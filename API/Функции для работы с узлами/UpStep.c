//������� ������������ ������� �� ������� ����� � ����� �� ������� ���� - ������

#include "stdafx.h"
NODE* up_step(NODE*CurrentF) 
{
	if (CurrentF->UpNode == NULL) return CurrentF; //������ 
	return CurrentF->UpNode;
}
