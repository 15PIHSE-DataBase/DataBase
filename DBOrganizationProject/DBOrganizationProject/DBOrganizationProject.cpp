#include <stdio.h>
#include <stdlib.h>

typedef struct filet
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
}FOLDER;

folder * root;

int main()
{
	int a = 1;
	root = (folder*)malloc(sizeof(folder));
	root->UpFolder = NULL;
	root->PreviousFolder = NULL;
	root->NextFolder = (folder*)malloc(sizeof(folder));
	root->File = (filet*)malloc(sizeof(filet));
	root->File->Parametr = &a;
	printf("lol");
	printf("%d\n", *(int*)root->File->Parametr);
	return 0;
}

