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
