void FindError(NODE * CurNode, char * ExprectedName)
{
		if (!strcmp(CurNode->NodeName, ExprectedName))
		{
			printf("It's OK\n");
			return;
		}
		else {
			printf("Error\n"); return;
}