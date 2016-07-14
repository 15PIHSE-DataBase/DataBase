
#include "15PIDataBaseAPI.h"

NODE* UpStep(NODE*CurrentF)
{
	if (CurrentF->UpNode == NULL) return CurrentF; //?????? 
	return CurrentF->UpNode;
}