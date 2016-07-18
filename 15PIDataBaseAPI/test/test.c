#include "stdafx.h"
#include "DataBase15.h"

void help();
void startUp();
void callNewNode();
 void callDeleteNode();
 void callPath(); 
 void callPrintNode(); 
 void callChangeNodeName();
 void callSaveDB(); 
void  callExit(); 

void callNewValue();
void callChangeVal(); 
void  callCopy(); 
void callGetNameVal();
void callPrintVal();
void callDeleteVal(); 
void callDeleteAllVal(); 
void callCreateNew();
void callLoad();

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
		case 1: callNewValue(); break;
		case 2: callChangeVal(); break;
		case 3: callCopy(); break;
		//case 4: callGetNameVal(); break;
		case 4: callPrintVal(); break;
		case 5: callDeleteVal(); break;
		case 6: callDeleteAllVal(); break;
		case 7: callExit(); break;
		default: printf("error"); help(); break;
		}
	}
	getch();
}

void startUp() {
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
		callLoad();
		printf("DB loaded\n");
		getch();
	}
	else if (choice == 'n' || choice == 'N') {
		system("cls");
		callCreateNew();
		printf("new DB is created\n");
		getch();
	}
}

void callNewNode() {
	NODE* curNode;
	char buf1[255];
	char buf2[255];
	system("cls");
	printf("\n type in the name for a new node \n");
	scanf("%s", &buf1);
	printf("\n type in the node in which you want to place the new node \n");
	scanf("%s", &buf2);
	NODE* f = findnode(buf2, root);
	curNode = InputTree(f, buf1);
	
}

void callDeleteNode() {
	NODE* curNode;
	char buf1[255];
	system("cls");
	printf("\n type in the name of the node you want to delete \n");
	scanf("%s", &buf1);
	NODE* f = findnode(buf1, root);
	int lala = Delete(&f, &root);
}

void callPath() {
	printf("3");
	//Возможно это лишняя функция
}

void callPrintNode() {
	
	char buf1[255];
	system("cls");
	printf("\n type in the name of the node you want to print \n");
	scanf("%s", &buf1);
	NODE* f = findnode(buf1, root);
	Directory(f);
}

void callChangeNodeName() {
	NODE* curNode;
	char buf1[255];
	char buf2[255];
	system("cls");
	printf("\n type in the name of the node you want to change name for \n");
	scanf("%s", &buf1);
	printf("\n type in the new name for the node \n");
	scanf("%s", &buf2);
	NODE* f = findnode(buf1, root);
	ChangeNodeName(f, buf2);
}

void callSaveDB() {
	NODE* curNode;
	FILE* pfile;
	char buf1[255];
	system("cls");
	printf("\n type in the name of the file \n");
	scanf("%s", &buf1);
	pfile = fopen(buf1, "w");
	Record(root, pfile);
	fclose(pfile);
}

void  callExit() {
	printf("\nEXIT\n");
	getch();
	exit(0);
}

void callNewValue() {
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

	NODE* f = findnode(buf3, root);

	AddValue(f, buf1, type1, buf2);
	
}

void callChangeVal() {
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

	NODE* f = findnode(buf3, root);
	newVal = findValueInNode(f, buf4);

	printf("\n do you want to change the name of the variable? 1 - yes, 2 - no\n");
	scanf("%d", &a);
	if (a == 1) {
		printf("\n type in the new name for the value \n");
		scanf("%s", &buf1);
		ChangeQualifier(f, newVal, buf1);
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

		ChangeValue(newVal, type1, buf2);
	
}

void  callCopy() {
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


	NODE* from = findnode(buf1, root);
	NODE* to = findnode(buf2, root);
	VALUE* v = findValueInNode(from, buf3);
	VALUE* copied;
	copied = Copy(v);
	lala = Paste(to, copied);
	
}

void callGetNameVal() {
	printf("4");
	//lлишняя функция
}

void callPrintVal() {
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

	NODE* f = findnode(buf1, root);

	lala = PrintValues(f, type1);
}

void callDeleteVal() {

	int lala;

	char buf1[255];
	char buf2[255];

	printf("\n type in the node, from which you want to delete \n");
	scanf("%s", &buf1);
	
	NODE* f = findnode(buf1, root);

	PrintValues(f, ALL);

	printf("\n type in the value, which you want to delete \n");
	scanf("%s", &buf2);

	VALUE* v = findValueInNode(f, buf2);

	lala = deleteVal(v, f);
}

void callDeleteAllVal() {

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

	NODE* f = findnode(buf1, root);

	DeleteAllValue(f, type1);
}
void callCreateNew() {
	root = InputTree(NULL, "root");
	NODE* curNode;
	char buf[255];
	system("cls");
	printf("\n type in the name for a new node \n");
	scanf("%s", &buf);
	curNode = InputTree(root, buf);
	
}
void callLoad() {
	FILE* pfile;
	char buf[100];
	system("cls");
	printf("\n type in file name of the Data Base \n");
	scanf("%s", &buf);
	pfile = fopen(buf, "r");
	root = scanfile(pfile);
	fclose(pfile);
}
