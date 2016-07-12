#include "stdafx.h"

void DeleteAllValue(NODE *currPtr, TYPE Type) //удаляет все значения из узла или значения конкретного типа
{

	VALUE* beginV = currPtr->Values;
	VALUE* temp2 = currPtr->Values;
	VALUE* temp = NULL;
	while (beginV != NULL)
	{
		if ((beginV->type == Type) || (Type == ALL))
		{
			temp = beginV->NextValue;
			if (temp != NULL)
			{
				beginV->Qualifier = temp->Qualifier;
				beginV->type = temp->type;
				beginV->Value = temp->Value;
				beginV->NextValue = temp->NextValue;
				free(temp);
			}
			else
			{
				if (currPtr->Values == beginV)
					currPtr->Values = NULL;
				temp = beginV;
				temp2->NextValue = NULL;
				beginV = NULL;
				free(temp);
				break;
			}

		}
		else
		{
			temp2 = beginV;
			beginV = beginV->NextValue;
		}
	}
}