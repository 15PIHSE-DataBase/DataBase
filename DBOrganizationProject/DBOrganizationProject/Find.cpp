#include "stdafx.h"


void way(NODE* beginf)
{
	char* ways;
	char* buf;
	int len = 0;
	len = strlen(beginf->NodeName) + 1;//������� ������ ��� ����� �������
	ways = (char*)malloc(len);
	buf = (char*)malloc(len);
	memset(ways, 0, len);//�������� ������ char ��� ������
	memset(buf, 0, len);
	strcat(ways, "\\");
	strcat(ways, beginf->NodeName);
	strcpy(buf, ways);
	beginf = beginf->UpNode;

	while (beginf != NULL)//����� ���� ����� � ���������� ����� ����� � ������, ���� �� �������� root
	{
		len = len + strlen(beginf->NodeName) + 1;
		ways = (char*)malloc(len);
		memset(ways, 0, len);
		strcat(ways, "\\");
		strcat(ways, beginf->NodeName);
		strcat(ways, buf);
		buf = (char*)malloc(len);
		memset(buf, 0, len);
		strcpy(buf, ways);
		beginf = beginf->UpNode;
	}
	printf("  MyComputer:\\%s\n", ways);
}

NODE* findnode(char* findname, NODE* beginf)//����� ������ � ������� ��������
{
	NODE* buf = NULL;
	//char YN[2];
	//strcat(YN, "Y");
	if (strcmp(beginf->NodeName, findname) == 0)//��� ���������
	{
		//way(beginf);
		//printf("    Continue searching? Y/N: ");
		//scanf("%s", YN);
		//if (strcmp(YN, "N") == 0)
		//{
		//	memset(YN, 0, 2);
		//	return(beginf);
		//}
		return(beginf);
	}
	beginf = beginf->DownNode;
	if (beginf != NULL)
		while (beginf != NULL)//���������� �� ������� �����(NextNode)
		{
			buf = findnode(findname, beginf);
			if (buf != NULL)//���������, ��� ��������� �������� ��� ������ ����������� ������
				return(buf);
			beginf = beginf->NextNode;
		}

	return(NULL);
}