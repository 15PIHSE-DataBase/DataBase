#include "stdafx.h"

struct folder* scanfile(FILE* dat)
{
	FOLDER * root = (FOLDER*)malloc(sizeof(FOLDER));
	root->UpFolder = NULL;
	root->NextFolder = NULL;
	root->PreviousFolder = NULL;
	root->DownFolder = NULL;
	//memset(root->FolderName, 0, 20);
	if (dat == NULL)
		return root;

	root->DownFolder = (FOLDER*)malloc(sizeof(FOLDER));
	root->DownFolder->UpFolder = root;
	root->DownFolder->NextFolder = NULL;
	root->DownFolder->PreviousFolder = NULL;
	root->DownFolder->DownFolder = NULL;
	//memset(root->DownFolder->FolderName, 0, 20);

	fscanf(dat, "%s\n\n%s\n\n", root->FolderName, root->DownFolder->FolderName);
	printf("%s=>%s  Begin\n", root->FolderName, root->DownFolder->FolderName);
	if (strcmp(root->FolderName, "") == 0) {
		printf("\nRead error or file is empty\nCreated new data base...\n");
		return root;
	}

	char Father[20];
	char Child[20];
	FOLDER * buf = root;
	FOLDER * children;
	FOLDER * ggwp;
	int check = 0;
	//!!!BEGIN!!!
	while (!feof(dat)) {
		//memset(Father, 0, 20);
		//memset(Child, 0, 20);
		fscanf(dat, "%s\n\n%s\n\n", Father, Child);
		printf("%s=>%s  ", Father, Child);
		if (strcmp(Father, "") == 0)
			return root;
		children = buf->DownFolder;

		if (strcmp(buf->FolderName, Father) == 0) {//Ищем по отцу
			printf("Father\n");
			while (children != NULL) {
				++check;
				ggwp = children;
				children = children->NextFolder;
			}
			if (children == NULL) {
				children = (FOLDER*)malloc(sizeof(FOLDER));
				children->UpFolder = buf;
				children->NextFolder = NULL;
				children->DownFolder = NULL;
				//memset(children->FolderName, 0, 20);
				strcpy(children->FolderName, Child);
				if (check == 0) {
					buf->DownFolder = children;
					children->PreviousFolder = NULL;
				}
				else {
					ggwp->NextFolder = children;
					children->PreviousFolder = ggwp;
				}
				continue;
			}
		}

		check = 1;
		while (1) {//ищем по детям
			if (children == NULL) {
				break;
			}
			if (strcmp(children->FolderName, Father) == 0) {
				printf("Children\n");
				children->DownFolder = (FOLDER*)malloc(sizeof(FOLDER));
				children->DownFolder->UpFolder = children;
				children->DownFolder->NextFolder = NULL;
				children->DownFolder->PreviousFolder = NULL;
				children->DownFolder->DownFolder = NULL;
				//memset(children->DownFolder->FolderName, 0, 20);
				strcpy(children->DownFolder->FolderName, Child);

				buf = children;
				check = 0;
			}
			children = children->NextFolder;
		}

		if (check == 1) {
			//Поиск по всему дереву
			check = 0;
			printf("Find\n");
			ggwp = findfolder(Father, root);
			buf = ggwp;
			children = buf->DownFolder;

			children = (FOLDER*)malloc(sizeof(FOLDER));
			children->UpFolder = buf;
			children->NextFolder = NULL;
			children->PreviousFolder = NULL;
			children->DownFolder = NULL;
			//memset(children->FolderName, 0, 20);
			strcpy(children->FolderName, Child);
			buf->DownFolder = children;

		}
	}
	return root;
}