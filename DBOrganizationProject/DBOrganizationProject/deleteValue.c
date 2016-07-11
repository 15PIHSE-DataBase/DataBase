#include "deleteValue.h"
int deleteVal(int key) {
	Value *curKey;
	curKey = searchKey(key);
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