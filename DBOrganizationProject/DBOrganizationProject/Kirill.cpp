#include "Kirill.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
FOLDER* current; //текуща€ папка
FOLDER* root; //корень базы 

void goToFolder(char* s1) {                 //выполн€ет переход в папку с данным именем из текущей директории
	FOLDER* tmp = root;
	char* s2;
	while (tmp->NextFolder != NULL) {				//ищем папку с именем, совпадающим с тем, которое подано в функцию
		s2 = tmp->FolderName;						
		if (strcmp(s1, s2) != 0) {
			tmp = tmp->NextFolder;					//если не нашли, то идем в следущего брата
		}
		else {
			current = (tmp->DownFolder);			//если нашли, то мен€ем текущую директорию и возвращаемс€ в предыдущую функцию
			break;
		}
	}

}

char** str_split(char* a_str, const char a_delim)   //разбивает адресс на подстроки
{
	char** result = 0;			//указатель на разбитые строки
	size_t count = 0;			//кол-во подстрок
	char* tmp = a_str;			//исходный путь с разделител€ми
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
	count += last_comma < (a_str + strlen(a_str) - 1);		//добавл€ем пробел, чтобы знать, где заканчиваютс€ подстроки
	count++;

	result = (char**)malloc(sizeof(char*) * count);		//выдел€ем пам€ть дл€ подстрок

	if (result)											//если пам€ть выделена начинаем резать строку
	{
		size_t idx = 0;
		char* token = strtok(a_str, delim);				//указатель на первую подстроку

		while (token)									//пока есть подстроки
		{
			assert(idx < count);						//провер€ет, что не последн€€ подстрока
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
	tokens = str_split(path, '/');						//генерирует этот массив с помощью функции разделени€
	if (tokens)											//идем по подстрокам и вызываем функцию перехода в папку из текущей директории пока не кончатс€ подстроки
	{
		int i;
		for (i = 0; *(tokens + i); i++)
		{
			//printf("month=[%s]\n", *(tokens + i));
			goToFolder(*(tokens + i));					// вызов функции перехода в папку
			free(*(tokens + i));						//освобождаем пам€ть после перехода в папку
		}
		printf("\n");
		free(tokens);						
	}
}