#include "DataBase15.h"

fpos_t get_new_values_position(FILE * );
fpos_t get_new_nodes_position(FILE * );
void record_values(NODE * , FILE * , fpos_t );
void record_nodes(NODE * , FILE * , FILE* );
void recursion(NODE * , FILE * , FILE * );

#define FILE_ERROR 2
#define EMPTY_FILE 1

int record_tree(NODE * CurrentNode, FILE * FileWithNodes, FILE * FileWithValues)
{
	if (CurrentNode == NULL)
		return NULL;
	if (FileWithNodes == NULL || FileWithValues == NULL)
		return FILE_ERROR;
	NODE * TempNode = CurrentNode->DownNode;
	record_nodes(CurrentNode, FileWithNodes, FileWithValues);
	record_nodes(CurrentNode->DownNode, FileWithNodes, FileWithValues);
	if (TempNode)
	{
		recursion(TempNode->NextNode, FileWithNodes, FileWithValues);
		recursion(TempNode->DownNode, FileWithNodes, FileWithValues);
	}
}
void recursion(NODE * CurrentNode, FILE * FileWithNodes, FILE * FileWithValues)
{
	if (CurrentNode == NULL)
		return;
	fwrite(&CurrentNode->UpNode->key, sizeof(int), 1, FileWithNodes);
	record_nodes(CurrentNode, FileWithNodes, FileWithValues);
	recursion(CurrentNode->NextNode, FileWithNodes, FileWithValues);
	recursion(CurrentNode->DownNode, FileWithNodes, FileWithValues);
}

void record_nodes(NODE * CurrentNode, FILE * FileWithNodes, FILE* FileWithValues)
{
	if (CurrentNode == NULL)
		return;
	bool check = 0;
	NODE* TempNode = CurrentNode;
	fpos_t ValuesPosition = get_new_values_position(FileWithValues);
	record_values(CurrentNode, FileWithValues, ValuesPosition);
	fwrite(&check, sizeof(bool), 1, FileWithNodes);
	fwrite(&TempNode->key, sizeof(int), 1, FileWithNodes);
	fwrite(TempNode->NodeName, sizeof(char), 255, FileWithNodes);
	fwrite(&ValuesPosition, sizeof(fpos_t), 1, FileWithNodes);
	ValuesPosition = get_new_nodes_position(FileWithNodes);
	fwrite(&ValuesPosition, sizeof(fpos_t), 1, FileWithNodes);
}
void record_values(NODE * CurrentNode, FILE * FileWithValues, fpos_t FilePosition)
{
	fseek(FileWithValues, FilePosition, SEEK_SET);
	unsigned count = 0;
	unsigned length = 0;
	VALUE * TempValues = CurrentNode->Values;
	while (TempValues)
	{
		count++;
		TempValues = TempValues->NextValue;
	}
	TempValues = CurrentNode->Values;
	fwrite(&count, sizeof(unsigned), 1, FileWithValues);
	for (int i = 0; i < count; i++)
	{
		length = strlen(TempValues->Qualifier) + 1;
		fwrite(&length, sizeof(unsigned), 1, FileWithValues);
		fwrite(TempValues->Qualifier, sizeof(char), length, FileWithValues);
		length = strlen(TempValues->Value) + 1;
		fwrite(&length, sizeof(unsigned), 1, FileWithValues);
		fwrite(TempValues->Value, sizeof(char), length, FileWithValues);
		fwrite(&TempValues->type, sizeof(TYPE), 1, FileWithValues);
		TempValues = TempValues->NextValue;
	}
	fpos_t NewValues = 0;
	fwrite(&NewValues, sizeof(fpos_t), 1, FileWithValues);
}

fpos_t get_new_nodes_position(FILE * FileWithNodes)
{
	fpos_t BytesNumber;
	fseek(FileWithNodes, 0, SEEK_END);
	BytesNumber = ftell(FileWithNodes);
	return BytesNumber;
}

fpos_t get_new_values_position(FILE * FileWithValues)
{
	fpos_t BytesNumber;
	fseek(FileWithValues, 0, SEEK_END);
	BytesNumber = ftell(FileWithValues);
	return BytesNumber;
}