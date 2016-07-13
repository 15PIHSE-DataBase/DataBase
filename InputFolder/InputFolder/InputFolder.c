#include "stdafx.h"

int keys = 0;		//???? ????? ?????????? ???? ? stdafx, ?? ???? ??????? ??!!!
int number = 0;		//?????????? ???-?? ?????????????? ??????
int* freek = NULL;	//?????? ?????????????? ??????

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

int gen_newkey()
{
	int save = 0;
	int * buf;
	if (number != 0)
	{
		save = *(freek + number - 1);
		--number;
		buf = (int*)malloc(number*sizeof(int));
		for (int i = 0; i < number; ++i)
			*(buf + i) = *(freek + i);
		free(freek);
		freek = (int*)malloc(number*sizeof(int));
		for (int i = 0; i < number; ++i)
			*(freek + i) = *(buf + i);
		free(buf);
		return save;
	}
	++keys;
	return keys;
}

void Directory(NODE *CurrentF)
{
	NODE *temp;
	if (CurrentF->DownNode != NULL) temp = CurrentF->DownNode;
	else {
		printf("\nDirectory is empty.\n");
		return;
	}
	printf("\nDirectory contains:\n");
	while (1)
	{
		printf("%s\n", temp->NodeName);
		if ((temp->NextNode) == NULL) break;
		else temp = temp->NextNode;
	}
}