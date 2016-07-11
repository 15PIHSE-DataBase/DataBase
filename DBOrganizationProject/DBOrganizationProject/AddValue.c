#include"stdafx.h"
//���������� �������� � ����.
//���� ���������� ������ ������, ������� ����� ��������� �� �������� ����, ����� - NULL
//NODE *CurrentPtr - ��������� �� ����, � ������� ���������� ��������
//TYPE Type - ��� ����������� �������� (INT,FLOAT,DOUBLE,CHAR)
//char * Info - ���������� �������� � ���� ������
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
		else CurrentPtr->Values = NewValue; //������ ���������� ������
		NewValue->NextValue = NULL;
		NewValue->Value = Info;
		NewValue->key = gen_newkey();
		switch (Type){ //����������� ����
		case INT:  NewValue->type = INT;  break;
		case FLOAT:  NewValue->type = FLOAT;  break;
		case DOUBLE:  NewValue->type = DOUBLE;  break;
		case CHAR:  NewValue->type = CHAR;  break;
		}
		//PrintValues(CurrentPtr->Values); //����� ���������� �������� ����
		return CurrentPtr;
	}
}
void PrintValues(VALUE *head) //����� �� ����� ���� �������� ���� � �� �����
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