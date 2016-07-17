#include"stdafx.h"
#include"DataBase13.h"

//прототипы
void FindError(NODE * CurNode, char * ExprectedName);
void BuildTree(NODE ** root);
void CheckFunc(NODE * ptr);
void FullTree(NODE * begin);
int PathList(NODE * CurrentNode);
void ErrorSearch_InsertNode(char *NewName, NODE *CurPtr, NODE *funct(NODE*, char*));
void ErrorSearch_ChangeNodeName(char *NewName, char*FindName, NODE *CurPtr, NODE *root);
void ErrorSearch_DeleteNode(char *Name, NODE * MainRoot);
void PrintLine(void);