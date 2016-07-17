#pragma once

//==============================Структура=================================
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>

typedef enum TYPE
{
	ALL,
	INT,
	FLOAT,
	DOUBLE,
	CHAR
}TYPE;

typedef struct VALUE
{
	TYPE type;
	char * Value;
	char * Qualifier;
	struct VALUE * NextValue;
}VALUE;

typedef struct NODE
{
	char NodeName[255];
	int key;
	struct NODE* UpNode;
	struct NODE* PreviousNode;
	struct NODE* NextNode;
	struct NODE* DownNode;
	struct VALUE * Values;
}NODE;
//========================================================================

//============================Переменные==================================
extern NODE* root; //корень базы 
extern int keys;
//========================================================================

//============================Прототипы===================================

//*******************************Узлы*************************************

//Добавление узла
NODE* InputTree(NODE *, char *);
//Удаление узла
int Delete(NODE**, NODE**);//если удалил,то вернет 1;Нечего удалять --> вернет 0; - избавиться от глоб переменнной
//Поиск узла
NODE* findnode(char*, NODE*);
void way(NODE *);
//Переход по пути
NODE* goToPath(NODE *, char*);
//Сохранение базы данных
void Record(NODE *, FILE * );
//Чтение базы данных
NODE* scanfile(FILE*);
//Возвращение на уровень вверх
NODE* UpStep(NODE*);
//Изменение названия узла
NODE* ChangeNodeName(NODE *, char *);
//Вывод всех вложенных узлов
void Directory(NODE *);
//Вывод всех путей
int PathList(NODE *);
//************************************************************************

//*******************************Значения*********************************

//Добавление значения
VALUE * AddValue(NODE *, char *, TYPE, char *);
//Изменение значения
int ChangeValue(NODE *, VALUE*, TYPE, char*, char*);
//Копирование значения
VALUE* CopyPasteValue(NODE *, VALUE *, NODE *, int*);
//Поиск значения
VALUE* findValueInNode(NODE*, char*);
//Вывод всех значений 
int PrintValues(NODE *, TYPE);
//Удаление значения
int deleteVal(VALUE*, NODE*);
//Удаление всех значений
void DeleteAllValue(NODE *, TYPE);
//Получение спецификатора по указателю на значение 
char* GetQualifier(VALUE *);
//************************************************************************

//========================================================================

