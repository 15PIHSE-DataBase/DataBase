#include "stdafx.h"

int main()
{
	NODE* root = NULL;
	NODE* root1 = NULL;
	int a = 1;
	char p[10] = "Ves";
	char p1[10] = "100";
	char p2[10] = "Rost";
	char p3[10] = "101";
	char p4[10] = "Dlina";
	char p5[10] = "94";
	root = (NODE*)malloc(sizeof(NODE));
	root->UpNode = NULL;
	root->PreviousNode = NULL;
	root->DownNode = NULL;
	root->NextNode = NULL;
	root->Values = NULL;
	InputTree(&root, GetName(&root));
	Directory(root);
	InputTree(&root, GetName(&root));
	Directory(root);
	AddValue(root, p, INT, p1);
	//AddValue(root, p2, CHAR, p3);
	//AddValue(root, p4, INT, p5);
	//AddValue(root, p5, INT, p3);
	//PrintValues(root, ALL);
	deleteVal(root->Values, root);
	//DeleteAllValue(root, ALL);
	//ChangeValue(root->Values, 3, p3, p4);
	PrintValues(root, ALL);
	//ChangeValue(root->Values, 3, p2, p3);
	//PrintValues(root, ALL);
	_getch();
}