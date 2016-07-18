#include "stdafx.h"
#include "DataBase15.h"

void help();
void start_up();
void call_new_node();
 void call_delete_node();
 void call_path(); 
 void call_print_node(); 
 void call_change_node_name();
 void call_save_db(); 
void  call_exit(); 

void call_new_value();
void call_change_val(); 
void  call_copy(); 
void call_get_name_val();
void call_print_val();
void call_delete_val(); 
void call_delete_all_val(); 
void call_create_new();
void call_load();

NODE* root = NULL;

int main()
{
	system("cls");

	startUp();
	while (1) {
		help();
	}
}



	/*NODE* root = NULL;
	int o = 1;
	int lala;
	//int a = 1; 
	char p[10] = "Ves";
	char p1[10] = "100";
	char p2[10] = "Rost";
	char p3[10] = "101";
	char p4[10] = "Dlina";
	char p5[10] = "94";
	root = InputTree(NULL, "root");
	Directory(root);
	InputTree(root, "35");
	Directory(root);
	InputTree(root, "34");
	InputTree(root, "36");
	Directory(root);
	PrintValues(root->DownNode->NextNode, ALL);
	AddValue(root, p, INT, p1);
	AddValue(root, p2, CHAR, p3);
	AddValue(root, p4, CHAR, p5);
	AddValue(root, p5, INT, p3);
	PrintValues(root, ALL);
	lala = deleteVal(root->Values, root);
	//DeleteAllValue(root, INT); 
	PrintValues(root, ALL);
	//ChangeValue(root, root->Values, INT, p3, p4); 
	//PrintValues(root, ALL); 
	//ChangeValue(root, root->Values->NextValue, 7, p3, p5); 
	PrintValues(root, ALL);
	//CopyPasteValue(root, root->Values, root->DownNode->NextNode, &o);
	//deleteVal(root->Values, root); 
	PrintValues(root->DownNode, ALL);
	PrintValues(root, ALL);
	InputTree(root->DownNode, "46");
	Directory(root->DownNode);
	lala = Delete(&(root->DownNode->NextNode), &root);
	Directory(root);
	_getch();
}*/

void help() {
	system("cls");
	printf("\n press: \n n - to see node functions \n v - to see value functions\n");
	char choice1;
	scanf("%c", &choice1);
	while ((choice1 != 'V') && (choice1 != 'v') && (choice1 != 'N') && (choice1 != 'n')) // If invalid choice entered
	{
		printf("\n");
		printf("Incorrect Choice.\n");
		scanf("%c", &choice1);
	}
	if (choice1 == 'n' || choice1 == 'N') {
		system("cls");
		int c;
		printf("\n 1 - new node \n 2 - delete node \n 3 - print all sub nodes \n 4 - change node name \n 5 - save DB \n 6 - exit \n");
		scanf("%d", &c);
		switch (c) {
		case 1: callNewNode(); break;
		case 2: callDeleteNode(); break;
	//	case 3: callPath(); break;
		case 3: callPrintNode(); break;
		case 4: callChangeNodeName(); break;
		case 5: callSaveDB(); break;
		case 6: callExit(); break;
		default: printf("error"); help(); break;
		}
	}
	else if (choice1 == 'v' || choice1 == 'V') {
		system("cls");
		int c;
		printf("\n 1 - add value \n 2 - change value \n 3 - copy value \n 4 - print values in node \n 5 - delete a value \n 6 - delete all values \n 7 - exit \n");
		scanf("%d", &c);
		switch (c) {
		case 1: call_new_value(); break;
		case 2: call_change_val(); break;
		case 3: call_copy(); break;
		//case 4: call_get_name_val(); break;
		case 4: call_print_val(); break;
		case 5: call_delete_val(); break;
		case 6: call_delete_all_val(); break;
		case 7: call_exit(); break;
		default: printf("error"); help(); break;
		}
	}
	getch();
}

void start_up() {
	printf("\n Welcome to 15PI Data Base \n Would you like to load a DataBase? \n Press y for YES, n for NO \n");
	char choice;
	scanf("%c", &choice);
	while ((choice != 'Y') && (choice != 'y') && (choice != 'N') && (choice != 'n')) // If invalid choice entered
	{
		printf("\n");
		printf("Incorrect Choice. Please Enter Y for Yes or N for No.\n");
		scanf("%c", &choice);
	}
	if (choice == 'y' || choice == 'Y') {
		system("cls");
		call_load();
		printf("DB loaded\n");
		getch();
	}
	else if (choice == 'n' || choice == 'N') {
		system("cls");
		call_create_new();
		printf("new DB is created\n");
		getch();
	}
}

void call_new_node() {
	NODE* curNode;
	char buf1[255];
	char buf2[255];
	system("cls");
	printf("\n type in the name for a new node \n");
	scanf("%s", &buf1);
	printf("\n type in the node in which you want to place the new node \n");
	scanf("%s", &buf2);
	NODE* f = find_node(buf2, root);
	curNode = input_tree(f, buf1);
	
}

void call_delete_node() {
	NODE* curNode;
	char buf1[255];
	system("cls");
	printf("\n type in the name of the node you want to delete \n");
	scanf("%s", &buf1);
	NODE* f = find_node(buf1, root);
	int lala = delete(&f, &root);
}

void call_path() {
	printf("3");
	//Возможно это лишняя функция
}

void call_print_node() {
	
	char buf1[255];
	system("cls");
	printf("\n type in the name of the node you want to print \n");
	scanf("%s", &buf1);
	NODE* f = find_node(buf1, root);
	directory(f);
}

void call_change_node_name() {
	NODE* curNode;
	char buf1[255];
	char buf2[255];
	system("cls");
	printf("\n type in the name of the node you want to change name for \n");
	scanf("%s", &buf1);
	printf("\n type in the new name for the node \n");
	scanf("%s", &buf2);
	NODE* f = find_node(buf1, root);
	change_node_name(f, buf2);
}

void call_save_db() {
	NODE* curNode;
	FILE* pfile;
	char buf1[255];
	system("cls");
	printf("\n type in the name of the file \n");
	scanf("%s", &buf1);
	pfile = fopen(buf1, "w");
	record_tree(root, pfile);
	fclose(pfile);
}

void  call_exit() {
	printf("\nEXIT\n");
	getch();
	exit(0);
}

void call_new_value() {
	VALUE* newVal = NULL;
	char buf1[255];
	char buf2[255];
	char buf3[255];
	TYPE type1;
	int a;
	printf("\n type in the name for the value \n");
	scanf("%s", &buf1);

	printf("\n type in the type of variable 1 - int, 2 - float, 3 - double, 4 - char\n");
	scanf("%d", &a);

	switch (a) {
	case 1:type1 = INT; break;
	case 2:type1 = FLOAT; break;
	case 3:type1 = DOUBLE; break;
	case 4:type1 = CHAR; break;
	}

	printf("\n type in the value itself\n");
	scanf("%s", &buf2);

	printf("\n type in the node to add value to \n");
	scanf("%s", &buf3);

	NODE* f = find_node(buf3, root);

	add_value(f, buf1, type1, buf2);
	
}

void call_change_val() {
	int lala;

	VALUE* newVal = NULL;
	char buf1[255];
	char buf2[255];
	char buf3[255];
	char buf4[255];
	TYPE type1;
	int a;

	printf("\n type in the name of the value you want to change\n");
	scanf("%s", &buf4);

	printf("\n type in the node where the value is stored \n");
	scanf("%s", &buf3);

	NODE* f = find_node(buf3, root);
	newVal = find_value_in_node(f, buf4);

	printf("\n do you want to change the name of the variable? 1 - yes, 2 - no\n");
	scanf("%d", &a);
	if (a == 1) {
		printf("\n type in the new name for the value \n");
		scanf("%s", &buf1);
		change_qualifier(f, newVal, buf1);
	}
	

		printf("\n type in the new type of variable 1 - int, 2 - float, 3 - double, 4 - char\n");
		scanf("%d", &a);

		switch (a) {
		case 1:type1 = INT; break;
		case 2:type1 = FLOAT; break;
		case 3:type1 = DOUBLE; break;
		case 4:type1 = CHAR; break;
		}

		printf("\n type in the new value itself\n");
		scanf("%s", &buf2);

		change_value(newVal, type1, buf2);
	
}

void  call_copy() {
	char buf1[255];
	char buf2[255];
	char buf3[255];
	
	int lala;

	printf("\n type in the node where the value is stored \n");
	scanf("%s", &buf1);

	printf("\n type in the node where the value should be moved \n");
	scanf("%s", &buf2);

	printf("\n type in the name of the value \n");
	scanf("%s", &buf3);


	NODE* from = find_node(buf1, root);
	NODE* to = find_node(buf2, root);
	VALUE* v = find_value_in_node(from, buf3);
	VALUE* copied;
	copied = copy(v);
	lala = paste(to, copied);
	
}

void call_get_name_val() {
	printf("4");
	//lлишняя функция
}

void call_print_val() {
	int lala, a;
	TYPE type1;
	char buf1[255];

	printf("\n type in the node, which you want to print \n");
	scanf("%s", &buf1);

	printf("\n type in the type of variables you want to print 1 - int, 2 - float, 3 - double, 4 - char, 5 - ALL\n");
	scanf("%d", &a);

	switch (a) {
	case 1:type1 = INT; break;
	case 2:type1 = FLOAT; break;
	case 3:type1 = DOUBLE; break;
	case 4:type1 = CHAR; break;
	case 5:type1 = ALL; break;
	}

	NODE* f = find_node(buf1, root);

	lala = print_values(f, type1);
}

void call_delete_val() {

	int lala;

	char buf1[255];
	char buf2[255];

	printf("\n type in the node, from which you want to delete \n");
	scanf("%s", &buf1);
	
	NODE* f = findnode(buf1, root);

	PrintValues(f, ALL);

	printf("\n type in the value, which you want to delete \n");
	scanf("%s", &buf2);

	VALUE* v = find_value_in_node(f, buf2);

	lala = delete_val(v, f);
}

void call_delete_all_val() {

	int a;
	TYPE type1;
	char buf1[255];

	printf("\n type in the node, from which you want to delete \n");
	scanf("%s", &buf1);

	printf("\n type in the type of variables you want to print 1 - int, 2 - float, 3 - double, 4 - char, 5 - ALL\n");
	scanf("%d", &a);

	switch (a) {
	case 1:type1 = INT; break;
	case 2:type1 = FLOAT; break;
	case 3:type1 = DOUBLE; break;
	case 4:type1 = CHAR; break;
	case 5:type1 = ALL; break;
	}

	NODE* f = find_node(buf1, root);

	delete_all_value(f, type1);
}
void call_create_new() {
	root = input_tree(NULL, "root");
	NODE* curNode;
	char buf[255];
	system("cls");
	printf("\n type in the name for a new node \n");
	scanf("%s", &buf);
	curNode = input_tree(root, buf);
	
}
void call_load() {
	FILE* pfile;
	char buf[100];
	system("cls");
	printf("\n type in file name of the Data Base \n");
	scanf("%s", &buf);
	pfile = fopen(buf, "r");
	root = scan_file(pfile);
	fclose(pfile);
}
