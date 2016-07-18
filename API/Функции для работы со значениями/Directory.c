//Функция распечатывает содержимое текущей директории

#include "stdafx.h"
void directory(NODE *CurrentF)
{
	NODE *temp;
	//Проверка на наличие содержимого в данной директории
	if (CurrentF->DownNode!=NULL) temp = CurrentF->DownNode;
	else {
		printf("\nDirectory is empty.\n");
		return;
	}
	//Распечатка всех папок
	printf("\nDirectory contains:\n");
	while (1)
	{
		printf("%s\n",temp->NodeName);
		if ((temp->NextNode) == NULL) break;
		else temp = temp->NextNode;
	}
}