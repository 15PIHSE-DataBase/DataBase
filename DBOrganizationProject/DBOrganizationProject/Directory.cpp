//Функция распечатывает содержимое текущей директории

#include "stdafx.h"
void Directory(FOLDER *CurrentF)
{
	FOLDER *temp;
	//Проверка на наличие содержимого в данной директории
	if (CurrentF->DownFolder!=NULL) temp = CurrentF->DownFolder;
	else {
		printf("\nDirectory is empty.\n");
		return;
	}
	//Распечатка всех папок
	printf("\nDirectory contains:\n");
	while (1)
	{
		printf("%s\n",temp->FolderName);
		if ((temp->NextFolder) == NULL) break;
		else temp = temp->NextFolder;
	}
}