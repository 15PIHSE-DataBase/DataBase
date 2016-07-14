
#include "15PIDataBaseAPI.h"
void RecordRecursion(NODE *, FILE *);
void Record(NODE * CurrentNode, FILE * file)
{
	if (CurrentNode == NULL)
		return;
	NODE * TempNode = CurrentNode;
	VALUE  * value = TempNode->Values;
	//fwrite(&from, sizeof(type), numberOfElements, to);
	//Parent
	size_t counter = strlen(TempNode->NodeName) + 1; // size_t ==== unsigned int
	fwrite(&counter, sizeof(counter), 1, file);
	fwrite(TempNode->NodeName, 1, counter, file);
	fwrite(&TempNode->key, sizeof(int), 1, file);
	counter = 0;
	while (value)
	{
		counter++;
		value = value->NextValue;
	}
	value = TempNode->Values;
	fwrite(&counter, sizeof(int), 1, file);
	for (int i = 0; i < counter; i++)
	{
		size_t length = strlen(value->Qualifier) + 1;
		fwrite(&length, sizeof(int), 1, file);
		fwrite(value->Qualifier, sizeof(char), length, file);
		fwrite(&value->type, sizeof(int), 1, file);
		length = strlen(value->Value) + 1;
		fwrite(&length, sizeof(int), 1, file);
		fwrite(value->Value, sizeof(char), length, file);
		value = value->NextValue;
	}

	if (TempNode->DownNode)
	{
		TempNode = TempNode->DownNode;
		value = TempNode->Values;
	}
	else
		return;
	//Child
	counter = strlen(TempNode->NodeName) + 1;
	fwrite(&counter, sizeof(counter), 1, file);
	fwrite(TempNode->NodeName, 1, counter, file);
	fwrite(&TempNode->key, sizeof(int), 1, file);
	counter = 0;
	while (value)
	{
		counter++;
		value = value->NextValue;
	}
	value = TempNode->Values;
	fwrite(&counter, sizeof(int), 1, file);
	for (int i = 0; i < counter; i++)
	{
		size_t length = strlen(value->Qualifier) + 1;
		fwrite(&length, sizeof(int), 1, file);
		fwrite(value->Qualifier, sizeof(char), length, file);
		fwrite(&value->type, sizeof(int), 1, file);
		length = strlen(value->Value) + 1;
		fwrite(&length, sizeof(int), 1, file);
		fwrite(value->Value, sizeof(char), length, file);
		value = value->NextValue;
	}
	RecordRecursion(TempNode->NextNode, file);
	RecordRecursion(TempNode->DownNode, file);
}
void RecordRecursion(NODE * CurrentNode, FILE * file)
{
	if (CurrentNode == NULL)
		return;
	//Parent key without values(already in file)
	fwrite(&CurrentNode->UpNode->key, sizeof(int), 1, file);
	//New Child
	size_t counter = strlen(CurrentNode->NodeName) + 1; //static?
	fwrite(&counter, sizeof(int), 1, file);
	fwrite(CurrentNode->NodeName, sizeof(char), counter, file);
	fwrite(&CurrentNode->key, sizeof(int), 1, file);
	VALUE *value = CurrentNode->Values;  //static?
	counter = 0;
	while (value)
	{
		counter++;
		value = value->NextValue;
	}
	value = CurrentNode->Values;
	fwrite(&counter, sizeof(int), 1, file);
	for (int i = 0; i < counter; i++)
	{
		size_t length = strlen(value->Qualifier) + 1;
		fwrite(&length, sizeof(int), 1, file);
		fwrite(value->Qualifier, sizeof(char), length, file);
		fwrite(&value->type, sizeof(int), 1, file);
		length = strlen(value->Value) + 1;
		fwrite(&length, sizeof(int), 1, file);
		fwrite(value->Value, sizeof(char), length, file);
		value = value->NextValue;
	}
	RecordRecursion(CurrentNode->NextNode, file);
	RecordRecursion(CurrentNode->DownNode, file);
}