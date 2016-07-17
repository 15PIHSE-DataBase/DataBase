
#include "DataBase15.h"


void Directory(NODE *Current)
{
	NODE *temp;
	if ((Current != NULL) && (Current->DownNode != NULL)) temp = Current->DownNode;
	else {
		printf("\nDirectory is empty.\n");
		return;
	}
	printf("\nDirectory contains:\n");
	while (1)
	{
		printf("%s\n", temp->NodeName);
		if ((temp->NextNode) == NULL) break;
		else temp = temp->NextNode;
	}
}