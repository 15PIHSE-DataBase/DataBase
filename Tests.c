#include"DataBase13.h"
#include"FunctionsForTesting.h"

void main()
{
	NODE  *pointer = NULL;
	NODE * MainRoot = NULL;
	BuildTree(&MainRoot);

	printf("\nPress any key to exit\n");
	getch();
}
