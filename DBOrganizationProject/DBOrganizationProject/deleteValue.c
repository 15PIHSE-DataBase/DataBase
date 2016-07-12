#include "deleteValue.h"
int deleteVal(int key, NODE* start) {
	Value *curKey;
	curKey = searchByKey(key, start);
	if (curKey->NextValue ==  NULL || curKey == NULL) {
		free(curKey);
		return 0;
	}
	VALUE *tmp = curKey->NextValue;
	curKey->Value = tmp->Value;
	curKey->NextValue = tmp->NextValue;
	free(tmp);
	return 1;
}