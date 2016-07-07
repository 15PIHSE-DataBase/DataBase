#include "Kirill.h"
#include <string.h>
FOLDER* current;

FOLDER *goToNextLevel(char* s1) {
	FOLDER* tmp = current;
	char* s2;
	while (tmp->NextFolder != NULL) {
		s2 = tmp->FolderName;
		if (strcmp(s1, s2) != 0) {
			tmp = tmp->NextFolder;
		}
		else {
			current = (tmp->DownFolder);
			break;
		}
	}

}
void goToPath() {

}