#include"stdafx.h"
//���������� �������� � ����.
//���� ���������� ������ ������, ������� ����� ��������� �� �������� ����, ����� - NULL
//NODE * CurrentPtr - ��������� �� ����, � ������� ���������� ��������
//char * Qualf - ��������� �� ������ - ������������ ��� ����� ������
//TYPE Type - ��� ����������� �������� (INT,FLOAT,DOUBLE,CHAR)
//char * Info - ��������� �� ���������� �������� � ���� ������
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
				if (strcmp(Pointer->Qualifier, Qualf) == 0) return NULL; //������ �������������
				Pointer = Pointer->NextValue;
			}
			if (strcmp(Pointer->Qualifier, Qualf) == 0) return NULL; //������ �������������
			Pointer->NextValue = NewValue;
		}
		else CurrentPtr->Values = NewValue; //������ ���������� ������
		NewValue->NextValue = NULL;
		NewValue->Value = Info;
		NewValue->Qualifier = Qualf;
		switch (Type){ //����������� ����
		case INT:  NewValue->type = INT;  break;
		case FLOAT:  NewValue->type = FLOAT;  break;
		case DOUBLE:  NewValue->type = DOUBLE;  break;
		case CHAR:  NewValue->type = CHAR;  break;
		}
		//int count = PrintValues(CurrentPtr->Values, ALL); //����� ���� ������ ���� � ������������, count - ���������� ��������
		return CurrentPtr;
	}
}