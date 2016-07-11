#include "stdafx.h"

NODE* current; //текущая папка
NODE* rootes;

void goToFolder(char* s1) {                 //выполняет переход в папку с данным именем из текущей директории
	NODE* tmp = rootes;
	char* s2;
	while (tmp->NextNode != NULL) {				//ищем папку с именем, совпадающим с тем, которое подано в функцию
		s2 = tmp->NodeName;//!!! Спорный момент
		if (strcmp(s1, s2) != 0) {
			tmp = tmp->NextNode;					//если не нашли, то идем в следущего брата
		}
		else {
			current = (tmp->DownNode);			//если нашли, то меняем текущую директорию и возвращаемся в предыдущую функцию
			break;
		}
	}

}

char** str_split(char* a_str, const char a_delim)   //разбивает адресс на подстроки
{
	char** result = 0;			//указатель на разбитые строки
	size_t count = 0;			//кол-во подстрок
	char* tmp = a_str;			//исходный путь с разделителями
	char* last_comma = 0;		//последний разделитель
	char delim[2];				//разделитель
	delim[0] = a_delim;
	delim[1] = 0;

	
	while (*tmp)			//считаем кол-во подстрок
	{
		if (a_delim == *tmp)
		{
			count++;
			last_comma = tmp;
		}
		tmp++;
	}
	count += last_comma < (a_str + strlen(a_str) - 1);		//добавляем пробел, чтобы знать, где заканчиваются подстроки
	count++;

	result = (char**)malloc(sizeof(char*) * count);		//выделяем память для подстрок

	if (result)											//если память выделена начинаем резать строку
	{
		size_t idx = 0;
		char* token = strtok(a_str, delim);				//указатель на первую подстроку

		while (token)									//пока есть подстроки
		{
			assert(idx < count);						//проверяет, что не последняя подстрока
			*(result + idx++) = strdup(token);			// помещает следующую подстроку после первой
			token = strtok(0, delim);					// Magic don't touch
		}												// More magic
		assert(idx == count - 1);						// Even more magic
		*(result + idx) = 0;							// кладет 0 после всех подстрок
	}

	return result;										//возвращает указатель на начало массива адрессов подстрок
}

void goToPath(char* path) {								//по заданному пути переходит в нужную папку
	char** tokens;										//указатель на массив указателей с адрессами подстрок
	tokens = str_split(path, '/');						//генерирует этот массив с помощью функции разделения
	if (tokens)											//идем по подстрокам и вызываем функцию перехода в папку из текущей директории пока не кончатся подстроки
	{
		int i;
		for (i = 0; *(tokens + i); i++)
		{
			//printf("month=[%s]\n", *(tokens + i));
			goToFolder(*(tokens + i));					// вызов функции перехода в папку
			free(*(tokens + i));						//освобождаем память после перехода в папку
		}
		printf("\n");
		free(tokens);						
	}
}