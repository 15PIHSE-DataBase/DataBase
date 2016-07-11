#include "stdafx.h"

NODE* root;
int main()
{
	int keys = 10;
	root = (NODE*)malloc(sizeof(NODE));
	root->UpNode = NULL;
	root->PreviousNode = NULL;
	root->DownNode = NULL;
	strcpy(root->NodeName, "LOL");
	root->NextNode = (NODE*)malloc(sizeof(NODE));
	printf("%s\n",root->NodeName);
	printf("%d\n", keys);
	return 0;
}

