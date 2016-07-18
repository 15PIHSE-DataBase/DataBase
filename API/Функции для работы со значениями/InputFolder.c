#include "stdafx.h"

void input_tree(NODE **currPtr)
{
	instruction();
	char buf[257], p = '/';
	bool flag = 0;
	int c;
	char *newname;
	NODE *childPtr = NULL;
	childPtr = (*currPtr)->DownNode;
	NODE *temp = NULL;
	if ((*currPtr)->DownNode != NULL) temp = childPtr;
	do
	{
		flag = 0;
		puts("Please enter a filename for the new folder:"); 
		fgets(buf, 257, stdin);
		c = strlen(buf);
		while (temp!=NULL)//проверка на существование в списке из братьев папки с таким именем
		{
			if (strcmp(buf, temp->NodeName) == 0)
			{ 
				puts("Error! Folder with this name already exists");
				flag = 1;
				break;
			}
		    temp = temp->NextNode;
		}
		if (c == 256) //размер имени превысил 255 символов
		{
			puts("Error! File Names Seem to Be Limited to Less Than 255 Characters");
			flag = 1;
		}
		if (strchr(buf, p) != 0) //имя содержит недопустимый символ '/'
		{
			puts("Error! The folder name specified contains character that is not permitted: '/'");
			flag = 1;
		}
		if (c == 1) //имя пустое
		{
			puts("Error! The folder name cannot be empty");
			flag = 1;
		}
	} while (flag != 0); //запрашиваем имя, пока оно не будет удовлетворять всем условиям
	NODE *newPtr = NULL;
	newPtr = (NODE*)malloc(sizeof(NODE));//заводим новую структуру(папку)
	if (newPtr == NULL){
		printf("No memory available \n");
		return;
	}
	newname = (char*)malloc(sizeof(char)*(c+1));//здесь начинаем заносить данные(имя, указатель на предка, указатели на братьев, всё остальное NULL)
	strcpy(newname, buf);
	strcpy(newPtr->NodeName, newname);//!!!!!!!!!!!!!!! Пришлось изменить самому(Слава) Если есть проблемы, то могут быть из-за этого
	newPtr->UpNode = *currPtr;
	newPtr->DownNode = NULL;
	newPtr->Values = NULL;
	if (childPtr != NULL)
	{
		newPtr->NextNode = childPtr;//прицепляем новый узел к соседу
		(childPtr)->PreviousNode = newPtr;//и соседа к этому узлу
	}
	else
	{
		newPtr->NextNode = NULL;
	}
	newPtr->PreviousNode = NULL;
	(*currPtr)->DownNode = newPtr;//прицепляем новый узел к предку
}//здесь заканчиваем заполнение новой структуры

void instruction()
{
	puts("Warning!");
	puts("1. The folder name cannot be empty");
	puts("2. The folder name cannot be less than 1 character or more than 255 characters");
	puts("3. The folder name cannot coitain '/' character");
}
