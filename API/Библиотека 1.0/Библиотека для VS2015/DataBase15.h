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
NODE* input_tree(NODE *, char *);
//Удаление узла
int delete(NODE**, NODE**);//если удалил,то вернет 1;Нечего удалять --> вернет 0; - избавиться от глоб переменнной
//Поиск узла
NODE* find_node(char*, NODE*);
void way(NODE *);
//Переход по пути
NODE* go_to_path(NODE *, char*);
//Cохранение базы данных
int record_tree(NODE *, FILE *, FILE *);
//Чтение базы данных
NODE* scan_file(FILE*);
//Возвращение на уровень вверх
NODE* up_step(NODE*);
//Изменение названия узла
NODE* change_node_name(NODE *, char *);
//Вывод всех вложенных узлов
void directory(NODE *);
//************************************************************************

//*******************************Значения*********************************

//Добавление значения
VALUE * add_value(NODE *, char *, TYPE, char *);
//Изменение значения
//int change_value(NODE *, VALUE*, TYPE, char*, char*);
int change_qualifier(NODE *, VALUE * , char * );
int change_value(VALUE * , TYPE , char * );
//Копирование значения
//VALUE* copy_paste_value(NODE *, VALUE *, NODE *, int*);
VALUE * copy(VALUE *);
int paste(NODE * , VALUE *);
//Поиск значения
VALUE* find_value_in_node(NODE*, char*);
//Вывод всех значений 
int print_values(NODE *, TYPE);
//Удаление значения
int delete_val(VALUE*, NODE*);
//Удаление всех значений
void delete_all_value(NODE *, TYPE);
//Получение спецификатора по указателю на значение 
char* get_qualifier(VALUE *);
//************************************************************************

//========================================================================

