#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdarg.h>

typedef struct filet
{
	//enum!!!
	char* FileName;
	void* Parametr;
	filet * NextFile;
}FILET;

typedef struct folder
{
	char* FolderName;
	folder * UpFolder;
	folder * PreviousFolder;
	folder * NextFolder;
	folder * DownFolder;
	filet* File;
}FOLDER;

//прототипы
//удаление узла(from Сергей)
void DeleteFolders(Node *);
void Delete(Node *);
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
