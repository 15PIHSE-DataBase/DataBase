﻿
#include "key.h"
#include "15PIDataBaseAPI.h"

NODE* InputTree(NODE *currPtr, char *newname)
{
	NODE *newPtr = NULL;
	newPtr = (NODE*)malloc(sizeof(NODE));//заводим новую структуру(папку)
	if (newPtr == NULL) return(NULL);
	//здесь начинаем заносить данные(имя, указатель на предка, указатели на братьев, всё остальное NULL)
	newPtr->PreviousNode = NULL;
	newPtr->DownNode = NULL;
	newPtr->Values = NULL;
	newPtr->key = gen_newkey();
	if (currPtr != NULL)//начальная вершина?
	{
		if (goToNode(newname, currPtr->DownNode) != NULL) return(NULL); //проверяем существование узла с таким именем
		strcpy(newPtr->NodeName, newname);
		newPtr->UpNode = currPtr;
		NODE *childPtr = NULL;
		childPtr = (currPtr)->DownNode;
		if (childPtr != NULL)
		{
			newPtr->NextNode = childPtr;//прицепляем новый узел к соседу
			(childPtr)->PreviousNode = newPtr;//и соседа к этому узлу
		}
		else
		{
			newPtr->NextNode = NULL;
		}
		(currPtr)->DownNode = newPtr;//прицепляем новый узел к предку
	}
	else
	{
		strcpy(newPtr->NodeName, newname);
		newPtr->NextNode = NULL;
		newPtr->UpNode = currPtr;
	}
	return(newPtr);
}//здесь заканчиваем заполнение новой структуры