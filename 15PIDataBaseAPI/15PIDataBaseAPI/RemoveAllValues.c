
#include "15PIDataBaseAPI.h"

void DeleteAllValue(NODE *currPtr, TYPE Type) //удаляет все значения из узла или значения конкретного типа
{

	VALUE* beginV = currPtr->Values;
	VALUE* temp2 = currPtr->Values;
	VALUE* temp = NULL;
	while (beginV != NULL)
	{
		if ((beginV->type == Type) || (Type == ALL)) //если удовлетворяет заданному типу, то удалить
		{
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
				if (currPtr->Values == beginV)
					currPtr->Values = NULL;
				free(beginV->Qualifier); //освобождаем память выделенную под спецификатор
				free(beginV->Value); //освобождаем память выделенную под имя
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