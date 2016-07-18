//Функция получения по указателю специфкатора значения 
//В случае успеха возвращает указатель на строку-спецификатор, иначе - NULL
//VALUE * pointer - указатель на значение
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