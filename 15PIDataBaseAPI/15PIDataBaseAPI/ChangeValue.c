 
#include "DataBase15.h"

#define ALREADY_EXISTS 1
#define SUCCESS 2
#define WRONG_DATA_TYPE 3

int change_value(VALUE * Value, TYPE type, char * string)
{
	if (Value == NULL || string == NULL)
		return NULL;
	if (Value->type != type)
	{
		switch (type)
		{
		case INT:  Value->type = INT;  break;
		case FLOAT:  Value->type = FLOAT;  break;
		case DOUBLE:  Value->type = DOUBLE;  break;
		case STRING:  Value->type = CHAR;  break;
		case ALL: break;
		default:
			return WRONG_DATA_TYPE;
			break;
		}
	}
	free(Value->Value);
	Value->Value = (char*)malloc(strlen(string) + 1);
	memmove(Value->Value, string, strlen(string) + 1);
	return SUCCESS;
}
int change_qualifier(NODE * Current, VALUE * Value, char * string)
{
	if (Current == NULL || Value == NULL || string == NULL)
		return NULL;
	if (find_value_in_node(Current, string) != NULL)
		return ALREADY_EXISTS;
	free(Value->Qualifier);
	Value->Qualifier = (char*)malloc(strlen(string) + 1);
	memmove(Value->Qualifier, string, strlen(string) + 1);
	return SUCCESS;
}