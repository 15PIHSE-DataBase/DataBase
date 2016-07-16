#include "DataBase15.h"

NODE* UpStep(NODE*CurrentF)
{
	if (CurrentF->UpNode == NULL) return CurrentF; //?????? 
	return CurrentF->UpNode;
}