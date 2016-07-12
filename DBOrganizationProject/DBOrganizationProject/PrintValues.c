#include "stdafx.h"
//Вывод на экран всех значений узла с их спецификаторами и типов этих значений.
//Функция возвразает количество значений требуемого типа в указанном узле
//VALUE *head - указатель на первое прикреплённое к узлу значение
//TYPE Type - тип значений, которые нуобходимо вывести (ALL, INT, FLOAT, DOUBLE, CHAR)
int PrintValues(VALUE *head, TYPE Type) 
{
	if (head == NULL) { //В узле нет значений
		printf("Empty\n");
		return 0;
	}
	VALUE *temp = head;
	int Count = 0;
	while (temp != NULL){
		if ((temp->type == Type) || (Type == ALL)){
			printf("%s: %s ", temp->Qualifier, temp->Value);
			switch (temp->type){
			case INT:printf("(int)  "); break;
			case FLOAT:printf("(float)  "); break;
			case DOUBLE:printf("(double)  "); break;
			case CHAR:printf("(char)  "); break;
			}
			Count++;
		}
		temp = temp->NextValue;
	}
	if (Count) printf("\n");
	else printf("No required type values\n");
	return Count;
}