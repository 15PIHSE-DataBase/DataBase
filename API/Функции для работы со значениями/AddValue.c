﻿#include"stdafx.h"
//Добавление значения в узел.
//Если добавление прошло удачно, функция вернёт указатель на новое значение, иначе - NULL
//NODE * CurrentPtr - указатель на узел, в который помещается значение
//char * Qualf - указатель на строку - спецификатор для новых данных
//TYPE Type - тип помещаемого значения (INT,FLOAT,DOUBLE,CHAR)
//char * Info - указатель на помещаемое значение в виде строки
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
		switch (Type){ //Определение типа
		case INT:  NewValue->type = INT;  break;
		case FLOAT:  NewValue->type = FLOAT;  break;
		case DOUBLE:  NewValue->type = DOUBLE;  break;
		case STRING:  NewValue->type = CHAR;  break;
		}
		//int count = PrintValues(CurrentPtr, ALL); //Вывод всех данных узла с обновлениями, count - количество значений
		return NewValue;
	}
}