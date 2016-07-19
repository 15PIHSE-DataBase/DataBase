#include "DataBase15.h"

int path_list(NODE * CurrentNode)
{
	if (CurrentNode == NULL)
		return NULL;//пустое дерево
	path_list(CurrentNode->DownNode);
	if (CurrentNode->DownNode == NULL)
		way(CurrentNode);
	path_list(CurrentNode->NextNode);
	return 1;//1 если хоть что-то вывело
}


void way(NODE * beginf)
{
	
	char* ways;
	char* buf;
	int len = 0;
	len = strlen(beginf->NodeName) + 1;
	ways = (char*)malloc(len);
	buf = (char*)malloc(len);
	memset(ways, 0, len);
	if (beginf->UpNode != NULL) {
		strcat(ways, ".");
	}
	strcat(ways, beginf->NodeName);
	strcpy(buf, ways);
	beginf = beginf->UpNode;
	
	while (beginf != NULL)
	{
		len = len + strlen(beginf->NodeName) + 1;
		ways = (char*)realloc(ways, len);
		memset(ways, 0, len);
		if (beginf->UpNode != NULL)
			strcat(ways, ".");
		strcat(ways, beginf->NodeName);
		strcat(ways, buf);
		buf = (char*)realloc(buf, len);
		strcpy(buf, ways);
		beginf = beginf->UpNode;
	}
	printf("%s\n", ways);
	free(ways);
	free(buf);
}
