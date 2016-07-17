
#include "DataBase13.h"

char* GetQualifier(VALUE * pointer)
{
	if (pointer)
	{
		char *TempString = (char*)malloc(strlen(pointer->Qualifier) + 1);
		strcpy(TempString, pointer->Qualifier);
		return TempString;
	}
	else return NULL; //указатель пуст
}