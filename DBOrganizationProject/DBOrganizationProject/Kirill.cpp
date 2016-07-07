#include "Kirill.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
FOLDER* current;
FOLDER* root;

void goToFolder(char* s1) {
	FOLDER* tmp = root;
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

char** str_split(char* a_str, const char a_delim)
{
	char** result = 0;
	size_t count = 0;
	char* tmp = a_str;
	char* last_comma = 0;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = 0;

	
	while (*tmp)
	{
		if (a_delim == *tmp)
		{
			count++;
			last_comma = tmp;
		}
		tmp++;
	}
	count += last_comma < (a_str + strlen(a_str) - 1);
	count++;

	result = (char**)malloc(sizeof(char*) * count);

	if (result)
	{
		size_t idx = 0;
		char* token = strtok(a_str, delim);

		while (token)
		{
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

void goToPath(char* path) {
	char** tokens;
	tokens = str_split(path, '/');
	if (tokens)
	{
		int i;
		for (i = 0; *(tokens + i); i++)
		{
			//printf("month=[%s]\n", *(tokens + i));
			goToFolder(*(tokens + i));
			free(*(tokens + i));
		}
		printf("\n");
		free(tokens);
	}
}