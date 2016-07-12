#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>


typedef enum TYPE
{
	ALL,
	INT,
	FLOAT,
	DOUBLE,
	CHAR
}TYPE;

typedef struct value
{
	TYPE type;
	char * Value;
	char * Qualifier;
	struct value* NextValue;
}VALUE;

typedef struct node
{
	char NodeName[255];
	int key;
	struct node * UpNode;
	struct node * PreviousNode;
	struct node * NextNode;
	struct node * DownNode;
	struct value * Values;
}NODE;



//прототипы
//удаление узла(from Сергей)
//void DeleteFolders(Node *);
//void Delete(Node *);
//добавление узла в текущую директорию(from Василий)
NODE* InputTree(NODE**, char*);
char* GetName(NODE **);
void Instruction();
//переход по указанному пути(from Кирилл)
void goToFolder(char*);
char** str_split(char*, const char);
void goToPath(char*);
//поиск по названию(from Слава)
//FOLDER* findfolder(char*, FOLDER*);
//void way(FOLDER*);
//на шаг вверх и распечатать содержимое(from Алина)
//void Directory(FOLDER*);
//FOLDER* UpStep(FOLDER*);

int gen_newkey();
void Directory(NODE *CurrentF);
NODE* AddValue(NODE *CurrentPtr, char *Qualf, TYPE Type, char * Info);
int PrintValues(NODE *head, TYPE Type);
int deleteVal(VALUE* toDelete, NODE* start);

