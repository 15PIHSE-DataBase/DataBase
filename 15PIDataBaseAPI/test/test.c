// TESTPROJ.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DataBase15.h"

void help();
//void startUp();
void call_new_node();
void call_delete_node();
void call_path();
void call_print_node();
void call_change_node_name();
void call_save_db();
void  call_exit();

void call_new_val();
void call_change_val();
void call_copy();
void call_paste();
void call_print_val();
void call_delete_val();
void call_delete_all_val();
void call_create_new();
void call_load();

NODE* root = NULL;
VALUE* COPY = NULL;

int main()
{
	while (1) {
		help();
	}
}



void help() {
	system("cls");
	call_path();
	printf("\n press: \n 0 - to quit \n 1 - to see node functions \n 2 - to see info functions\n 3 - Load DataBase\n 4 - Save DataBase\n");
	int choice1;
	char buf[2];
	int c;
	gets_s(buf, 2);
	sscanf(buf, "%d", &choice1);
	fflush(stdin);
	while ((choice1 != 1) && (choice1 != 2) && (choice1 != 0) && (choice1 != 3) && (choice1 != 4))
	{
		printf("\n");
		printf("Incorrect Choice\n");
		gets_s(buf, 2);
		sscanf(buf, "%d", &choice1);
		fflush(stdin);
	}
	switch (choice1)
	{
	case 0:
		call_exit();
		break;
	case 1:
		system("cls");
		int c;
		call_path();
		printf(" 0 - back\n 1 - new node \n 2 - delete node \n 3 - print tree \n 4 - print all sub nodes \n 5 - change node name \n");
		gets_s(buf, 2);
		sscanf(buf, "%d", &c);
		fflush(stdin);
		switch (c) {
		case 0: break;
		case 1: call_new_node(); break;
		case 2: call_delete_node(); break;
		case 3: call_path(); break;
		case 4: call_print_node(); break;
		case 5: call_change_node_name(); break;
		default: printf("Invalid input\n"); help(); break;
		}
		break;
	case 2:
		system("cls");
		call_path();
		printf(" 0 - back\n 1 - add information\n 2 - change information\n 3 - copy information\n 4 - paste information\n"
			" 5 - print infromation in node\n 6 - delete infromation\n 7 - delete all information(all/by type) \n");
		gets_s(buf, 2);
		sscanf(buf, "%d", &c);
		fflush(stdin);
		switch (c) {
		case 0: break;
		case 1: call_new_val(); break;
		case 2: call_change_val(); break;
		case 3: call_copy(); break;
		case 4: call_paste(); break;
		case 5: call_print_val(); break;
		case 6: call_delete_val(); break;
		case 7: call_delete_all_val(); break;
		default: printf("Invalid input\n"); help(); break;
		}
		break;
	case 3:
		call_load();
		break;
	case 4:
		call_save_db();
		break;
	}
}

void call_new_node() {
	if (root == NULL)
	{
		call_create_new();
		return;
	}
	NODE* curNode;
	char buf1[255];
	char buf2[255];
	system("cls");
	call_path();
	printf("\ntype in path to the node in which you want to place the new node>>\n");
	gets_s(buf2, 254);
	fflush(stdin);
	NODE* f = go_to_path(root, buf2);
	if (f == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}
	printf("\ntype in the name for a new node>>\n");
	gets_s(buf1, 254);
	fflush(stdin);
	curNode = input_tree(f, buf1);
}

void call_delete_node() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}
	char buf1[255];
	system("cls");
	call_path();
	printf("\ntype in path to the node you want to delete>>\n");
	gets_s(buf1, 254);
	fflush(stdin);
	NODE* f = go_to_path(root, buf1);
	if (f == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}
	int lala = delete_node(&f, &root);
}
void call_path() {

	if (path_list(root) == 0)
		printf("DataBase is empty\n");
	
}

void call_print_node() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
	}
	else {
		char buf1[255];
		system("cls");
		call_path();
		printf("\ntype in path to the node you want to print>>\n");
		gets_s(buf1, 254);
		fflush(stdin);
		NODE* f = go_to_path(root, buf1);
		if (f == NULL)
		{
			printf("Invalid path\n");
			getch();
			return;
		}
		directory(f);
	}
}

void call_change_node_name() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}
	char buf1[255];
	char buf2[255];
	system("cls");
	call_path();
	printf("\ntype in path to the node you want to change name for>>\n");
	gets_s(buf1, 254);
	fflush(stdin);
	NODE* f = go_to_path(root, buf1);
	if (f == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}
	printf("\ntype in the new name for the node>>\n");
	gets_s(buf2, 254);
	fflush(stdin);

	change_node_name(f, buf2);
}

void call_save_db() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}
	FILE* pfile;
	FILE * pfile2;
	char buf1[255];
	system("cls");
	do
	{
		printf("\ntype in body file>>\n");
		gets_s(buf1, 254);
		fflush(stdin);
		pfile = fopen(buf1, "wb+");
		if (pfile == NULL)
			printf("Can't open %s\n", buf1);
	} while (pfile == NULL);
	do
	{
		printf("\ntype in data file>>\n");
		gets_s(buf1, 254);
		fflush(stdin);
		pfile2 = fopen(buf1, "wb+");
		if (pfile2 == NULL)
			printf("Can't open %s\n", buf1);
	} while (pfile == NULL);
	record_tree(root, pfile, pfile2);
	fclose(pfile);
	fclose(pfile2);
	printf("DB saved\n");
}

void  call_exit() {
	
	printf("\n Would you like to save you db? 1 - yes, 2 - no \n");
	int choice1;
	char buf[2];
	gets_s(buf, 2);
	sscanf(buf, "%d", &choice1);
	fflush(stdin);
	if (choice1 == 1) {
		call_save_db();
	}
	printf("\nEXIT\n");
	exit(0);
}

void call_new_val() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}
	char buf1[255];
	char buf2[255];
	char buf3[255];
	char buf[2];
	TYPE type1;
	int a;

	system("cls");
	call_path();
	printf("\ntype in path to the node to add info to>>\n");
	gets_s(buf3, 254);
	fflush(stdin);
	NODE* f = go_to_path(root, buf3);
	if (f == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}
	printf("\ntype in info field>>\n");
	gets_s(buf1, 254);
	fflush(stdin);

	printf("\ntype in the type of information (1 - int, 2 - float, 3 - double, 4 - string)>>");
	gets_s(buf, 2);
	sscanf(buf, "%d", &a);
	fflush(stdin);

	switch (a) {
	case 1:type1 = INT; break;
	case 2:type1 = FLOAT; break;
	case 3:type1 = DOUBLE; break;
	case 4:type1 = CHAR; break;
	default:
		printf("Invalid type\n");
		getch();
		return;
	}


	printf("\ntype in info>>\n");
	gets_s(buf2, 254);
	fflush(stdin);
	add_value(f, buf1, type1, buf2);

}

void call_change_val() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}
	int lala = 0;

	VALUE* newVal = NULL;
	char buf1[255];
	char buf2[255];
	char buf3[255];
	char buf4[255];
	char buf[2];
	TYPE type1;
	int a;
	system("cls");
	call_path();
	printf("\ntype in path to the node where the information is stored>>\n");
	gets_s(buf3, 254);
	fflush(stdin);
	NODE* f = go_to_path(root, buf3);
	if (f == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}
	print_values(f, ALL);

	printf("\ntype in info field you want to change>>\n");
	gets_s(buf4, 254);
	fflush(stdin);


	newVal = find_value_in_node(f, buf4);
	if (newVal == NULL)
	{
		printf("Not found\n");
		getch();
		return;
	}

	printf("\ndo you want to change info field ? 1 - yes, 2 - no\n");
	gets_s(buf, 2);
	sscanf(buf, "%d", &a);
	fflush(stdin);
	if (a == 1) {
		printf("\n type in new info field \n");
		gets_s(buf1, 254);
		fflush(stdin);
		while (change_qualifier(f, newVal, buf1) == 1)
		{
			printf("Such field already exists.Type in new info field>>\n");
			gets_s(buf1, 254);
			fflush(stdin);
		}
	}


	printf("\ntype in new information type  1 - int, 2 - float, 3 - double, 4 - string\n");
	gets_s(buf, 2);
	sscanf(buf, "%d", &a);
	fflush(stdin);

	switch (a) {
	case 1:type1 = INT; break;
	case 2:type1 = FLOAT; break;
	case 3:type1 = DOUBLE; break;
	case 4:type1 = CHAR; break;
	default:
		printf("Invalid type\n");
		getch();
		return;

	}

	printf("\ntype in new information>>\n");
	gets_s(buf2, 254);

	change_value(newVal, type1, buf2);

}

void  call_copy() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}
	char buf1[255];
	char buf3[255];

	printf("\ntype in path to the node where the information is stored>>\n");
	gets_s(buf1, 254);
	fflush(stdin);

	NODE* from = go_to_path(root, buf1);
	if (from == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}
	printf("\ntype in info field to copy>>\n");
	print_values(from, ALL);
	gets_s(buf3, 254);
	fflush(stdin);
	if (print_values(from, ALL) == 0) {
		getch();
		return;
	}
	VALUE* v = find_value_in_node(from, buf3);

	if (v == NULL)
	{
		printf("Such field doesnt exist\n");
		getch();
	}
	if (COPY != NULL)
	{
		free(COPY->Qualifier);
		free(COPY->Value);
		free(COPY);
	}
	COPY = copy(v);
}
void call_paste()
{
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}
	char buf2[255];
	printf("\ntype in path to the node where the copy should be moved>>\n");
	gets_s(buf2, 254);
	fflush(stdin);
	NODE* to = go_to_path(root, buf2);
	if (paste(to, COPY) == 1)
		printf("Such field already exists\n");
}


void call_print_val() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}
	int lala, a;
	TYPE type1;
	char buf1[255];
	char buf2[255];
	char buf[2];
	system("cls");
	call_path();
	printf("\ntype in path to the node, which you want to print>>\n");
	gets_s(buf1, 254);
	fflush(stdin);
	strcpy(buf2, buf1);
	NODE* f = go_to_path(root, buf1);
	if (f == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}

	printf("\n type in information you want to print 1 - int, 2 - float, 3 - double, 4 - string, 5 - ALL\n");
	gets_s(buf, 2);
	sscanf(buf, "%d", &a);
	fflush(stdin);

	switch (a) {
	case 1:type1 = INT; break;
	case 2:type1 = FLOAT; break;
	case 3:type1 = DOUBLE; break;
	case 4:type1 = CHAR; break;
	case 5:type1 = ALL; break;
	default:
		printf("Invalid type\n");
		getch();
		return;
	}
	printf("\n%s>>\n", buf2);
	lala = print_values(f, type1);
}

void call_delete_val() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}

	int lala;

	char buf1[255];
	char buf2[255];
	system("cls");
	call_path();
	printf("\ntype in path to the node, from which you want to delete>>\n");
	gets_s(buf1, 254);
	fflush(stdin);
	NODE* f = go_to_path(root, buf1);
	if (f == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}

	if (print_values(f, ALL) == 0)
		getch();
		return;
	printf("\ntype in info field, which you want to delete>>\n");
	print_values(f, ALL);

	gets_s(buf2, 254);
	fflush(stdin);
	VALUE* v = find_value_in_node(f, buf2);
	if (v == NULL)
	{
		printf("Such filed doesnt exist\n");
		getch();
		return;
	}

	lala = delete_val(v, f);
}

void call_delete_all_val() {
	if (root == NULL)
	{
		printf("DataBase is empty\n");
		getch();
		return;
	}

	int a;
	TYPE type1;
	char buf1[255];
	char buf[2];

	printf("\ntype in path to the node, from which you want to delete>>\n");
	gets_s(buf1, 254);
	NODE* f = go_to_path(root, buf1);
	if (f == NULL)
	{
		printf("Invalid path\n");
		getch();
		return;
	}

	printf("\ntype in the type of variables you want to delete 1 - int, 2 - float, 3 - double, 4 - string, 5 - ALL\n");
	gets_s(buf, 2);
	sscanf(buf, "%d", &a);
	fflush(stdin);

	switch (a) {
	case 1:type1 = INT; break;
	case 2:type1 = FLOAT; break;
	case 3:type1 = DOUBLE; break;
	case 4:type1 = CHAR; break;
	case 5:type1 = ALL; break;
	}

	delete_all_value(f, type1);
}
void call_create_new() {
	char buf[255];
	system("cls");
	printf("\ntype in the name for a new node>>\n");
	gets_s(buf, 254);
	fflush(stdin);
	root = input_tree(NULL, buf);
}
void call_load() {
	if (root)
	{
		char buf[2];
		int choice;
		printf("\nwould you like to save your current database? 1-yes, 2-no\n");
		gets_s(buf, 2);
		sscanf(buf, "%d", &choice);
		fflush(stdin);
		if (choice == 1)
			call_save_db();
		delete_node(&root, &root);
	}
	FILE* pfile;
	FILE* pfile2;
	char buf[255];
	system("cls");
	printf("\ntype in body file>>\n");
	gets_s(buf, 254);
	fflush(stdin);
	pfile = fopen(buf, "rb");
	if (pfile == NULL)
	{
		printf("cant open %s\n", buf);
		getch();
		return;
	}
	printf("\ntype in data file>>\n");
	gets_s(buf, 254);
	fflush(stdin);
	pfile2 = fopen(buf, "rb");
	if (pfile2 == NULL)
	{
		fclose(pfile);
		printf("Cant open %s\n", buf);
		getch();
		return;
	}
	root = scan_file(pfile, pfile2);
	fclose(pfile);
	fclose(pfile2);
	if (root == NULL)
		printf("File is empty\n");
}














