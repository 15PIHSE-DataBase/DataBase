#include "generation.h"
#include <stdlib.h>
#include <stdio.h>

int keys = 0;		//���� ����� ���������� ���� � stdafx, �� ���� ������� �!!!
int number = 0;		//���������� ���-�� �������������� ������
int* freek = NULL;	//������ �������������� ������

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