#include "DataBase15.h"
#include "key.h"

// Требуется только для выгрузки дерева из файла. Конкретнее для выгрузки значений для узла
VALUE* fread_value(fpos_t, FILE*);
// Функция поиска узла по значению ключа
NODE* find_key(int, NODE*);
//возвращает размер файла
long int file_size(FILE *);
//функция только для чтения значений для root
VALUE* value_root(fpos_t , FILE* );

NODE* scan_file(FILE* FileWithNodes, FILE* FileWithValue)
{
	if (FileWithNodes == NULL) {
		printf("\n!Error reading file\nCreated new data base...\n");
		return NULL;
	}

	if (file_size(FileWithNodes) == 0) {
		printf("\n!File is empty!\nCreated new data base...\n");
		return NULL;
	}
	bool flagDel = 0;
	fpos_t posVal, posTree;
	int length = 0;
	int *unlegal_key = NULL;
	int num_key = 0;
	NODE * rootes = (NODE*)malloc(sizeof(NODE));
	rootes->UpNode = NULL;
	rootes->NextNode = NULL;
	rootes->PreviousNode = NULL;
	rootes->DownNode = NULL;
	rootes->Values = NULL;

	//(Ключ int)
	//(Флаг Удаления 1 байт)(Ключ Int)(Имя char* 255)(Смещенние на данные во втором файле 8 байт)(Смещение на подузлы в первом файле 8 байт)
	flagDel = 0;
	fread(&flagDel, sizeof(bool), 1, FileWithNodes);// Флаг удаления
	if (flagDel == 1) {
		printf("\n!All the tree removed!\n");
		return NULL;
	}
	fread(&rootes->key, sizeof(int), 1, FileWithNodes); // Ключ Узла
	num_key++;
	unlegal_key = (int*)realloc(unlegal_key, num_key * 4);
	*(unlegal_key + num_key - 1) = rootes->key;
	length = 0;
	fread(rootes->NodeName, sizeof(char), 255, FileWithNodes); // Имя Узла
	posVal = 0;
	fread(&posVal, sizeof(fpos_t), 1, FileWithNodes); // Cмещения на значения
	rootes->Values = value_root(posVal, FileWithValue); // Сами значения
	posTree = 0;
	fread(&posTree, sizeof(fpos_t), 1, FileWithNodes); // Cмещения на подузлы

	flagDel = 0;
	fread(&flagDel, sizeof(bool), 1, FileWithNodes);// Флаг удаления
	if (flagDel == 1)
	{
		fseek(FileWithNodes, (sizeof(int) + 255 * sizeof(char) + sizeof(fpos_t)), ftell(FileWithNodes));
		posTree = 0;
		fread(&posTree, sizeof(fpos_t), 1, FileWithNodes);
	}
	else {
		rootes->DownNode = (NODE*)malloc(sizeof(NODE));
		fread(&rootes->DownNode->key, sizeof(int), 1, FileWithNodes); // Ключ Узла
		num_key++;
		unlegal_key = (int*)realloc(unlegal_key, num_key * 4);
		*(unlegal_key + num_key - 1) = rootes->DownNode->key;
		fread(rootes->DownNode->NodeName, sizeof(char), 255, FileWithNodes); // Имя Узла
		posVal = 0;
		fread(&posVal, sizeof(fpos_t), 1, FileWithNodes); // Cмещения на значения
		rootes->DownNode->Values = fread_value(posVal, FileWithValue); // Сами значения
		//printf("%s\n", rootes->DownNode->Values->Value);
		posTree = 0;
		fread(&posTree, sizeof(fpos_t), 1, FileWithNodes); // Cмещения на подузлы
		rootes->DownNode->UpNode = rootes;
		rootes->DownNode->NextNode = NULL;
		rootes->DownNode->PreviousNode = NULL;
		rootes->DownNode->DownNode = NULL;
	}
	int keyer;
	NODE* Child;
	NODE * buf = rootes;
	NODE* children;
	NODE* bufer;
	int check = 0;
	int numeration = 0;
	//!!!BEGIN!!!
	while (!feof(FileWithNodes)) {
		numeration++;
		Child = (NODE*)malloc(sizeof(NODE));

		keyer = 0;
		fread(&keyer, 4, 1, FileWithNodes);
		if (keyer == 0) {
			create_freek(unlegal_key, num_key);
			free(unlegal_key);
			return rootes;
		}

		flagDel = 0;
		fread(&flagDel, sizeof(bool), 1, FileWithNodes);// Флаг удаления
		if (flagDel == 1)
		{
			fseek(FileWithNodes, (sizeof(int) + 255 * sizeof(char) + sizeof(fpos_t)), ftell(FileWithNodes));
			posTree = 0;
			fread(&posTree, sizeof(fpos_t), 1, FileWithNodes);
		}
		else {
			fread(&Child->key, sizeof(int), 1, FileWithNodes); // Ключ Узла
			num_key++;
			unlegal_key = (int*)realloc(unlegal_key, num_key * 4);
			*(unlegal_key + num_key - 1) = Child->key;
			fread(Child->NodeName, sizeof(char), 255, FileWithNodes); // Имя Узла
			posVal = 0;
			fread(&posVal, sizeof(fpos_t), 1, FileWithNodes); // Cмещения на значения
			Child->Values = fread_value(posVal, FileWithValue); // Сами значения
			posTree = 0;
			fread(&posTree, sizeof(fpos_t), 1, FileWithNodes); // Cмещения на подузлы
		}

		children = buf->DownNode;

		//Ищем по отцу
		if (buf->key == keyer) {
			while (children != NULL) {
				check = 1;
				bufer = children;
				children = children->NextNode;
			}
			if (children == NULL) {
				children = (NODE*)malloc(sizeof(NODE));
				children = Child;
				children->UpNode = buf;
				children->NextNode = NULL;
				children->DownNode = NULL;
				if (check == 0) {
					buf->DownNode = children;
					children->PreviousNode = NULL;
				}
				else {
					bufer->NextNode = children;
					children->PreviousNode = bufer;
				}
				continue;
			}
		}

		check = 1;
		//ищем по детям
		while (1) {
			if (children == NULL) {
				break;
			}
			if (children->key == keyer) {
				children->DownNode = Child;
				children->DownNode->UpNode = children;
				children->DownNode->NextNode = NULL;
				children->DownNode->PreviousNode = NULL;
				children->DownNode->DownNode = NULL;

				buf = children;
				check = 0;
			}
			children = children->NextNode;
		}

		//Поиск по всему дереву(find_key)
		if (check == 1) {
			check = 0;
			bufer = find_key(keyer, rootes);
			buf = bufer;
			children = buf->DownNode;
			children = Child;
			children->UpNode = buf;
			children->NextNode = NULL;
			children->PreviousNode = NULL;
			children->DownNode = NULL;
			buf->DownNode = children;
		}
	}
	create_freek(unlegal_key, num_key);
	free(unlegal_key);
	return rootes;
}

//(Кол-во значений int == k)(Флаг удаление 1 байт)(Длина спецификатора int == n)(Спецификатор char* [n])(Длина значения int)(Значений char* [n])(Тип Int)*k(Смещение на новые зн. 8 байт)

VALUE* fread_value(fpos_t posFile, FILE* FileWithValue)
{
	if (posFile == 0)
		return NULL;
	fpos_t buf_pos = posFile;
	unsigned n = 0;
	int checkVal = 0;// Проверка на наличие значений
	unsigned length = 0;
	bool flagDel = 0;// Флаг удаления значения
	VALUE* buf;
	VALUE* save;
	buf = (VALUE*)malloc(sizeof(VALUE));
	buf->NextValue = NULL;
	save = buf;

	while (buf_pos != 0) {
		fseek(FileWithValue, buf_pos, SEEK_SET);
		n = 0;
		fread(&n, sizeof(unsigned), 1, FileWithValue); // Кол-во значений
		for (int i = 0; i < n; ++i) {
			buf->NextValue = (VALUE*)malloc(sizeof(VALUE));
			buf = buf->NextValue;
			buf->NextValue = NULL;
			//flagDel = 0;
			//fread(&flagDel, sizeof(bool), 1, FileWithValue);
			/*if (flagDel == 1) {
				length = 0;
				fread(&length, sizeof(int), 1, FileWithValue);
				fseek(val, length*sizeof(char), ftell(FileWithValue));
				length = 0;
				fread(&length, sizeof(int), 1, FileWithValue);
				fseek(val, length*sizeof(char), ftell(FileWithValue));
				fseek(val, sizeof(int), ftell(FileWithValue));
				continue;
			}*/
			checkVal = 1;
			length = 0;
			fread(&length, sizeof(unsigned), 1, FileWithValue); // Длина Спецификатора
			buf->Qualifier = (char*)malloc(length*sizeof(char));
			fread(buf->Qualifier, sizeof(char), length, FileWithValue); // Спецификатор
			fread(&length, sizeof(unsigned), 1, FileWithValue); // Длина значения
			buf->Value = (char*)malloc(length*sizeof(char));
			fread(buf->Value, sizeof(char), length, FileWithValue); // Значение
			fread(&buf->type, sizeof(TYPE), 1, FileWithValue); // Тип
		}
		fread(&buf_pos, sizeof(fpos_t), 1, FileWithValue); // Смещение на новые значения(для перезаписи)
	}
	if (checkVal == 0)
		return 0;
	return save->NextValue;
}


VALUE* value_root(fpos_t posFile, FILE* FileWithValue)
{
	fpos_t buf_pos = posFile;
	int n = 0;
	int checkVal = 0;// Проверка на наличие значений
	int length = 0;
	bool flagDel = 0;// Флаг удаления значения
	VALUE* buf;
	VALUE* save;
	buf = (VALUE*)malloc(sizeof(VALUE));
	buf->NextValue = NULL;
	save = buf;

	while (1) {
		fseek(FileWithValue, buf_pos, SEEK_SET);
		n = 0;
		fread(&n, sizeof(int), 1, FileWithValue); // Кол-во значений
		for (int i = 0; i < n; ++i) {
			buf->NextValue = (VALUE*)malloc(sizeof(VALUE));
			buf = buf->NextValue;
			buf->NextValue = NULL;
			//flagDel = 0;
			//fread(&flagDel, sizeof(bool), 1, FileWithValue);
			/*if (flagDel == 1) {
			length = 0;
			fread(&length, sizeof(int), 1, FileWithValue);
			fseek(val, length*sizeof(char), ftell(FileWithValue));
			length = 0;
			fread(&length, sizeof(int), 1, FileWithValue);
			fseek(val, length*sizeof(char), ftell(val));
			fseek(val, sizeof(int), ftell(FileWithValue));
			continue;
			}*/
			checkVal = 1;
			length = 0;
			fread(&length, sizeof(int), 1, FileWithValue); // Длина Спецификатора
			buf->Qualifier = (char*)malloc(length*sizeof(char));
			fread(buf->Qualifier, sizeof(char), length, FileWithValue); // Спецификатор
			fread(&length, sizeof(int), 1, FileWithValue); // Длина значения
			buf->Value = (char*)malloc(length*sizeof(char));
			fread(buf->Value, sizeof(char), length, FileWithValue); // Значение
			fread(&buf->type, sizeof(int), 1, FileWithValue); // Тип
		}
		fread(&buf_pos, sizeof(fpos_t), 1, FileWithValue); // Смещение на новые значения(для перезаписи)
		if (buf_pos == NULL)
			break;
	}
	if (checkVal == 0)
		return 0;
	return save->NextValue;
}


NODE* find_key(int findkeyy, NODE* beginf)//Поиск файлов с помощью рекурсии
{
	NODE* buf = NULL;
	if (beginf->key == findkeyy)//Идёт сравнение
	{
		return(beginf);
	}
	beginf = beginf->DownNode;
	if (beginf != NULL)
		while (beginf != NULL)//Проходимся по каждому брату(NextNode)
		{
			buf = find_key(findkeyy, beginf);
			if (buf != NULL)//Требуется, для возварата значения при отказе дальнейшего поиска
				return(buf);
			beginf = beginf->NextNode;
		}

	return(NULL);
}


long int file_size(FILE *fp)
{
	long int save_pos, size_of_file;

	save_pos = ftell(fp);
	fseek(fp, 0L, SEEK_END);
	size_of_file = ftell(fp);
	fseek(fp, save_pos, SEEK_SET);
	return(size_of_file);
}