#pragma once

void Delete(FOLDER*); //+ удаление

FOLDER * DeleteFolders(FOLDER*);

void Record(FOLDER*, FILE*); //+ сохранение

void InputTree(FOLDER **); //+ создание

void Instruction(); //?

struct folder* scanfile(FILE*); //+ загрузка

folder* findfolder(char* findname, folder* beginf); //тоже поиск

void way(folder*); //+ поиск
