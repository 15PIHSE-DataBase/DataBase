//Функция осуществляет переход из текущей папки в папку на уровень выше - предок

#include "stdafx.h"
FOLDER* UpStep(FOLDER *CurrentF) 
{
	if (CurrentF->UpFolder == NULL) return CurrentF; //Корень 
	return CurrentF->UpFolder;
}
