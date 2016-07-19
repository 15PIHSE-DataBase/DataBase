

#include "DataBase15.h"
NODE * delete_nodes(NODE *);

int delete_node(NODE** CurrentNode, NODE** Root)//если удалил,то вернет 1;Нечего удалять --> вернет 0;
{
	NODE* temp = *CurrentNode;
	if (*CurrentNode == NULL)
		return 0;
	if ((*CurrentNode)->DownNode)
		(*CurrentNode)->DownNode = delete_nodes((*CurrentNode)->DownNode);
	printf("%s deleted\n", (*CurrentNode)->NodeName);
	if ((*CurrentNode)->PreviousNode && (*CurrentNode)->NextNode)
	{
		(*CurrentNode)->PreviousNode->NextNode = (*CurrentNode)->NextNode;
		temp->NextNode->PreviousNode = temp->PreviousNode;
		delete_all_value(temp, ALL);
		free(temp);
	}
	else if ((*CurrentNode)->PreviousNode)
	{
		(*CurrentNode)->PreviousNode->NextNode = NULL;
		delete_all_value(temp, ALL);
		free(temp);
		*CurrentNode = NULL;
	}
	else if ((*CurrentNode)->NextNode)
	{
		(*CurrentNode)->UpNode->DownNode = (*CurrentNode)->NextNode;
		delete_all_value(temp, ALL);
		free(temp);
	}
	else if ((*CurrentNode)->UpNode)
	{
		(*CurrentNode)->UpNode->DownNode = NULL;
		delete_all_value(temp, ALL);
		free(temp);
	}
	else if (*CurrentNode == *Root)
	{
		delete_all_value(*CurrentNode, ALL);
		free(*CurrentNode);
		*CurrentNode = NULL;
		*Root = NULL;
	}
	return 1;
}

NODE * delete_nodes(NODE * CurrentNode)
{
	if (CurrentNode == NULL)
		return NULL;
	CurrentNode->NextNode = delete_nodes(CurrentNode->NextNode);
	CurrentNode->DownNode = delete_nodes(CurrentNode->DownNode);
	delete_all_value(CurrentNode, ALL);
	free(CurrentNode);
	return NULL;
}