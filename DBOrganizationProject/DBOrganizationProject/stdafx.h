#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>

typedef enum TYPE
{
	INT,
	FLOAT,
	DOUBLE,
	CHAR
}TYPE;

typedef struct value
{
	TYPE type;
	char * Value;
	int key;
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

extern NODE* root; //корень базы 
extern int keys;
//прототипы
//удаление узла(from Сергей)
void DeleteFolders(NODE *);
void Delete(NODE *);

//добавление узла в текущую директорию(from Василий)
void InputTree(NODE **);
void Instruction();

//переход по указанному пути(from Кирилл)
void goToFolder(char*);
char** str_split(char*, const char);
void goToPath(char*);

//поиск по названию(from Слава)
NODE* findnode(char*, NODE*);
void way(NODE*);

//выгрузка дерева из файла(from Слава)
NODE* scanfile(FILE*);

//на шаг вверх и распечатать содержимое(from Алина)
void Directory(NODE*);
NODE* UpStep(NODE*);
