
int delete(NODE ** CurrentNode, NODE ** Root)
{
	NODE* TempNode = *CurrentNode;
	if (TempNode == NULL)
		return 0;
	if (TempNode->DownNode)
		TempNode->DownNode = DeleteNodes(TempNode->DownNode);
	printf("%s deleted\n", TempNode->NodeName);
	if (TempNode->PreviousNode && TempNode->NextNode)
	{
		TempNode->NextNode->PreviousNode = TempNode->PreviousNode;
		TempNode->PreviousNode->NextNode = TempNode->NextNode;
		delete_all_values(TempNode, ALL);
		free(TempNode);
	}
	else if (TempNode->PreviousNode)
	{
		TempNode->PreviousNode->NextNode = NULL;
		delete_all_values(TempNode, ALL);
		free(TempNode);
	}
	else if (TempNode->NextNode)
	{
		TempNode->UpNode->DownNode = TempNode->NextNode;
		delete_all_values(TempNode, ALL);
		free(TempNode);
	}
	else if (TempNode->UpNode)
	{
		TempNode->UpNode->DownNode = NULL;
		delete_all_values(TempNode, ALL);
		free(TempNode);
	}
	else if (TempNode == *Root)
	{
		delete_all_values(TempNode, ALL);
		free(TempNode);
		*Root = NULL;
		*CurrentNode = NULL;
	}
	return 1;
}

NODE * delete_nodes(NODE * CurrentNode)
{
	if (CurrentNode == NULL)
		return NULL;
	CurrentNode->NextNode = DeleteNodes(CurrentNode->NextNode);
	CurrentNode->DownNode = DeleteNodes(CurrentNode->DownNode);
	delete_all_values(CurrentNode, ALL);
	free(CurrentNode);
	return NULL;
}
