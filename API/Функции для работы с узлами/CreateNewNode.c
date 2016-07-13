#include "stdafx.h"

NODE* InputTree(NODE **currPtr, char *newname)
{
	NODE *childPtr = NULL;
	childPtr = (*currPtr)->DownNode;
	NODE *temp = NULL;
	if ((*currPtr)->DownNode != NULL) temp = childPtr;
	NODE *newPtr = NULL;
	newPtr = (NODE*)malloc(sizeof(NODE));//заводим новую структуру(папку)
	if (newPtr == NULL){
		printf("No memory available \n");
		return(NULL);
	}
	strcpy(newPtr->NodeName,newname); //здесь начинаем заносить данные(имя, указатель на предка, указатели на братьев, всё остальное NULL)
	newPtr->UpNode = *currPtr;
	newPtr->DownNode = NULL;
	newPtr->Values = NULL;
	newPtr->key = gen_newkey();
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
	return(newPtr);
}//здесь заканчиваем заполнение новой структуры