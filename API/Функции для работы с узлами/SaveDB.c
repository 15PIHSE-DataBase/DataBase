fpos_t GetNewValuesPosition(FILE * );
fpos_t GetNewNodesPosition(FILE * );
void RecordValues(NODE * , FILE * , fpos_t );
void RecordNodes(NODE * , FILE * , FILE* );
void Recursion(NODE * , FILE * , FILE * );
int RecordTree(NODE *, FILE *, FILE *);

#define FILE_ERROR 3
#define EMPTY_FILE 2
#define NOT_FOUND 1
#define FOUND 0
#define NODE_NULL -1

int RecordTree(NODE * CurrentNode, FILE * FileWithNodes, FILE * FileWithValues)
{
	if (CurrentNode == NULL)
		return NODE_NULL;
	if (FileWithNodes == NULL || FileWithValues == NULL)
		return FILE_ERROR;
	NODE * TempNode = CurrentNode->DownNode;
	RecordNodes(CurrentNode, FileWithNodes, FileWithValues);
	RecordNodes(CurrentNode->DownNode, FileWithNodes, FileWithValues);
	if (TempNode)
	{
		Recursion(TempNode->NextNode, FileWithNodes, FileWithValues);
		Recursion(TempNode->DownNode, FileWithNodes, FileWithValues);
	}
}
void Recursion(NODE * CurrentNode, FILE * FileWithNodes, FILE * FileWithValues)
{
	if (CurrentNode == NULL)
		return;
	fwrite(&CurrentNode->UpNode->key, sizeof(int), 1, FileWithNodes);
	RecordNodes(CurrentNode, FileWithNodes, FileWithValues);
	Recursion(CurrentNode->NextNode, FileWithNodes, FileWithValues);
	Recursion(CurrentNode->DownNode, FileWithNodes, FileWithValues);
}

void RecordNodes(NODE * CurrentNode, FILE * FileWithNodes, FILE* FileWithValues)
{
	if (CurrentNode == NULL)
		return;
	bool check = 0;
	NODE* TempNode = CurrentNode;
	fpos_t ValuesPosition = GetNewValuesPosition(FileWithValues);
	RecordValues(CurrentNode, FileWithValues, ValuesPosition);
	fwrite(&check, sizeof(bool), 1, FileWithNodes);
	fwrite(&TempNode->key, sizeof(int), 1, FileWithNodes);
	fwrite(TempNode->NodeName, sizeof(char), 255, FileWithNodes);
	fwrite(&ValuesPosition, sizeof(fpos_t), 1, FileWithNodes);
	ValuesPosition = GetNewNodesPosition(FileWithNodes);
	fwrite(&ValuesPosition, sizeof(fpos_t), 1, FileWithNodes);
}
void RecordValues(NODE * CurrentNode, FILE * FileWithValues, fpos_t FilePosition)
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

fpos_t GetNewNodesPosition(FILE * FileWithNodes)
{
	fpos_t BytesNumber;
	fseek(FileWithNodes, 0, SEEK_END);
	BytesNumber = ftell(FileWithNodes);
	return BytesNumber;
}

fpos_t GetNewValuesPosition(FILE * FileWithValues)
{
	fpos_t BytesNumber;
	fseek(FileWithValues, 0, SEEK_END);
	BytesNumber = ftell(FileWithValues);
	return BytesNumber;
}