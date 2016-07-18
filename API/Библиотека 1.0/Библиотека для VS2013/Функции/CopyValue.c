
#include "DataBase13.h"

#define PASTE_SUCCESS 2
#define WRONG_DATA_TYPE 3
#define ALREADY_EXISTS 1



VALUE * Copy(VALUE * ValueFrom)
{
	if (ValueFrom == NULL)
		return NULL;
	VALUE * COPY = (VALUE*)malloc(sizeof(VALUE));
	COPY->Qualifier = (char*)malloc(strlen(ValueFrom->Qualifier) + 1);
	COPY->Value = (char*)malloc(strlen(ValueFrom->Value) + 1);
	memmove(COPY->Qualifier, ValueFrom->Qualifier, strlen(ValueFrom->Qualifier) + 1);
	memmove(COPY->Value, ValueFrom->Value, strlen(ValueFrom->Value) + 1);
	COPY->type = ValueFrom->type;
	COPY->NextValue = NULL;
	return COPY;//СОЗДАЕТСЯ КОПИЯ ОБЪЕКТА ,ЕЙ НУЖНО БУДЕТ ОСВОБОЖДАТЬ ПАМЯТЬ,ЕСЛИ НЕ БУДЕТ ИСПОЛЬЗОВАТЬСЯ ДАЛЬШЕ(ОЧИСТКА БУФЕРА ТИПО)
}

int Paste(NODE * PasteTo, VALUE * Copy)
{
	if (PasteTo == NULL)
		return NULL;
	VALUE * Temp = PasteTo->Values;
	if (PasteTo->Values == NULL)
	{
		PasteTo->Values = Copy;
		return PASTE_SUCCESS;
	}
	else
	{
		if (findValueInNode(PasteTo, Copy->Qualifier) != NULL)
			return ALREADY_EXISTS;
		Copy->NextValue = PasteTo->Values;
		PasteTo->Values = Copy;
		return PASTE_SUCCESS;
	}
}