#include "deleteValue.h"
int deleteVal(int key) {
	KEYS *curKey;
	curKey = searchKey(key);
	if (curKey->NextKey ==  NULL || curKey == NULL) {
		free(curKey);
		return 0;
	}
	KEYS *tmp = curKey->NextKey;
	curKey->Value = tmp->Value;
	curKey->NextKey = tmp->NextKey;
	free(tmp);
	return 1;
}