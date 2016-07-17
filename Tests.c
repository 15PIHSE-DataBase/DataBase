#include"DataBase13.h"
#include"FunctionsForTesting.h"

void main()
{
	NODE  *pointer = NULL;
	NODE * MainRoot = NULL;

	BuildTree(&MainRoot);
	PrintLine();

	printf("UpStep check...\n");			//NODE* UpStep(NODE*);
	pointer = findnode("node8", MainRoot);
	FindError(UpStep(NULL), NULL);
	while (pointer->UpNode){
		pointer = UpStep(pointer);
		if (pointer)		
			printf("%s ", pointer->NodeName);
		else printf("\nThe end");
	}
	PrintLine();

	printf("\nPress any key to exit\n");
	getch();
}
