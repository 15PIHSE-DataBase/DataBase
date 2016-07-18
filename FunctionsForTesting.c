#include"FunctionsForTesting.h"
#include"DataBase13.h"
//Сравнивает имя указанного узла и ожидаемое имя
void find_error(NODE * CurNode, char * ExprectedName)
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
void build_tree(NODE ** root)
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
	(*root) = input_tree((*root), name1); 
	NODE*pointer = NULL;
	pointer = input_tree((*root), name2);
	pointer = input_tree((*root), name3); 
	pointer = input_tree((*root), name4); 
	NODE *ptr = (*root)->DownNode;
	//pointer = InputTree(ptr, name5);
	pointer = input_tree(ptr, name6);
	ptr = ptr->NextNode;
	pointer = input_tree(ptr, name7);// CheckFunc(pointer);
	pointer = input_tree(ptr, name8); //CheckFunc(pointer);
	pointer = input_tree(ptr, name9); //CheckFunc(pointer);
	full_tree(*root);
}
//Проверяет указатель на NULL (отладка)
void check_func(NODE * ptr)
{
	if (ptr)printf("%s\n", ptr->NodeName);
	else printf("Error\n");
}
//Проверка результатов path_list
void full_tree(NODE * begin)
{
	if (!(path_list(begin))) printf("Empty\n");
}
//Линия разделения проверок
void print_line(void)
{
	for (int i = 0; i < 30; i++)
		printf("=");
	printf("\n");
}
//Поиск ошибок в функции insert_tree, параметром funct необходимо указать именно её
void error_search_insert_node(char *NewName, NODE *CurPtr, NODE *funct(NODE*, char*))
{
	find_error(funct(CurPtr, NewName), NewName);
	find_error(funct(CurPtr, NewName), NULL);
	if (strcmp(CurPtr->NodeName, NewName) == 0)
		return;
	CurPtr = CurPtr->DownNode;
	if (CurPtr != NULL)
		while (CurPtr != NULL)
		{
			error_search_insert_node(NewName, CurPtr, funct);
			CurPtr = CurPtr->NextNode;
		}
}
//Поиск ошибок в функции change_node_name, параметром funct необходимо указать именно её
void error_search_change_node_name(char *NewName, char*FindName, NODE *CurPtr, NODE *root)
{
	NODE * temp = find_node(FindName, root);
	if (!temp) return;
	if (go_to_node(NewName, up_step(temp))) //Такое имя уже есть в узле
		find_error(change_node_name(temp, NewName), NULL);
	else find_error(change_node_name(temp, NewName), NewName);
	CurPtr = CurPtr->DownNode;
	if (CurPtr != NULL)
		while (CurPtr != NULL)
		{
			error_search_change_node_name(NewName, FindName, CurPtr, root);
			CurPtr = CurPtr->NextNode;
		}
}
//Поиск ошибок в функции delete_node
void error_search_delete_node(char *Name, NODE ** MainRoot)
{
	if (!(*MainRoot)){
		printf("Wrong pointer\n");
		return;
	}
	NODE * temp;
	while (temp = find_node(Name, *MainRoot)){
		if (!delete_node(&temp, MainRoot))
			printf("Nothing to delete\n");
		if (!(*MainRoot)) break;
	}

}
//Сравнивает информацию указанного значения с ожидаемыми
void find_error_in_values(VALUE * Current, char * ExpectedValue, char*ExpectedQualifier, TYPE ExpectedType)
{
	if ((!Current) || (!ExpectedValue) || (!ExpectedQualifier))
		if ((!Current) && (!ExpectedValue) && (!ExpectedQualifier)) { printf("It's OK\n"); return; }
		else { printf("Error\n"); return; }
	else{
		if ((!strcmp(Current->Value, ExpectedValue)) && (!strcmp(Current->Qualifier, ExpectedQualifier)) && (Current->type = ExpectedType))
		{
			printf("It's OK\n"); return;
		}
		else { printf("Error\n"); return; }
	}
}
//Поиск ошибок в функции add_value
void error_search_add_value(NODE * node)
{
	char Value[4][10] = { "100y", "red", "forest", "1m" }, Qualif[4][10] = { "Age", "Color", "Place", "Size" };
	for (int i = 0; i < 4; i++){
		find_error_in_values(add_value(node, Qualif[i], INT, Value[i]), Value[i], Qualif[i], INT);
		find_error_in_values(add_value(node, Qualif[i], INT, Value[i]), NULL, NULL, INT);
	}
}
//Поиск ошибок в функциях поиска и удаления значения узла
void error_search_find_delete_value(NODE * node)
{
	char Qualif[4][10] = { "Age", "Color", "Place", "Size" }, Value[4][10] = { "100y", "red", "forest", "1m" };
	VALUE * temp; int result;
	temp = find_value_in_node(node, Qualif[0]);
	find_error_in_values(temp, Value[0], Qualif[0], INT);
	result = delete_val(temp, node);
	print_values(node, ALL);

	temp = find_value_in_node(node, Qualif[2]);
	find_error_in_values(temp, Value[2], Qualif[2], INT);
	result = delete_val(temp, node);
	print_values(node, ALL);

	temp = find_value_in_node(node, Qualif[3]);
	find_error_in_values(temp, Value[3], Qualif[3], INT);
	result = delete_val(temp, node);
	print_values(node, ALL);

	find_error_in_values(find_value_in_node(node, Qualif[3]), NULL, NULL, INT); //провека на поиск несуществующего спецификатора
	/*
	temp = find_value_in_node(node, Qualif[1]);
	find_error_in_values(temp, Value[1], Qualif[1], INT);
	result = delete_val(temp, node);
	print_values(node, ALL);
	*/
}
//Поиск ошибок в функциях поиска и удаления значения узла
void error_search_delete_all_values(NODE * node)
{
	delete_all_value(node, INT);
	print_values(node, INT);
}
