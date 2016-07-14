
#include "key.h"
#include "15PIDataBaseAPI.h"
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
		DeleteAllValues((*CurrentNode), ALL);
		free(*CurrentNode);
		*CurrentNode = NULL;
	}
	else if ((*CurrentNode)->PreviousNode)
	{
		(*CurrentNode)->PreviousNode->NextNode = NULL;
		DeleteAllValues((*CurrentNode), ALL);
		free((*CurrentNode));
		*CurrentNode = NULL;
	}
	else if ((*CurrentNode)->NextNode)
	{
		(*CurrentNode)->UpNode->DownNode = (*CurrentNode)->NextNode;
		DeleteAllValues((*CurrentNode), ALL);
		free(*CurrentNode);
		*CurrentNode = NULL;
	}
	else if ((*CurrentNode)->UpNode)
	{
		(*CurrentNode)->UpNode->DownNode = NULL;
		DeleteAllValues((*CurrentNode), ALL);
		free(*CurrentNode);
		*CurrentNode = NULL;
	}
	else if (*CurrentNode == *Root)
	{
		DeleteAllValues(*CurrentNode, ALL);
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
	DeleteAllValues(CurrentNode, ALL);
	free(CurrentNode);
	return NULL;
}