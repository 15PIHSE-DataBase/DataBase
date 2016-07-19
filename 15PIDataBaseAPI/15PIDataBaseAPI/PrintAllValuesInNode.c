
#include "DataBase15.h"

int print_values(NODE *head, TYPE Type) //Вывод на экран всех значений узла и их типов
{
	if (!(head) || !(head->Values)) { //Указатель пуст или нет значений в узле 
		printf("Empty\n");
		return 0;
	}
	VALUE *temp = head->Values;
	int Count = 0; //Счётчик количества значений в узле требуемого типа
	while (temp != NULL) {
		if ((temp->type == Type) || (Type == ALL)) {
			printf("%s: %s ", temp->Qualifier, temp->Value);
			switch (temp->type) {
			case INT:printf("(int)  "); break;
			case FLOAT:printf("(float)  "); break;
			case DOUBLE:printf("(double)  "); break;
			case CHAR:printf("(char)  "); break;
			}
			Count++;
		}
		temp = temp->NextValue;
	}
	if (Count) printf("\n");
	else printf("No required type values\n");
	return Count;
}