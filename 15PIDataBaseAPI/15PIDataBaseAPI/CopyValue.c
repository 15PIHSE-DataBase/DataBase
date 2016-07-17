
#include "DataBase15.h"

VALUE* CopyPasteValue(NODE *PtrFrom, VALUE *temp, NODE *PtrTo, int* i) //функция cutpuste, copypaste. функция принимает указатель на узел из которого скопировать,
																	   //адрес копируемого значения и указатель на узел куда нужно вставить значение, а также режим 0-копия 1-вырезать-вставить
																	   //вернёт адрес вставленного элемента в случае успеха или NULL в случае ошибки. В i код ошибки: 2 в случае попытки вставить в узел где уже есть значение с таким именем и 3 при выборе неправильного режима
{
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
			return(NULL);
		i = 2;
		break;
	case 1:
		deleteVal(temp, PtrFrom);
		p = AddValue(PtrTo, temp->Qualifier, temp->type, temp->Value);
		if (p != NULL)
		{
			return (p);
		}
		else
			return(NULL);
		i = 2;
		break;
	default:
		return(NULL);
		i = 3;
	}
}