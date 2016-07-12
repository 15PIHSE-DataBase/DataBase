#include "deleteValue.h"

int deleteVal(int key, NODE* start) {
	VALUE *curKey;
	curKey = searchByKey(key, start);
	if (curKey->NextValue ==  NULL || curKey == NULL) {
		delete_key(key);
		free(curKey);
		return 0;
	}
	VALUE *tmp = curKey->NextValue;
	curKey->Value = tmp->Value;
	curKey->NextValue = tmp->NextValue;
	delete_key(key);
	free(tmp);
	return 1;
}