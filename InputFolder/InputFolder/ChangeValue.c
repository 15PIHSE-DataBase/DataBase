#include "stdafx.h"

void ChangeValue(VALUE* currPtr, TYPE Type, char* NewName, char* NewValue) //меняет значение, в т.ч. его тип: 1 указатель на значение, 2 тип, 3 новое имя, 4 новое значение
{

	if (Type != ALL)
	{
		if (currPtr->type != Type)
		{
			switch (Type)
			{
			case INT:  currPtr->type = INT;  break;
			case FLOAT:  currPtr->type = FLOAT;  break;
			case DOUBLE:  currPtr->type = DOUBLE;  break;
			case CHAR:  currPtr->type = CHAR;  break;
			}
		}
	}
	if (NewName != NULL)
		strcpy(currPtr->Qualifier, NewName);
	if (NewValue != NULL)
		strcpy(currPtr->Value, NewValue);
}