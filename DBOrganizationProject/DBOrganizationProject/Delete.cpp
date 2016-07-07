// DataBase.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>


/*typedef struct filet
{
	//enum!!!
	char* FileName;
	void* Parametr;
	filet * NextFile;
}FILET;

typedef struct folder
{
	char* FolderName;
	folder * UpFolder;
	folder * PreviousFolder;
	folder * NextFolder;
	folder * DownFolder;
	filet* File;
}FOLDER;*/



typedef struct Node
{
	Node * UpFolder;
	Node * DownFolder;
	Node * NextFolder;
	Node * PreviousFolder;
	int value;
}Node;

void DeleteFolders(Node *);
void Delete(Node *);

int main()
{
	Node * head = (Node*)malloc(sizeof(Node));
	Node * tmp = head;
	head->UpFolder = NULL;
	head->NextFolder = NULL;
	head->PreviousFolder = NULL;
	head->value = 1;
	head->DownFolder = (Node*)malloc(sizeof(Node));
	head = head->DownFolder;
	head->value = 2;
	head->UpFolder= tmp;
	head->DownFolder = (Node*)malloc(sizeof(Node));
	head->DownFolder->UpFolder = head;
	head = head->DownFolder;
	head->DownFolder = NULL;
	head->NextFolder = NULL;
	head->PreviousFolder = NULL;
	head->value = 5;
	head = head->UpFolder;
	head->NextFolder = (Node*)malloc(sizeof(Node));
	head->NextFolder->PreviousFolder = head;
	head = head->NextFolder;
	head->value = 3;
	head->UpFolder = tmp;
	head->NextFolder = NULL;
	head->DownFolder = (Node*)malloc(sizeof(Node));
	head->DownFolder->UpFolder = head;
	head = head->DownFolder;
	head->DownFolder = NULL;
	head->NextFolder = (Node*)malloc(sizeof(Node));
	head->PreviousFolder = NULL;
	head->value = 4;
	head->NextFolder->PreviousFolder = head;
	head = head->NextFolder;
	head->NextFolder = NULL;
	head->DownFolder = NULL;
	head->value = 6;
	Delete(tmp);
}

void Delete(Node * root)
{
	if (root->DownFolder)
		DeleteFolders(root->DownFolder);
	printf("%d\t", root->value);
	if (root->PreviousFolder && root->NextFolder)
		root->PreviousFolder->NextFolder = root->NextFolder;
	free(root);
}

void DeleteFolders(Node * root)
{
	if (root->DownFolder == NULL && root->NextFolder)
	{
		DeleteFolders(root->NextFolder);
		printf("%d\t", root->value);
		free(root);
	}
	else if (root->DownFolder && root->NextFolder == NULL)
	{
		DeleteFolders(root->DownFolder);
		printf("%d\t", root->value);
		free(root);
	}
	else if (root->DownFolder && root->NextFolder)
	{
		DeleteFolders(root->NextFolder);
		DeleteFolders(root->DownFolder);
		printf("%d\t", root->value);
		free(root);
	}
	else if (root->DownFolder == NULL && root->NextFolder == NULL)
	{
		printf("%d\t", root->value);
		free(root);
	}
}
