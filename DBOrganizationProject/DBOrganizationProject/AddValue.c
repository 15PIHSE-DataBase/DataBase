#include"stdafx.h"
//Добавление значения в узел.
//Если добавление прошло удачно, функция вернёт указатель на исходный узел, иначе - NULL
//NODE *CurrentPtr - Указатель на узел, в который помещается значение
//TYPE Type - тип помещаемого значения (INT,FLOAT,DOUBLE,CHAR)
//char * Info - помещаемое значение в виде строки
NODE* AddValue(NODE *CurrentPtr, TYPE Type, char * Info)
{
	if ((Type < 0) || (Type>3)) 
		return NULL;
	else
	{
		VALUE * Pointer=NULL;
		VALUE * NewValue = (VALUE*)malloc(sizeof(VALUE));
		if (Pointer = CurrentPtr->Values){
			while (Pointer->NextValue != NULL)
				Pointer = Pointer->NextValue;
			Pointer->NextValue = NewValue;
		}
		else CurrentPtr->Values = NewValue; //Первое добавление данных
		NewValue->NextValue = NULL;
		NewValue->Value = Info;
		NewValue->key = gen_newkey();
		switch (Type){ //Определение типа
		case INT:  NewValue->type = INT;  break;
		case FLOAT:  NewValue->type = FLOAT;  break;
		case DOUBLE:  NewValue->type = DOUBLE;  break;
		case CHAR:  NewValue->type = CHAR;  break;
		}
		//PrintValues(CurrentPtr->Values); //Вывод обновлённых значений узла
		return CurrentPtr;
	}
}
void PrintValues(VALUE *head) //Вывод на экран всех значений узла и их типов
{
	while (head != NULL){
		printf("%s ", head->Value);
		switch (head->type){
		case INT:printf("(int)  "); break;
		case FLOAT:printf("(float)  "); break;
		case DOUBLE:printf("(double)  "); break;
		case CHAR:printf("(char)  "); break;
		}
		head = head->NextValue;
	}
	printf("\n");
}