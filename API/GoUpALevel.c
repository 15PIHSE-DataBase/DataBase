#include "DataBase15.h"

NODE* up_step(NODE*Current)
{
	if (Current == NULL) return NULL;
	if (Current->UpNode == NULL) return Current;
	return Current->UpNode;
}