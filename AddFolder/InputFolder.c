#include "stdafx.h"

FOLDER* InputTree(FOLDER **currPtr, char *newname)
{
	FOLDER *childPtr = NULL;
	childPtr = (*currPtr)->DownFolder;
	FOLDER *temp = NULL;
	if ((*currPtr)->DownFolder != NULL) temp = childPtr;
	FOLDER *newPtr = NULL;
	newPtr = (FOLDER*)malloc(sizeof(FOLDER));//заводим новую структуру(папку)
	printf("%d", newPtr);
	if (newPtr == NULL){
		printf("No memory available \n");
		return(NULL);
	}
	newPtr->FolderName = newname; //здесь начинаем заносить данные(имя, указатель на предка, указатели на братьев, всё остальное NULL)
	newPtr->UpFolder = *currPtr;
	newPtr->DownFolder = NULL;
	newPtr->Values = NULL;
	if (childPtr != NULL)
	{
		newPtr->NextFolder = childPtr;//прицепляем новый узел к соседу
		(childPtr)->PreviousFolder = newPtr;//и соседа к этому узлу
	}
	else
	{
		newPtr->NextFolder = NULL;
	}
	newPtr->PreviousFolder = NULL;
	(*currPtr)->DownFolder = newPtr;//прицепляем новый узел к предку
	return(newPtr);
}//здесь заканчиваем заполнение новой структуры

