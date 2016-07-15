#include "stdafx.h"
#include "15PIDataBaseAPI.h"

int main()
{

	NODE* root = NULL;
	NODE* NewNode = NULL;
	root = InputTree(NULL, "root");
	Directory(root);
	NewNode = InputTree(root, "NewNode");
	Directory(root);
	NewNode = InputTree(root, "NewNode2");
	NewNode = findnode("NewNode", root);
	Directory(NewNode);
	getch();
}