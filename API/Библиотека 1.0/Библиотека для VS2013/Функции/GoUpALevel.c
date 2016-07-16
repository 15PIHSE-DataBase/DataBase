
#include "DataBase13.h"

NODE* UpStep(NODE*Current)
{
	if (Current==NULL) return NULL;
	if (Current->UpNode == NULL) return Current; 
	return Current->UpNode;
}