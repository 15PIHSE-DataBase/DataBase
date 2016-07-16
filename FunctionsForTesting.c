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
		//if (((!CurNode) && (!ExprectedName)) || (!strcmp(CurNode->NodeName, ExprectedName)))  printf("It's OK\n");
		if (!strcmp(CurNode->NodeName, ExprectedName))
		{
			printf("It's OK\n");
			return;
		}
		else {
			printf("Error\n"); return;
		}
	}
}