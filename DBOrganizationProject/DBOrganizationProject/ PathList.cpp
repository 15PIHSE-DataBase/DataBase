void PathList(NODE * CurrentNode)
{
	if (CurrentNode == NULL)
		return;
	PathList(CurrentNode->DownNode);
	if (CurrentNode->DownNode == NULL )
		way(CurrentNode);
	PathList(CurrentNode->NextNode);
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
	//memset(buf, 0, len);
	strcat(ways, ".");
	strcat(ways, beginf->NodeName);
	strcpy(buf, ways);
	beginf = beginf->UpNode;

	while (beginf != NULL)
	{
		len = len + strlen(beginf->NodeName) + 1;
		ways = (char*)malloc(len);
		memset(ways, 0, len);
		if (beginf->UpNode != NULL)
			strcat(ways, ".");
		strcat(ways, beginf->NodeName);
		strcat(ways, buf);
		buf = (char*)malloc(len);
		//memset(buf, 0, len);
		strcpy(buf, ways);
		beginf = beginf->UpNode;
	}
	printf("%s\n", ways);
}

