NODE * goToNode(char* s1, NODE* node) {                 //выполняет переход в папку с данным именем из текущей директории
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
