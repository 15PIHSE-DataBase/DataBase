//������� ������������� ���������� ������� ����������

#include "stdafx.h"
void directory(NODE *CurrentF)
{
	NODE *temp;
	//�������� �� ������� ����������� � ������ ����������
	if (CurrentF->DownNode!=NULL) temp = CurrentF->DownNode;
	else {
		printf("\nDirectory is empty.\n");
		return;
	}
	//���������� ���� �����
	printf("\nDirectory contains:\n");
	while (1)
	{
		printf("%s\n",temp->NodeName);
		if ((temp->NextNode) == NULL) break;
		else temp = temp->NextNode;
	}
}