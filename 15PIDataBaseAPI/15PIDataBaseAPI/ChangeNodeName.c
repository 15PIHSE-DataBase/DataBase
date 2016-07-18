

#include "DataBase15.h"

NODE * go_to_node(char*, NODE*);
NODE* change_node_name(NODE * CurrentNode, char *NewName)
{
	if (!(CurrentNode) || (goToNode(NewName, CurrentNode->UpNode))) //Поступивший указатель пуст или имя уже занято 
		return NULL;
	else //Имя свободно
	{
		strcpy(CurrentNode->NodeName, NewName);
		return CurrentNode;
	}
}
//Функция нахождения узла по имени
//В случае успеха возвращает указатель на узел с требуемым именем, иначе - NULL
//char* s1 - имя для поиска
//NODE* node - указатель на узел, где необходимо усществить поиск
NODE * go_to_node(char* s1, NODE* node) {                 //выполняет переход в папку с данным именем из текущей директории
	if (!node) return NULL;
	NODE* tmp = node->DownNode;
	while (tmp != NULL) {               //ищем папку с именем, совпадающим с тем, которое подано в функцию
		if (strcmp(s1, tmp->NodeName))
			tmp = tmp->NextNode;                    //если не нашли, то идем в следущего брата
		else
			return tmp;
	}
	return NULL;
}