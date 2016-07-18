#include "stdafx.h"

int change_value(NODE *CurrentPtr, VALUE* currPtr, TYPE Type, char* NewName, char* NewValue) //меняет значение, в т.ч. его тип: 1 указатель на узел, 2 указатель на значение, 3 тип, 4 новое имя, 5 новое значение
//функция вернёт 0 в случае успеха, 1 в случае неправильного типа 2 при попытке переименовать спецификатор используя имя другого спецификатора
{
	if (NewValue != NULL)//если указатель NULL, то не меняем значение
		strcpy(currPtr->Value, NewValue);
	if (Type != ALL) //если тип ALL, то не меняем тип
	{
		if (currPtr->type != Type)
		{
			switch (Type)
			{
			case INT:  currPtr->type = INT;  break;
			case FLOAT:  currPtr->type = FLOAT;  break;
			case DOUBLE:  currPtr->type = DOUBLE;  break;
			case STRING:  currPtr->type = CHAR;  break;
			default: return(1); break;
			}
		}
	}
	if (NewName != NULL)//если указатель NULL, то не меняем спецификатор
	{
		if (find_value_in_node(CurrentPtr, NewName) == NULL)
			strcpy(currPtr->Qualifier, NewName);
		else
			return(2);
	}
	return(0);
}