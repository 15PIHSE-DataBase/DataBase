//Функция осуществляет переход из текущей папки в папку на уровень выше - предок

#include "stdafx.h"
NODE* up_step(NODE*CurrentF) 
{
	if (CurrentF->UpNode == NULL) return CurrentF; //Корень 
	return CurrentF->UpNode;
}
