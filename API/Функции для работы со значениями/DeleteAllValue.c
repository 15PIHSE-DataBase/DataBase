#include "stdafx.h"

void DeleteAllValue(NODE *currPtr, TYPE Type) //удаляет все значения из узла или значения конкретного типа
{
	VALUE* prewValue = NULL; //указатель на предшествующий рассматриваемому элемент
	VALUE* currValue = currPtr->Values; // указатель рассматриваемый элемент
	while (currValue != NULL)
	{
		if ((currValue->type == Type) || (Type == ALL)) //если удовлетворяет заданному типу, то удалить
		{
			if (currValue->NextValue != NULL) // если этот элемент не последний, то переключаем указатель предыдущего на последующий, иначе указатель предыдущего NULL
			{
				currValue->Qualifier = currValue->NextValue->Qualifier;
				currValue->type = currValue->NextValue->type;
				currValue->Value = currValue->NextValue->Value;
				currValue->NextValue = currValue->NextValue->NextValue;
				free(currValue->NextValue->Qualifier); //освобождаем память выделенную под спецификатор
				free(currValue->NextValue->Value);//освобождаем память выделенную под имя
			}
			else
			{
				if (currPtr->Values == currValue)//удаляемый элемент первый и последний?
					currPtr->Values = NULL;
				else
					prewValue->NextValue = NULL;
				free(currValue->Qualifier);
				free(currValue->Value);
				free(currValue);
				break;
			}

		}
		prewValue = currValue;
		currValue = currValue->NextValue;
	}
}