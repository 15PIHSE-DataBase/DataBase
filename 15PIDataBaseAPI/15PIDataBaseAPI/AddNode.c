
#include "key.h"
#include "DataBase15.h"

NODE* input_tree(NODE *currPtr, char *newname)
{
	if (go_to_node(newname, currPtr) != NULL) return(NULL); //проверяем существование узла с таким именем
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