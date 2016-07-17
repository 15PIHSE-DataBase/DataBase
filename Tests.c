#include"DataBase13.h"
#include"FunctionsForTesting.h"

void main()
{
	//============================== N O D E S ==============================
	NODE * pointer = NULL;
	NODE * MainRoot = NULL;
	char NewName1[255] = "NewNode1", NewName2[255] = "NewNode2",
		UpExpect[2][10] = { "node3", "node1" },
		path[5][30] = { "node1", "node1.node3", "node1.node4.node6.NewNode1", "node1.node8", "12.34" },
		PathExpect[3][10] = { "node1", "node3", "NewNode1" };
	BuildTree(&MainRoot);
	//Directory(NULL);
	PrintLine();
	printf("UpStep check...\n");		//NODE* UpStep(NODE*);
	pointer = findnode("node8", MainRoot);
	FindError(UpStep(NULL), NULL);
	int i = 0;
	while (pointer->UpNode){
		FindError(pointer = UpStep(pointer), UpExpect[i]);
		i++;
	}
	PrintLine();

	printf("InputTree check...\n");		// NODE* InputTree(NODE *, char *);
	ErrorSearch_InsertNode(NewName1, MainRoot, InputTree);
	FullTree(MainRoot);
	PrintLine();

	printf("goToPath check...");		//NODE* goToPath(NODE *, char*);
	for (i = 0; i < 3; i++)
		FindError(goToPath(MainRoot, path[i]), PathExpect[i]);
	for (i = 3; i < 5; i++)
		FindError(goToPath(MainRoot, path[i]), NULL);
	PrintLine();

	printf("ChangeNodeName check...\n");	//NODE* ChangeNodeName(NODE * CurrentNode, char *NewName);
	ErrorSearch_ChangeNodeName(NewName2, NewName1, MainRoot, MainRoot);
	FullTree(MainRoot);
	PrintLine();

	printf("findnode check...\n");			//NODE* findnode(char*, NODE*);
	FindError(findnode(NewName1, MainRoot), NULL);
	FindError(findnode(NewName2, MainRoot), NewName2);
	FindError(findnode("node4", MainRoot->DownNode), NULL);
	FindError(findnode("node4", MainRoot), "node4");
	PrintLine();

	printf("Delete check...\n");			//int Delete(NODE**, NODE**);
	i = 1; printf("\n>>Check %d<<\n", i++);
	ErrorSearch_DeleteNode(NewName2, &MainRoot);
	FullTree(MainRoot);
	printf("\n>>Check %d<<\n", i++);
	ErrorSearch_DeleteNode("node3", &MainRoot);
	FullTree(MainRoot);
	printf("\n>>Check %d<<\n", i++);
	ErrorSearch_DeleteNode("node1", &MainRoot);
	FullTree(MainRoot);
	printf("\n>>Check %d<<\n", i++);
	ErrorSearch_DeleteNode("node1", &MainRoot);
	FullTree(MainRoot);
	PrintLine();
	//============================== V A L U E S ==============================
	BuildTree(&MainRoot);
	PrintLine();
	char Value[3][10] = { "100y", "red", "forest" }, Qualif[3][10] = { "Age", "Color", "Place" };
	pointer = MainRoot;

	printf("AddValue check...\n");						// NODE* InputTree(NODE *, char *);
	ErrorSearch_AddValue(pointer);
	PrintValues(pointer, ALL);
	PrintLine();

	printf("PrintValues check...\n");					//void PrintValues(NODE*, TYPE);
	PrintValues(pointer, ALL);
	PrintValues(pointer->DownNode, ALL);
	PrintLine();

	printf("findValueInNode & deleteValues check...\n"); //VALUE* findValueInNode(NODE*, char*); int deleteVal(VALUE*, NODE*);
	ErrorSearch_FindDeleteValue(pointer);

	printf("DeleteAllValue check...\n");					//void DeleteAllValue(NODE *, TYPE);
	ErrorSearch_DeleteAllValues(pointer);

	printf("\nPress any key to exit\n");
	getch();
}
