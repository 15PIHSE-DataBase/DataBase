#include "stdafx.h"

char* GetName(FOLDER **currPtr){
	bool flag = 0;
	char buf[256], p = '/';
	char *newname;
	int c;

	FOLDER *childPtr = NULL;
	childPtr = (*currPtr)->DownFolder;
	FOLDER *temp = NULL;
	if ((*currPtr)->DownFolder != NULL) temp = childPtr;
	do
	{
		Instruction();
		flag = 0;
		c = 0;
		puts("Please enter a filename for the new folder:");
		fgets(buf, 256, stdin);
		if (buf[254] == '\n')
			c = strlen(buf)-1;
		else
			c = strlen(buf);
		while (temp != NULL)//�������� �� ������������� � ������ �� ������� ����� � ����� ������
		{
			if (strcmp(buf, temp->FolderName) == 0)
			{
				puts("Error! Folder with this name already exists");
				flag = 1;
			}
			temp = temp->NextFolder;
		}
		if (c == 255) //������ ����� �������� 254 �������
		{
			puts("Error! File names seem to be limited to less than 254 characters");
			flag = 1;
			while (buf[254]!=NULL)
			{
				buf[254] = NULL;
				fgets(buf, 256, stdin);
			}
		}
		else
		{
			if (strchr(buf, p) != 0) //��� �������� ������������ ������ '/'
			{
				puts("Error! The folder name specified contains character that is not permitted: '/'");
				flag = 1;
			}
			else
			{
				if (c == 1) //��� ������
				{
					puts("Error! The folder name cannot be empty");
					flag = 1;
				}
			}
		}
	} while (flag != 0); //����������� ���, ���� ��� �� ����� ������������� ���� ��������
	newname = (char*)malloc(sizeof(char)*(c+1));
	strcpy(newname, buf);
	return(newname);
}

void Instruction()
{
	puts("Warning!");
	puts("1. The folder name cannot be empty");
	puts("2. The folder name cannot be less than 1 character or more than 255 characters");
	puts("3. The folder name cannot coitain '/' character");
}