#include "stdafx.h"
void Directory(FOLDER *CurrentF)
{
	FOLDER *temp;
	if (CurrentF->DownFolder!=NULL) temp = CurrentF->DownFolder;
	else {
		printf("\nDirectory is empty.\n");
		return;
	}
	printf("\nDirectory contains:\n");
	while (1)
	{
		printf("%s\n",temp->FolderName);
		if ((temp->NextFolder) == NULL) break;
		else temp = temp->NextFolder;
	}
}