#include "deleteValue.h"

int deleteVal(VALUE* toDelete, NODE* start)
{
	VALUE* beginV = start->Values;
	VALUE* temp2 = NULL;
	VALUE* temp = NULL;
	while (beginV != toDelete && beginV != NULL)
	{
		temp2 = beginV;
		beginV = beginV->NextValue;
	}
	if (beginV == NULL) return(0);
	temp = beginV->NextValue;
	if (temp != NULL)
	{
		free(beginV->Qualifier);
		free(beginV->Value);
		beginV->Qualifier = temp->Qualifier;
		beginV->type = temp->type;
		beginV->Value = temp->Value;
		beginV->NextValue = temp->NextValue;
		free(temp);
	}
	else
	{
		if (start->Values == beginV)
			start->Values = NULL;
		free(beginV->Qualifier);
		free(beginV->Value);
		temp = beginV;
		temp2->NextValue = NULL;
		beginV = NULL;
		free(temp);
	}
	return(1);
}