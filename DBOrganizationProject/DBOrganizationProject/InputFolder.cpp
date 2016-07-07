#include "stdafx.h"

void InputTree(FOLDER **currPtr)
{
	char buf[257], p = '/';
	bool flag = 0;
	int c;
	char *newname;
	do
	{
		flag = 0;
		puts("Please enter a filename for the new folder:"); 
		fgets(buf, 257, stdin);
		c = strlen(buf);
		if (c == 256)
		{
			puts("Error! File Names Seem to Be Limited to Less Than 255 Characters");
			flag = 1;
		}
		if (strchr(buf, p) != 0)
		{
			puts("Error! The file name specified contains characters that are not permitted: '/'");
			flag = 1;
		}
		if (c == 1)
		{
			puts("Error! The file name cannot be empty");
			flag = 1;
		}
	} while (flag != 0);
	FOLDER *newPtr = NULL;
	FOLDER *childPtr = NULL;
	newPtr = (FOLDER*)malloc(sizeof(FOLDER));
	if (newPtr == NULL){
		printf("No memory available \n");
		return;
	}
	newname = (char*)malloc(sizeof(char)*(c+1));
	strcpy(newname, buf);
	newPtr->FolderName = newname;
	newPtr->UpFolder = *currPtr;
	newPtr->DownFolder = NULL;
	childPtr = (*currPtr)->DownFolder;
	if (childPtr != NULL)
	{
		newPtr->NextFolder = childPtr;
		(childPtr)->PreviousFolder = newPtr;
	}
	else
	{
		newPtr->NextFolder = NULL;
	}
	newPtr->PreviousFolder = NULL;
	(*currPtr)->DownFolder = newPtr;
}

void Directory(FOLDER *CurrentF)
{
	FOLDER *temp;
	if (CurrentF->DownFolder != NULL) temp = CurrentF->DownFolder;
	else {
		printf("\nDirectory is empty.\n");
		return;
	}
	printf("\nDirectory contains:\n");
	while (1)
	{
		printf("%s", temp->FolderName);
		if ((temp->NextFolder) == NULL) break;
		else temp = temp->NextFolder;
	}
}
