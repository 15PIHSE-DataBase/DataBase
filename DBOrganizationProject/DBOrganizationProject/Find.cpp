#include "find.h"


void way(struct folder* beginf)
{
	char* ways;
	char* buf;
	int len = 0;
	len = strlen(beginf->FolderName) + 1;//������� ������ ��� ����� �������
	ways = (char*)malloc(len);
	buf = (char*)malloc(len);
	memset(ways, 0, len);//�������� ������ char ��� ������
	memset(buf, 0, len);
	strcat(ways, "\\");
	strcat(ways, beginf->FolderName);
	strcpy(buf, ways);
	beginf = beginf->UpFolder;

	while (beginf != NULL)//����� ���� ����� � ���������� ����� ����� � ������, ���� �� �������� root
	{
		len = len + strlen(beginf->FolderName) + 1;
		ways = (char*)malloc(len);
		memset(ways, 0, len);
		strcat(ways, "\\");
		strcat(ways, beginf->FolderName);
		strcat(ways, buf);
		buf = (char*)malloc(len);
		memset(buf, 0, len);
		strcpy(buf, ways);
		beginf = beginf->UpFolder;
	}
	printf("  MyComputer:\\%s\n", ways);
}

struct folder* findfolder(char* findname, struct folder* beginf)//����� ������ � ������� ��������
{
	struct folder* buf = NULL;
	char YN[2];
	strcat(YN, "Y");
	if (strcmp(beginf->FolderName, findname) == 0)//��� ���������
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
	beginf = beginf->DownFolder;
	if (beginf != NULL)
		while (beginf != NULL)//���������� �� ������� �����(NextFolder)
		{
			buf = findfolder(findname, beginf);
			if (buf != NULL)//���������, ��� ��������� �������� ��� ������ ����������� ������
				return(buf);
			beginf = beginf->NextFolder;
		}

	return(NULL);
}