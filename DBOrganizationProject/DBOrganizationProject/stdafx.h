#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdarg.h>

typedef enum TYPE
{
None,
Int,
Float,
Double,
Bool,
Character
}TYPE;

typedef struct keys
{
// TYPE type = None;
union
{
int Integer;
float Float;
double Double;
bool Bool;
char Character;
}Value;
struct keys* NextKey;
}KEYS;

typedef struct folder
{
char* FolderName;
int level;
struct folder* UpFolder;
struct folder* PreviousFolder;
struct folder* NextFolder;
struct folder* DownFolder;
struct keys * Values;
}FOLDER;

//прототипы
//удаление узла(from Сергей)
//void DeleteFolders(Node *);
//void Delete(Node *);
//добавление узла в текущую директорию(from Василий)
void InputTree(FOLDER **);
void Instruction();
//переход по указанному пути(from Кирилл)
void goToFolder(char*);
char** str_split(char*, const char);
void goToPath(char*);
//поиск по названию(from Слава)
folder* findfolder(char*, folder*);
void way(folder*);
//на шаг вверх и распечатать содержимое(from Алина)
void Directory(FOLDER*);
FOLDER* UpStep(FOLDER*);
