
#include "key.h"
#include "DataBase13.h"

NODE * DeleteNodes(NODE * CurrentNode)

int Delete(NODE ** CurrentNode, NODE ** Root)
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
		DeleteAllValues(TempNode, ALL);
		free(TempNode);
	}
	else if (TempNode->PreviousNode)
	{
		TempNode->PreviousNode->NextNode = NULL;
		DeleteAllValues(TempNode, ALL);
		free(TempNode);
	}
	else if (TempNode->NextNode)
	{
		TempNode->UpNode->DownNode = TempNode->NextNode;
		DeleteAllValues(TempNode, ALL);
		free(TempNode);
	}
	else if (TempNode->UpNode)
	{
		TempNode->UpNode->DownNode = NULL;
		DeleteAllValues(TempNode, ALL);
		free(TempNode);
	}
	else if (TempNode == *Root)
	{
		DeleteAllValues(TempNode, ALL);
		free(TempNode);
		*Root = NULL;
		*CurrentNode = NULL;
	}
	return 1;
}

NODE * DeleteNodes(NODE * CurrentNode)
{
	if (CurrentNode == NULL)
		return NULL;
	CurrentNode->NextNode = DeleteNodes(CurrentNode->NextNode);
	CurrentNode->DownNode = DeleteNodes(CurrentNode->DownNode);
	DeleteAllValues(CurrentNode, ALL);
	free(CurrentNode);
	return NULL;
}