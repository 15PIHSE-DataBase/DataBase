NODE* goToNode(char* s1, NODE* node) {  //выполняет переход в папку с данным именем из текущей директории
	if (node == NULL) return (NULL);
	NODE* tmp = node;
	char* s2;
	while (tmp != NULL) {               //ищем папку с именем, совпадающим с тем, которое подано в функцию
		s2 = tmp->NodeName;
		if (strcmp(s1, s2) != 0)
			tmp = tmp->NextNode;                    //если не нашли, то идем в следущего брата
		else
			return (tmp);
	}
	return (NULL);
}