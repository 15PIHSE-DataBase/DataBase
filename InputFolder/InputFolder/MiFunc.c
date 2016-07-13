#include "stdafx.h"

void ChangeValue(VALUE* currPtr, TYPE Type, char* NewName, char* NewValue) //мен€ет значение, в т.ч. его тип: 1 указатель на значение, 2 тип, 3 новое им€, 4 новое значение
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


void DeleteAllValue(NODE *currPtr, TYPE Type) //удал€ет все значени€ из узла или значени€ конкретного типа
{

	VALUE* beginV = currPtr->Values;
	VALUE* temp2 = currPtr->Values;
	VALUE* temp = NULL;
	while (beginV != NULL)
	{
		if ((beginV->type == Type) || (Type == ALL))
		{
			temp = beginV->NextValue;
			if (temp != NULL)
			{
				beginV->Qualifier = temp->Qualifier;
				beginV->type = temp->type;
				beginV->Value = temp->Value;
				beginV->NextValue = temp->NextValue;
				free(temp);
			}
			else
			{
				if (currPtr->Values == beginV)
					currPtr->Values = NULL;
				temp = beginV;
				temp2->NextValue = NULL;
				beginV = NULL;
				free(temp);
				break;
			}

		}
		else
		{
			temp2 = beginV;
			beginV = beginV->NextValue;
		}
	}
}


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
				if (strcmp(Pointer->Qualifier, Qualf) == 0) return NULL; //ѕовтор спецификатора
				Pointer = Pointer->NextValue;
			}
			if (strcmp(Pointer->Qualifier, Qualf) == 0) return NULL; //ѕовтор спецификатора
			Pointer->NextValue = NewValue;
		}
		else CurrentPtr->Values = NewValue; //ѕервое добавление данных
		NewValue->NextValue = NULL;
		NewValue->Value = Info;
		NewValue->Qualifier = Qualf;
		switch (Type){ //ќпределение типа
		case INT:  NewValue->type = INT;  break;
		case FLOAT:  NewValue->type = FLOAT;  break;
		case DOUBLE:  NewValue->type = DOUBLE;  break;
		case CHAR:  NewValue->type = CHAR;  break;
		}
		//int count = PrintValues(CurrentPtr->Values, ALL); //¬ывод всех данных узла с обновлени€ми, count - количество значений
		return CurrentPtr;
	}
}

int PrintValues(NODE *head, TYPE Type) 
{
	if (head->Values == NULL) { 
		printf("Empty\n");
		return 0;
	}
	VALUE *temp = head->Values;
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

int deleteVal(VALUE* toDelete, NODE* start) {

	if (toDelete->NextValue == NULL) {
		
		if (start->Values->NextValue == NULL) {
			free(toDelete);
			start->Values = NULL;
			return 0;
		} else {
			VALUE* cur = start->Values;
			while (cur->NextValue != toDelete) {
				cur = cur->NextValue;
			}
			free(toDelete);
			cur->NextValue = NULL;
			return 1;
		}
		
	}
	else {
		VALUE *tmp = toDelete->NextValue;
		toDelete->Value = tmp->Value;
		toDelete->NextValue = tmp->NextValue;
		toDelete->Qualifier = tmp->Qualifier;
		free(tmp);
		return 1;
	}
}