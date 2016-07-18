#include"stdafx.h"
#include"DataBase13.h"

//прототипы
void check_func(NODE * ptr);
void build_tree(NODE ** root);
void full_tree(NODE * begin);
void find_error(NODE * CurNode, char * ExprectedName);
void error_search_insert_node(char *NewName, NODE *CurPtr, NODE *funct(NODE*, char*));
void error_search_change_node_name(char *NewName, char*FindName, NODE *CurPtr, NODE *funct(NODE*, char*));
void error_search_delete_node(char *Name, NODE * MainRoot);
void print_line(void);

void find_error_in_values(VALUE * Current, char * ExpectedValue, char*ExpectedQualifier, TYPE ExpectedType);
void error_search_add_value(NODE * node);
void error_search_find_delete_value(NODE * node);
void error_search_delete_all_values(NODE * node);