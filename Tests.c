#include"DataBase13.h"
#include"FunctionsForTesting.h"

void main()
{
	NODE  *pointer = NULL;
	NODE * MainRoot = NULL;

	char NewName1[255] = "NewNode1",
		UpExpect[2][10] = { "node3", "node1" },
		path[4][20] = { "node1", "node1.node3.node8", "node1.node8", "12.34" },
		PathExpect[2][10] = { "node1", "node8" };
	BuildTree(&MainRoot);
	//Directory(NULL);
	PrintLine();
	printf("UpStep check...\n");			//NODE* UpStep(NODE*);
	pointer = findnode("node8", MainRoot);
	FindError(UpStep(NULL), NULL);
	int i = 0;
	while (pointer->UpNode){
		FindError(pointer = UpStep(pointer), UpExpect[i]);
		i++;
	}
	PrintLine();

	printf("goToPath check...");		//NODE* goToPath(NODE *, char*);
	for (i = 0; i < 2; i++)
		FindError(goToPath(MainRoot, path[i]), PathExpect[i]);
	for (i = 2; i < 4; i++)
		FindError(goToPath(MainRoot, path[i]), NULL);
	PrintLine();

	printf("InputTree check...\n");		// NODE* InputTree(NODE *, char *);
	ErrorSearch_InsertNode(NewName1, MainRoot, InputTree);
	FullTree(MainRoot);
	PrintLine();

	printf("\nPress any key to exit\n");
	getch();
}
