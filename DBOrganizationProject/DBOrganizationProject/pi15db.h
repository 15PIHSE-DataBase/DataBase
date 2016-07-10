#pragma once
#include "stdafx.h"

FOLDER* InputTree(FOLDER **currPtr, char *newname); //добавление новой папки

void goToPath(char*); //проход по папкам, выделенным из пути, аргументы: путь

void goToFolder(char*); //переход в папку, на вход подаем название папки, в которую нужно зайти

FOLDER* DeleteFolders(Node);// Удаление содержимого текущей папки

FOLDER Delete(FOLDER*);//Удаление самой папки

struct folder* findfolder(char*, struct folder*); //поиск папки

struct folder* scanfile(FILE*); //загрузка базы из файла

