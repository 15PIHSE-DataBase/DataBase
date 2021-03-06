﻿
#include "DataBase15.h"

VALUE * add_value(NODE *CurrentPtr, char *Qualf, TYPE Type, char * Info)
{
	if (CurrentPtr == NULL) return NULL;
	VALUE * Pointer = NULL;
	if ((Type < 1) || (Type>4) || (Pointer = find_value_in_node(CurrentPtr, Qualf)))
		return NULL;
	else
	{
		VALUE * NewValue = (VALUE*)malloc(sizeof(VALUE));
		if (!(Pointer = CurrentPtr->Values))
			NewValue->NextValue = NULL; //Первое добавление данных
		else NewValue->NextValue = Pointer;
		CurrentPtr->Values = NewValue;
		NewValue->Value = (char*)malloc(strlen(Info) + 1);
		strcpy(NewValue->Value, Info);
		NewValue->Qualifier = (char*)malloc(strlen(Qualf) + 1);
		strcpy(NewValue->Qualifier, Qualf);
		switch (Type) { //Определение типа
		case INT:  NewValue->type = INT;  break;
		case FLOAT:  NewValue->type = FLOAT;  break;
		case DOUBLE:  NewValue->type = DOUBLE;  break;
		case STRING:  NewValue->type = STRING;  break;
		}
		//int count = print_values(CurrentPtr, ALL); //Вывод всех данных узла с обновлениями, count - количество значений
		return NewValue;
	}
}