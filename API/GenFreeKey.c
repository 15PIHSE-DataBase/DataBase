
#include "key.h"
#include <stdlib.h>
#include <stdio.h>

int keys = 0;		//???? ????? ?????????? ???? ? stdafx, ?? ???? ??????? ??!!!
int number = 0;		//?????????? ???-?? ?????????????? ??????
int* freek = NULL;	//?????? ?????????????? ??????

int gen_newkey()
{
	int save = 0;
	int * buf;
	if (number != 0)
	{
		save = *(freek + number - 1);
		--number;
		buf = (int*)malloc(number*sizeof(int));
		for (int i = 0; i < number; ++i)
			*(buf + i) = *(freek + i);
		free(freek);
		freek = (int*)malloc(number*sizeof(int));
		for (int i = 0; i < number; ++i)
			*(freek + i) = *(buf + i);
		free(buf);
		return save;
	}
	++keys;
	return keys;
}

void delete_key(int a)
{
	if (number != 0) {
		int * buf;
		buf = (int*)malloc(number*sizeof(int));
		for (int i = 0; i < number; ++i)
			*(buf + i) = *(freek + i);
		free(freek);
		++number;
		freek = (int*)malloc(number*sizeof(int));
		for (int i = 0; i < (number - 1); ++i)
			*(freek + i) = *(buf + i);
		free(buf);
		*(freek + number - 1) = a;
	}
	else {
		freek = (int*)malloc(sizeof(int));
		*(freek + number) = a;
		++number;
	}
}

int compare(const void * x1, const void * x2)
{
	return (*(int*)x1 - *(int*)x2);
}

void create_freek(int * buf, int size)
{
	qsort(buf, size, sizeof(int), compare);
	int save = *(buf + size - 1);
	int t = 0;
	for (int i = 1; i < save; ++i) {
		if ((t > size) || i != *(buf + t)) {
			++number;
			freek = (int*)realloc(freek, number*sizeof(int));
			*(freek + number - 1) = i;
			continue;
		}
		if (i == *(buf + t)) {
			++t;
			continue;
		}
	}
}