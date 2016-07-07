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
	Node * Father;
	Node * Child;
	Node * NextBrother;
	Node * PreviousBrother;
	int value;
}Node;

void DeleteFolder(Node *);

int main()
{
	Node * head = (Node*)malloc(sizeof(Node));
	Node * tmp = head;
	head->Father = NULL;
	head->NextBrother = NULL;
	head->PreviousBrother = NULL;
	head->value = 1;
	head->Child = (Node*)malloc(sizeof(Node));
	head = head->Child;
	head->value = 2;
	head->Father = tmp;
	head->Child = (Node*)malloc(sizeof(Node));
	head->Child->Father = head;
	head = head->Child;
	head->Child = NULL;
	head->NextBrother = NULL;
	head->PreviousBrother = NULL;
	head->value = 5;
	head = head->Father;
	head->NextBrother = (Node*)malloc(sizeof(Node));
	head->NextBrother->PreviousBrother = head;
	head = head->NextBrother;
	head->value = 3;
	head->Father = tmp;
	head->NextBrother = NULL;
	head->Child = (Node*)malloc(sizeof(Node));
	head->Child->Father = head;
	head = head->Child;
	head->Child = NULL;
	head->NextBrother = NULL;
	head->PreviousBrother = NULL;
	head->value = 4;

	DeleteFolder(tmp->Child);
	free(tmp);
}


void DeleteFolder(Node * root)
{
	static Node * tmp;
	if (root == NULL)
	{
		free(tmp);
		printf("NULL");
	}
	if (root->Child == NULL && root->NextBrother)
	{
		DeleteFolder(root->NextBrother);
		printf("%d\t", root->value);
		free(root);
	}
	else if (root->Child && root->NextBrother == NULL)
	{
		DeleteFolder(root->Child);
		printf("%d\t", root->value);
		free(root);
	}
	else if (root->Child && root->NextBrother)
	{
		DeleteFolder(root->NextBrother);
		DeleteFolder(root->Child);
		printf("%d\t", root->value);
		free(root);
	}
	else if (root->Child == NULL && root->NextBrother == NULL)
	{
		printf("%d\t", root->value);
		tmp = root->Father;
		free(root);
	}
}