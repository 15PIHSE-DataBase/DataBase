
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
