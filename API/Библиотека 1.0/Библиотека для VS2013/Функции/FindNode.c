
#include "DataBase15.h"

NODE* find_node(char* findname, NODE* beginf)
{
	NODE* buf = NULL;
	if (strcmp(beginf->NodeName, findname) == 0)
	{
		return(beginf);
	}
	beginf = beginf->DownNode;
	if (beginf != NULL)
		while (beginf != NULL)
		{
			buf = find_node(findname, beginf);
			if (buf != NULL)
				return(buf);
			beginf = beginf->NextNode;
		}
	return(NULL);
}