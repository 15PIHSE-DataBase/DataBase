
#include "DataBase15.h"

char* get_qualifier(VALUE * pointer)
{
	if (pointer)
	{
		char *TempString = (char*)malloc(strlen(pointer->Qualifier) + 1);
		strcpy(TempString, pointer->Qualifier);
		return TempString;
	}
	else return NULL; //указатель пуст
}