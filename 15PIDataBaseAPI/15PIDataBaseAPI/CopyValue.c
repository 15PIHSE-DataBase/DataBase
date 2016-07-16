
#include "DataBase15.h"

VALUE* CopyPasteValue(NODE *PtrFrom, VALUE *temp, NODE *PtrTo, int* i) //функция cutpuste, copypaste. функция принимает указатель на узел из которого скопировать,
																	   //адрес копируемого значения и указатель на узел куда нужно вставить значение, а также режим 1-копия 2-вырезать-вставить
{
	int deleting;
	VALUE* temp2 = temp;
	VALUE *p = NULL;
	switch (*i)
	{
	case 0:
		p = AddValue(PtrTo, temp->Qualifier, temp->type, temp->Value);
		if (p != NULL)
		{
			return (p);
		}
		else
			return(2);
		break;
	case 1:
		deleting = deleteVal(PtrFrom, temp);
		p = AddValue(PtrTo, temp2->Qualifier, temp2->type, temp2->Value);
		free(temp2);
		break;
	default:
		return(3);
	}
}