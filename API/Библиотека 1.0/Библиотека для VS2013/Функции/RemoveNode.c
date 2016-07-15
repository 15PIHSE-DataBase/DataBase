
#include "key.h"
#include "DataBase13.h"
NODE * DeleteNodes(NODE *);

int Delete(NODE** CurrentNode, NODE** Root)//если удалил,то вернет 1;Нечего удалять --> вернет 0;
{
	if (*CurrentNode == NULL)
		return 0;
	if ((*CurrentNode)->DownNode)
		(*CurrentNode)->DownNode = DeleteNodes((*CurrentNode)->DownNode);
	printf("%s deleted\n", (*CurrentNode)->NodeName);
	if ((*CurrentNode)->PreviousNode && (*CurrentNode)->NextNode)
	{
		(*CurrentNode)->PreviousNode->NextNode = (*CurrentNode)->NextNode;
		(*CurrentNode)->NextNode->PreviousNode = (*CurrentNode)->PreviousNode;
		DeleteAllValue((*CurrentNode), ALL);
		free(*CurrentNode);
		*CurrentNode = NULL;
	}
	else if ((*CurrentNode)->PreviousNode)
	{
		(*CurrentNode)->PreviousNode->NextNode = NULL;
		DeleteAllValue((*CurrentNode), ALL);
		free((*CurrentNode));
		*CurrentNode = NULL;
	}
	else if ((*CurrentNode)->NextNode)
	{
		(*CurrentNode)->UpNode->DownNode = (*CurrentNode)->NextNode;
		DeleteAllValue((*CurrentNode), ALL);
		free(*CurrentNode);
		*CurrentNode = NULL;
	}
	else if ((*CurrentNode)->UpNode)
	{
		(*CurrentNode)->UpNode->DownNode = NULL;
		DeleteAllValue((*CurrentNode), ALL);
		free(*CurrentNode);
		*CurrentNode = NULL;
	}
	else if (*CurrentNode == *Root)
	{
		DeleteAllValue(*CurrentNode, ALL);
		free(*CurrentNode);
		*CurrentNode = NULL;
		*Root = NULL;
	}
	return 1;
}

NODE * DeleteNodes(NODE * CurrentNode)
{
	if (CurrentNode == NULL)
		return NULL;
	CurrentNode->NextNode = DeleteNodes(CurrentNode->NextNode);
	CurrentNode->DownNode = DeleteNodes(CurrentNode->DownNode);
	DeleteAllValue(CurrentNode, ALL);
	free(CurrentNode);
	return NULL;
}