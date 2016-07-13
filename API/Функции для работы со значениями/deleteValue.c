#include "deleteValue.h"

int deleteVal(VALUE* toDelete, NODE* start) {
	
	if (toDelete->NextValue == NULL) {

		if (start->Values->NextValue == NULL) {
			free(toDelete->Value);
			free(toDelete);
			start->Values = NULL;
			return 0;
		}
		else {
			VALUE* cur = start->Values;
			while (cur->NextValue != toDelete) {
				cur = cur->NextValue;
			}
			free(toDelete->Value);
			free(toDelete);
			cur->NextValue = NULL;
			return 1;
		}

	}
	else {
		VALUE *tmp = toDelete->NextValue;
		toDelete->Value = tmp->Value;
		toDelete->NextValue = tmp->NextValue;
		toDelete->Qualifier = tmp->Qualifier;
		free(tmp->Value);
		free(tmp);
		return 1;
	}
}