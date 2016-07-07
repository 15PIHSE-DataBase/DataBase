#include "stdafx.h"
FOLDER* UpStep(FOLDER *CurrentF)
{
	if (CurrentF->UpFolder == NULL) return CurrentF;
	return CurrentF->UpFolder;
}
