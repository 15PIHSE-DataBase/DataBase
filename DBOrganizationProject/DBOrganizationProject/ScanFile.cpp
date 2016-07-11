#include "stdafx.h"

NODE* scanfile(FILE* dat)
{
	NODE * rootes = (NODE*)malloc(sizeof(NODE));
	rootes->UpNode = NULL;
	rootes->NextNode = NULL;
	rootes->PreviousNode = NULL;
	rootes->DownNode = NULL;
	//memset(root->NodeName, 0, 20);
	if (dat == NULL)
		return rootes;

	rootes->DownNode = (NODE*)malloc(sizeof(NODE));
	rootes->DownNode->UpNode = rootes;
	rootes->DownNode->NextNode = NULL;
	rootes->DownNode->PreviousNode = NULL;
	rootes->DownNode->DownNode = NULL;
	//memset(root->DownNode->NodeName, 0, 20);

	fscanf(dat, "%s\n\n%s\n\n", rootes->NodeName, rootes->DownNode->NodeName);
	if (strcmp(rootes->NodeName, "") == 0) {
		printf("\nRead error or file is empty\nCreated new data base...\n");
		return rootes;
	}

	char Father[20];
	char Child[20];
	NODE * buf = rootes;
	NODE* children;
	NODE* ggwp;
	int check = 0;
	//!!!BEGIN!!!
	while (!feof(dat)) {
		//memset(Father, 0, 20);
		//memset(Child, 0, 20);
		fscanf(dat, "%s\n\n%s\n\n", Father, Child);
		if (strcmp(Father, "") == 0)
			return rootes;
		children = buf->DownNode;

		if (strcmp(buf->NodeName, Father) == 0) {//Ищем по отцу
			while (children != NULL) {
				++check;
				ggwp = children;
				children = children->NextNode;
			}
			if (children == NULL) {
				children = (NODE*)malloc(sizeof(NODE));
				children->UpNode = buf;
				children->NextNode = NULL;
				children->DownNode = NULL;
				//memset(children->NodeName, 0, 20);
				strcpy(children->NodeName, Child);
				if (check == 0) {
					buf->DownNode = children;
					children->PreviousNode = NULL;
				}
				else {
					ggwp->NextNode = children;
					children->PreviousNode = ggwp;
				}
				continue;
			}
		}

		check = 1;
		while (1) {//ищем по детям
			if (children == NULL) {
				break;
			}
			if (strcmp(children->NodeName, Father) == 0) {
				children->DownNode = (NODE*)malloc(sizeof(NODE));
				children->DownNode->UpNode = children;
				children->DownNode->NextNode = NULL;
				children->DownNode->PreviousNode = NULL;
				children->DownNode->DownNode = NULL;
				//memset(children->DownNode->NodeName, 0, 20);
				strcpy(children->DownNode->NodeName, Child);

				buf = children;
				check = 0;
			}
			children = children->NextNode;
		}

		if (check == 1) {
			//Поиск по всему дереву
			check = 0;
			ggwp = findnode(Father, rootes);
			buf = ggwp;
			children = buf->DownNode;
			children = (NODE*)malloc(sizeof(NODE));
			children->UpNode = buf;
			children->NextNode = NULL;
			children->PreviousNode = NULL;
			children->DownNode = NULL;
			//memset(children->NodeName, 0, 20);
			strcpy(children->NodeName, Child);
			buf->DownNode = children;

		}
	}
	return rootes;
}