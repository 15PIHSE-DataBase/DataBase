#include "deleteValue.h"
int deleteVal(KEYS *keyToDelete) {
	KEYS *curKey;
	curKey = searchKey(keyToDelete);
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