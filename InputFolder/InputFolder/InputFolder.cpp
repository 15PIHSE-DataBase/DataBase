#include "stdafx.h"

void InputTree(FOLDER **currPtr)
{
	Instruction();
	char buf[257], p = '/';
	bool flag = 0;
	int c;
	char *newname;
	FOLDER *childPtr = NULL;
	childPtr = (*currPtr)->DownFolder;
	FOLDER *temp = NULL;
	if ((*currPtr)->DownFolder != NULL) temp = childPtr;
	do
	{
		flag = 0;
		puts("Please enter a filename for the new folder:"); 
		fgets(buf, 257, stdin);
		c = strlen(buf);
		while (temp!=NULL)//�������� �� ������������� � ������ �� ������� ����� � ����� ������
		{
			if (strcmp(buf, temp->FolderName) == 0)
			{ 
				puts("Error! Folder with this name already exists");
				flag = 1;
				break;
			}
		    temp = temp->NextFolder;
		}
		if (c == 256) //������ ����� �������� 255 ��������
		{
			puts("Error! File Names Seem to Be Limited to Less Than 255 Characters");
			flag = 1;
		}
		if (strchr(buf, p) != 0) //��� �������� ������������ ������ '/'
		{
			puts("Error! The folder name specified contains character that is not permitted: '/'");
			flag = 1;
		}
		if (c == 1) //��� ������
		{
			puts("Error! The folder name cannot be empty");
			flag = 1;
		}
	} while (flag != 0); //����������� ���, ���� ��� �� ����� ������������� ���� ��������
	FOLDER *newPtr = NULL;
	newPtr = (FOLDER*)malloc(sizeof(FOLDER));//������� ����� ���������(�����)
	if (newPtr == NULL){
		printf("No memory available \n");
		return;
	}
	newname = (char*)malloc(sizeof(char)*(c+1));//����� �������� �������� ������(���, ��������� �� ������, ��������� �� �������, �� ��������� NULL)
	strcpy(newname, buf);
	newPtr->FolderName = newname;
	newPtr->UpFolder = *currPtr;
	newPtr->DownFolder = NULL;
	newPtr->Values = NULL;
	if (childPtr != NULL)
	{
		newPtr->NextFolder = childPtr;//���������� ����� ���� � ������
		(childPtr)->PreviousFolder = newPtr;//� ������ � ����� ����
	}
	else
	{
		newPtr->NextFolder = NULL;
	}
	newPtr->PreviousFolder = NULL;
	(*currPtr)->DownFolder = newPtr;//���������� ����� ���� � ������
}//����� ����������� ���������� ����� ���������

void Instruction()
{
	puts("Warning!");
	puts("1. The folder name cannot be empty");
	puts("2. The folder name cannot be less than 1 character or more than 255 characters");
	puts("3. The folder name cannot coitain '/' character");
}
