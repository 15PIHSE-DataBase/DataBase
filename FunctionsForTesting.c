void FindError(NODE * CurNode, char * ExprectedName)
{
	if ((!CurNode) || (!ExprectedName))
		if ((!CurNode) && (!ExprectedName)) {
			printf("It's OK\n"); return;
		}
		else {
			printf("Error\n"); return;
		}
	else{
		if (!strcmp(CurNode->NodeName, ExprectedName))
		{
			printf("It's OK\n"); return;
		}
		else {
			printf("Error\n"); return;
		}
	}
}

void BuildTree(NODE * root)
{
	//Массивы имён для узлов
	char name1[20] = "node1";
	char name2[20] = "node2";//_2_3
	char name3[20] = "node3";//_2_2
	char name4[20] = "node4";//_2_1
	char name5[20] = "node5";//_3_21_2
	char name6[20] = "node6";//_3_21_1
	char name7[20] = "node7";//_3_22_3
	char name8[20] = "node8";//_3_22_2
	char name9[20] = "node9";//_3_22_1
	(*root) = InputTree((*root), name1); 
	pointer = InputTree((*root), name2);
	pointer = InputTree((*root), name3); 
	pointer = InputTree((*root), name4); 
}