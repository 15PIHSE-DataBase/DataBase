#include "SearchByKey.h"

VALUE* findValueInNode(NODE* nodeptr, char* key) {
	if (nodeptr->Values != NULL) {
		VALUE* curVal = nodeptr->Values;
		while (curVal) {
			if (strcmp(curVal->Qualifier, key) == 0) {
				return curVal;
			}
			else {
				curVal = curVal->NextValue;
			}
		}
	}
	else {
		return NULL;
	}
}

/*VALUE* searchValueByKey(int key, NODE* beginf) {
	NODE* buf = NULL;
	val = searchThisNode(buf, key);
	if (val != NULL)//Идёт сравнение
	{
		return(val);
	}
	beginf = beginf->DownNode;
	if (beginf != NULL)
		while (beginf != NULL)//Проходимся по каждому брату(NextNode)
		{
			buf = searchValueByKey(key, beginf);
			beginf = beginf->NextNode;
		}

	return(NULL);
}*/
/*NODE* searchNodeByKey(int key, NODE* beginf) {
	NODE* buf = NULL;
	val = searchThisNode(buf, key);
	if (val != NULL)//Идёт сравнение
	{
		return(beginf);
	}
	beginf = beginf->DownNode;
	if (beginf != NULL)
		while (beginf != NULL)//Проходимся по каждому брату(NextNode)
		{
			buf = searchNodeByKey(key, beginf);
			beginf = beginf->NextNode;
		}

	return(NULL);
}*/
