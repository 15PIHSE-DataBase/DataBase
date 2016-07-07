#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct filet
{
	//enum!!!
	char* FileName;
	void* Parametr;
	filet * NextFile;
}FILET;

typedef struct folder
{
	char FolderName[2];
	folder * UpFolder;
	folder * PreviousFolder;
	folder * NextFolder;
	folder * DownFolder;
	filet* File;
}FOLDER;