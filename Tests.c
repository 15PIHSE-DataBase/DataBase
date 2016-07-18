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
	build_tree(&MainRoot);
	//directory(NULL);
	print_line();
	printf("up_step check...\n");			//NODE* up_step(NODE*);
	pointer = find_node("node8", MainRoot);
	find_error(up_step(NULL), NULL);
	int i = 0;
	while (pointer->UpNode){
		find_error(pointer = up_step(pointer), UpExpect[i]);
		i++;
	}
	print_line();

	printf("input_tree check...\n");			// NODE* input_tree(NODE *, char *);
	error_search_insert_node(NewName1, MainRoot, input_tree);
	full_tree(MainRoot);
	print_line();

	printf("go_to_path check...");			//NODE* go_to_path(NODE *, char*);
	for (i = 0; i < 3; i++)
		find_error(go_to_path(MainRoot, path[i]), PathExpect[i]);
	for (i = 3; i < 5; i++)
		find_error(go_to_path(MainRoot, path[i]), NULL);
	print_line();

	printf("change_node_name check...\n");	//NODE* change_node_name(NODE * CurrentNode, char *NewName);
	error_search_change_node_name(NewName2, NewName1, MainRoot, MainRoot);
	full_tree(MainRoot);
	print_line();

	printf("find_node check...\n");			//NODE* find_node(char*, NODE*);
	find_error(find_node(NewName1, MainRoot), NULL);
	find_error(find_node(NewName2, MainRoot), NewName2);
	find_error(find_node("node4", MainRoot->DownNode), NULL);
	find_error(find_node("node4", MainRoot), "node4");
	print_line();

	printf("delete_node check...\n");			//int delete_node(NODE**, NODE**);
	i = 1; printf("\n>>Check %d<<\n", i++);
	error_search_delete_node(NewName2, &MainRoot);
	full_tree(MainRoot);
	printf("\n>>Check %d<<\n", i++);
	error_search_delete_node("node3", &MainRoot);
	full_tree(MainRoot);
	printf("\n>>Check %d<<\n", i++);
	error_search_delete_node("node1", &MainRoot);
	full_tree(MainRoot);
	printf("\n>>Check %d<<\n", i++);
	error_search_delete_node("node1", &MainRoot);
	full_tree(MainRoot);
	print_line();
	//============================== V A L U E S ==============================
	build_tree(&MainRoot);
	print_line();
	char Value[3][10] = { "100y", "red", "forest" }, Qualif[3][10] = { "Age", "Color", "Place" };
	pointer = MainRoot;

	printf("add_value check...\n");							// VALUE * add_value(NODE *CurrentPtr, char *Qualf, TYPE Type, char * Info)
	error_search_add_value(pointer);
	error_search_add_value(pointer->DownNode);
	print_values(pointer, ALL);
	print_line();

	printf("print_values check...\n");						//void print_values(NODE*, TYPE);
	print_values(pointer, ALL);
	print_values(pointer->DownNode, ALL);
	print_line();

	printf("find_value_in_node & delete_val check...\n");	//VALUE* find_value_in_node(NODE*, char*); int delete_val(VALUE*, NODE*);
	error_search_find_delete_value(pointer);
	print_line();

	printf("delete_all_value check...\n");					//void delete_all_value(NODE *, TYPE);
	error_search_delete_all_values(pointer);
	print_line();

	printf("\nPress any key to exit\n");
	getch();
}
