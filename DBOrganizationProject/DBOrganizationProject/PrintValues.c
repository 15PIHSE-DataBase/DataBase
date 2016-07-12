#include "stdafx.h"
//����� �� ����� ���� �������� ���� � �� ��������������� � ����� ���� ��������.
//������� ���������� ���������� �������� ���������� ���� � ��������� ����
//VALUE * head - ��������� �� ����
//TYPE Type - ��� ��������, ������� ���������� ������� (ALL, INT, FLOAT, DOUBLE, CHAR)
int PrintValues(NODE *head, TYPE Type) //����� �� ����� ���� �������� ���� � �� �����
{
	if (head->Values == NULL) {
		printf("Empty\n");
		return 0;
	}
	VALUE *temp = head->Values;
	int Count = 0;
	while (temp != NULL){		
		if ((temp->type == Type)||(Type==ALL)){
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