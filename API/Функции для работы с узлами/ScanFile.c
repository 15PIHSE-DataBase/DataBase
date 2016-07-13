#include "stdafx.h"
#include "generation.h"
// Требуется только для выгрузки дерева из файла. Конкретнее для выгрузки значений для узла
VALUE* fread_value(int, FILE*);
// Функция поиска узла по значению ключа
NODE* findkey(int, NODE*);

NODE* scanfile(FILE* dat)
{
	if (dat == NULL){
		printf("\n!Error reading file\nCreated new data base...\n");
		return NULL;
	}
	
	if (!feof(dat)) {
		printf("\n!File is empty!\nCreated new data base...\n");
		return NULL;
	}
	int length = 0;
	int *unlegal_key = NULL;
	int num_key = 0;
	NODE * rootes = (NODE*)malloc(sizeof(NODE));
	rootes->UpNode = NULL;
	rootes->NextNode = NULL;
	rootes->PreviousNode = NULL;
	rootes->DownNode = NULL;
	rootes->Values = NULL;

	rootes->DownNode = (NODE*)malloc(sizeof(NODE));
	rootes->DownNode->UpNode = rootes;
	rootes->DownNode->NextNode = NULL;
	rootes->DownNode->PreviousNode = NULL;
	rootes->DownNode->DownNode = NULL;
	rootes->DownNode->Values = NULL;

	fread(&length, sizeof(int), 1, dat); // Длина Имени Узла
	fread(rootes->NodeName, sizeof(char), length, dat); // Имя Узла
	fread(&rootes->key, sizeof(int), 1, dat); // Ключ Узла
	num_key++;
	unlegal_key = (int*)realloc(unlegal_key, num_key*4);
	*(unlegal_key + num_key - 1) = rootes->key;
	fread(&length, sizeof(int), 1, dat); // Кол-во значений
	rootes->Values = fread_value(length, dat); // Сами значения

	
	fread(&length, sizeof(int), 1, dat); // Длина Имени Узла
	if (length == 0) {
		create_freek(unlegal_key, num_key);
		free(unlegal_key);
		return rootes;
	}
	fread(rootes->DownNode->NodeName, sizeof(char), length, dat); // Имя Узла
	fread(&rootes->DownNode->key, sizeof(int), 1, dat); // Ключ Узла
	num_key++;
	unlegal_key = (int*)realloc(unlegal_key, num_key * 4);
	*(unlegal_key + num_key - 1) = rootes->DownNode->key;
	fread(&length, sizeof(int), 1, dat); // Кол-во значений
	rootes->DownNode->Values = fread_value(length, dat); // Сами значения


	int keyer;
	NODE* Child;
	NODE * buf = rootes;
	NODE* children;
	NODE* bufer;
	int check = 0;
	int numeration = 0;
	//!!!BEGIN!!!
	while (!feof(dat)) {
		numeration++;
		Child = (NODE*)malloc(sizeof(NODE));

		keyer = 0;
		fread(&keyer, 4, 1, dat);
		if (keyer == 0) {
			create_freek(unlegal_key, num_key);
			free(unlegal_key);
			return rootes;
		}

		fread(&length, sizeof(int), 1, dat); // Длина Имени Узла
		fread(Child->NodeName, sizeof(char), length, dat); // Имя Узла
		fread(&Child->key, sizeof(int), 1, dat); // Ключ Узла
		num_key++;
		unlegal_key = (int*)realloc(unlegal_key, num_key * 4);
		*(unlegal_key + num_key - 1) = Child->key;
		fread(&length, sizeof(int), 1, dat); // Кол-во значений
		if(length != 0)
			Child->Values = fread_value(length, dat); // Сами значения

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

		//Поиск по всему дереву(findkey)
		if (check == 1) {
			check = 0;
			bufer = findkey(keyer, rootes);
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


VALUE* fread_value(int n, FILE* dat)
{
	VALUE * buf = NULL;
	VALUE * save = NULL;
	int length = 0;
	buf = (VALUE*)malloc(sizeof(VALUE));
	save = buf;
	for (int i = 0; i < n; ++i)
	{
		buf->NextValue = NULL;
		fread(&length, sizeof(int), 1, dat);//ДлинаСпецификатора
		buf->Specifier = (char*)malloc(length*sizeof(char));
		fread(buf->Specifier, sizeof(char), length, dat);//Спецификатор
		fread(&buf->type, sizeof(int), 1, dat);//ТипЗначения
		fread(&length, sizeof(int), 1, dat);//ДлинаЗначения
		buf->Value = (char*)malloc(length*sizeof(char));
		fread(buf->Value, sizeof(char), length, dat);//Значение
		buf->NextValue = (VALUE*)malloc(sizeof(VALUE));
		buf = buf->NextValue;
	}
	free(buf);
	buf = NULL;
	return save;
}

NODE* findkey(int findkeyy, NODE* beginf)//Поиск файлов с помощью рекурсии
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
			buf = findkey(findkeyy, beginf);
			if (buf != NULL)//Требуется, для возварата значения при отказе дальнейшего поиска
				return(buf);
			beginf = beginf->NextNode;
		}

	return(NULL);
}

