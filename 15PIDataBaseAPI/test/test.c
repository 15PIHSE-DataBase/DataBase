#include "stdafx.h"
#include "DataBase15.h"

int main()
{
	NODE* root = NULL;
	int o = 1;
	int lala;
	//int a = 1; 
	char p[10] = "Ves";
	char p1[10] = "100";
	char p2[10] = "Rost";
	char p3[10] = "101";
	char p4[10] = "Dlina";
	char p5[10] = "94";
	root = InputTree(NULL, "root");
	Directory(root);
	InputTree(root, "35");
	Directory(root);
	InputTree(root, "34");
	InputTree(root, "36");
	Directory(root);
	PrintValues(root->DownNode->NextNode, ALL);
	AddValue(root, p, INT, p1);
	AddValue(root, p2, CHAR, p3);
	AddValue(root, p4, CHAR, p5);
	AddValue(root, p5, INT, p3);
	PrintValues(root, ALL);
	lala = deleteVal(root->Values, root);
	//DeleteAllValue(root, INT); 
	PrintValues(root, ALL);
	//ChangeValue(root, root->Values, INT, p3, p4); 
	//PrintValues(root, ALL); 
	//ChangeValue(root, root->Values->NextValue, 7, p3, p5); 
	PrintValues(root, ALL);
	//CopyPasteValue(root, root->Values, root->DownNode->NextNode, &o);
	//deleteVal(root->Values, root); 
	PrintValues(root->DownNode, ALL);
	PrintValues(root, ALL);
	InputTree(root->DownNode, "46");
	Directory(root->DownNode);
	lala = Delete(&(root->DownNode->NextNode), &root);
	Directory(root);
	_getch();
}
