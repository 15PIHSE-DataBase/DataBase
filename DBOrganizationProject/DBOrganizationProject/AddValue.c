#include"stdafx.h"
//���������� �������� � ����.
//���� ���������� ������ ������, ������� ����� �������� ��������� ����, ����� - NULL
//NODE **CurrentPtr - ����� ����, � ������� ���������� ��������
//int Type - ��� ����������� ��������
//char * Info - ���������� �������� � ���� ������
NODE* AddValue(NODE **CurrentPtr, int Type, char * Info)
{
	if ((Type < 0) || (Type>3))
		return NULL;
	else
	{
		VALUE * Pointer = NULL;
		VALUE * NewValue = (VALUE*)malloc(sizeof(VALUE));
		if (Pointer = (*CurrentPtr)->Values){
			while (Pointer->NextValue != NULL)
				Pointer = Pointer->NextValue;
			Pointer->NextValue = NewValue;
		}
		else (*CurrentPtr)->Values = NewValue; //������ ���������� ������
		NewValue->NextValue = NULL;
		NewValue->Value = Info;
		switch (Type){ //����������� ����
		case 0:  NewValue->type = INT;  break;
		case 1:  NewValue->type = FLOAT;  break;
		case 2:  NewValue->type = DOUBLE;  break;
		case 3:  NewValue->type = CHAR;  break;
		}
		//PrintKeys((*CurrentPtr)->Values); //����� ���� ������ ���� � ������������
		return *CurrentPtr;
	}
}
void PrintKeys(VALUE *head) //����� �� ����� ���� �������� ���� � �� �����
{
	while (head != NULL){
		printf("%s ", head->Value);
		switch (head->type){
		case 0:printf("(int)  "); break;
		case 1:printf("(float)  "); break;
		case 2:printf("(double)  "); break;
		case 3:printf("(char)  "); break;
		}
		head = head->NextValue;
	}
	printf("\n");
}