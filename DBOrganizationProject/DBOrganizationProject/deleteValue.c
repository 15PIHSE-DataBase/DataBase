#include "deleteValue.h"

int deleteVal(VALUE* toDelete, NODE* start) {
	
	if (toDelete->NextValue ==  NULL || toDelete == NULL) {
		free(toDelete);
		start->Values = NULL;
		return 0;
	}
	else {
		VALUE *tmp = toDelete->NextValue;
		toDelete->Value = tmp->Value;
		toDelete->NextValue = tmp->NextValue;
		toDelete->Qualifier = tmp->Qualifier;
		free(tmp);
		return 1;
	}
}