#include"stdafx.h"
//Добавление значения в узел.
//Если добавление прошло удачно, функция вернёт указатель на исходный узел, иначе - NULL
//NODE * CurrentPtr - указатель на узел, в который помещается значение
//char * Qualf - указатель на строку - спецификатор для новых данных
//TYPE Type - тип помещаемого значения (INT,FLOAT,DOUBLE,CHAR)
//char * Info - указатель на помещаемое значение в виде строки
NODE* AddValue(NODE *CurrentPtr, char *Qualf, TYPE Type, char * Info)
{
	if ((Type < 1) || (Type>4)) 
		return NULL;
	else
	{
		VALUE * Pointer = NULL;
		VALUE * NewValue = (VALUE*)malloc(sizeof(VALUE));
		if (Pointer = CurrentPtr->Values){
			while (Pointer->NextValue != NULL){
				if (strcmp(Pointer->Qualifier, Qualf) == 0) return NULL; //Повтор спецификатора
				Pointer = Pointer->NextValue;
			}
			if (strcmp(Pointer->Qualifier, Qualf) == 0) return NULL; //Повтор спецификатора
			Pointer->NextValue = NewValue;
		}
		else CurrentPtr->Values = NewValue; //Первое добавление данных
		NewValue->NextValue = NULL;
		NewValue->Value = Info;
		NewValue->Qualifier = Qualf;
		switch (Type){ //Определение типа
		case INT:  NewValue->type = INT;  break;
		case FLOAT:  NewValue->type = FLOAT;  break;
		case DOUBLE:  NewValue->type = DOUBLE;  break;
		case CHAR:  NewValue->type = CHAR;  break;
		}
		//int count = PrintValues(CurrentPtr->Values, ALL); //Вывод всех данных узла с обновлениями, count - количество значений
		return CurrentPtr;
	}
}