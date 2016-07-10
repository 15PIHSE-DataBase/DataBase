#pragma once

void Delete(FOLDER*); //+ удаление

FOLDER * DeleteFolders(FOLDER*);

void Record(FOLDER*, FILE*); //+ сохранение

FOLDER* InputTree(FOLDER**, char*); //+ создание

struct folder* scanfile(FILE*); //+ загрузка

folder* findfolder(char* findname, folder* beginf); //тоже поиск

void way(folder*); //+ поиск
