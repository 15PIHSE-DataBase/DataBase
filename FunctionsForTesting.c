﻿//Сравнивает имя указанного узла и ожидаемое имя
void FindError(NODE * CurNode, char * ExprectedName) 
{
	if ((!CurNode) || (!ExprectedName))
		if ((!CurNode) && (!ExprectedName)) { printf("It's OK\n"); return;	}
		else {	printf("Error\n"); return;	}
	else{
		if (!strcmp(CurNode->NodeName, ExprectedName))
		{ printf("It's OK\n"); return; }
		else { printf("Error\n"); return; }
	}
}
//Построение дерева
void BuildTree(NODE ** root)
{
	//Массивы имён для узлов
	char name1[20] = "node1";
	char name2[20] = "node2";//_2_3
	char name3[20] = "node3";//_2_2
	char name4[20] = "node4";//_2_1
	//char name5[20] = "node5";//_3_21_2
	char name6[20] = "node6";//_3_21_1
	char name7[20] = "node7";//_3_22_3
	char name8[20] = "node8";//_3_22_2
	char name9[20] = "node9";//_3_22_1
	(*root) = InputTree((*root), name1); 
	NODE*pointer = NULL;
	pointer = InputTree((*root), name2);
	pointer = InputTree((*root), name3);
	pointer = InputTree((*root), name4); 
	NODE *ptr = (*root)->DownNode;
	//pointer = InputTree(ptr, name5);
	pointer = InputTree(ptr, name6);
	ptr = ptr->NextNode;
	pointer = InputTree(ptr, name7); //CheckFunc(pointer);
	pointer = InputTree(ptr, name8); //CheckFunc(pointer);
	pointer = InputTree(ptr, name9); //CheckFunc(pointer);
	FullTree(*root); //Распечатка всех путей дерева
}
//Проверяет указатель на NULL (отладка)
void CheckFunc(NODE * ptr)
{
	if (ptr)printf("%s\n", ptr->NodeName);
	else printf("Error\n");
}
//Проверка результатов PathList
void FullTree(NODE * begin)
{
	int print = PathList(begin);
	if (print) printf("\n");
	else printf("\nEmpty\n");
}
//Распечатка всех путей
int PathList(NODE * CurrentNode)
{
	if (CurrentNode == NULL)
		return NULL;//пустое дерево
	PathList(CurrentNode->DownNode);
	if (CurrentNode->DownNode == NULL)
		way(CurrentNode);
	PathList(CurrentNode->NextNode);
	return 1;//1 если хоть что-то вывело
}
//Поиск ошибок в функции InsertTree, параметром funct необходимо указать именно её
void ErrorSearch_InsertNode(char *NewName, NODE *CurPtr, NODE *funct(NODE*, char*))
{
	FindError(funct(CurPtr, NewName), NewName);
	FindError(funct(CurPtr, NewName), NULL);
	if (strcmp(CurPtr->NodeName, NewName) == 0)
		return;
	CurPtr = CurPtr->DownNode;
	if (CurPtr != NULL)
		while (CurPtr != NULL)
		{
			ErrorSearch_InsertNode(NewName, CurPtr, funct);
			CurPtr = CurPtr->NextNode;
		}
	return(NULL);
}
//Поиск ошибок в функции ChangeNodeName, параметром funct необходимо указать именно её
void ErrorSearch_ChangeNodeName(char *NewName, NODE *CurPtr, NODE *funct(NODE*, char*))
{
	if (goToNode(NewName, CurPtr->UpNode)) //Такое имя уже есть в узле
		FindError(funct(CurPtr, NewName), NULL);
	else FindError(funct(CurPtr, NewName), NewName);
	CurPtr = CurPtr->DownNode;
	if (CurPtr != NULL)
		while (CurPtr != NULL)
		{
			ErrorSearch_ChangeNodeName(NewName, CurPtr, funct);
			CurPtr = CurPtr->NextNode;
		}
}
void ErrorSearch_DeleteNode(char *Name, NODE * MainRoot)
{
	NODE * temp;
	while (temp = findnode(Name, MainRoot))
		if (!Delete(&temp,&MainRoot)) 
		printf("Nothing to remove\n");
}