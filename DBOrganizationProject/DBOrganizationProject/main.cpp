#include "stdafx.h"

int main()
{
	FOLDER* root = NULL;
	FOLDER* root1 = NULL;
	int a = 1;
	root = (folder*)malloc(sizeof(folder));
	root1 = (folder*)malloc(sizeof(folder));
	root->UpFolder = NULL;
	root->PreviousFolder = NULL;
	root->DownFolder = NULL;
	root->NextFolder = NULL;
	InputTree(&root);
	InputTree(&root);
	Directory(root);
	getch();
}