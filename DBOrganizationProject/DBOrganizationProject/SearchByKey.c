#include "SearchByKey.h"

VALUE* searchThisNode(NODE* nodeptr, int key) {
	if (nodeptr->Values != NULL) {
		VALUE* curVal = nodeptr->Values;
		while (curVal) {
			if (curVal->key == key) {
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

VALUE* searchByKey(int key, NODE* beginf) {
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
			buf = searchByKey(key, beginf);
			beginf = beginf->NextNode;
		}

	return(NULL);
}
