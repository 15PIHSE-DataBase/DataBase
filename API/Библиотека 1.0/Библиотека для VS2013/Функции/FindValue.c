
#include "DataBase15.h"

VALUE* find_value_in_node(NODE* nodeptr, char* key) {
	if (nodeptr == NULL) return NULL;
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
		return NULL;
	}
	else {
		return NULL;
	}
}

/*VALUE* search_value_by_key(int key, NODE* beginf) {
NODE* buf = NULL;
val = search_this_node(buf, key);
if (val != NULL)//???? ?????????
{
return(val);
}
beginf = beginf->DownNode;
if (beginf != NULL)
while (beginf != NULL)//?????????? ?? ??????? ?????(NextNode)
{
buf = search_value_by_key(key, beginf);
beginf = beginf->NextNode;
}
return(NULL);
}*/
/*NODE* search_node_by_key(int key, NODE* beginf) {
NODE* buf = NULL;
val = search_this_node(buf, key);
if (val != NULL)//???? ?????????
{
return(beginf);
}
beginf = beginf->DownNode;
if (beginf != NULL)
while (beginf != NULL)//?????????? ?? ??????? ?????(NextNode)
{
buf = search_node_by_key(key, beginf);
beginf = beginf->NextNode;
}
return(NULL);
}*/