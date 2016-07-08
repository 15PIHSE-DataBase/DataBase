#include "stdafx.h"
#include <string.h>
#include <stdlib.h>

typedef enum TYPE{None,Int,Float,Double,Bool,Character}TYPE;
 
typedef struct Sweets
{
	TYPE type = None;
	union
	{
		int Integer;
		float Float;
		double Double;
		bool Bool;
		char Character;
	}Candy;
	Sweets * NextCandy;
}Sweets;

typedef struct Box
{
	char BoxName[20];
	int level;
	Box * FatherBox;
	Box * NextBox;
	Box * PreviousBox;
	Box * BoxIn;
	Sweets * Candies;
}Box;



Box * MainBox = NULL;
void NewBox(Box **);
void TreePrint(Box *);
Box * Search(char *, Box *);
void Record(Box *);
void RecordCouples(Box *, FILE *);

int main()
{
	NewBox(&MainBox);
	NewBox(&MainBox);
	NewBox(&MainBox);
	NewBox(&MainBox);
	NewBox(&MainBox);
	NewBox(&MainBox);
	NewBox(&(MainBox->BoxIn));
	NewBox(&(MainBox->BoxIn));
	NewBox(&(MainBox->BoxIn));
	NewBox(&(MainBox->BoxIn));
	Record(MainBox->BoxIn);
}


void TreePrint(Box * box)
{
	if (box == NULL)
		return;
	TreePrint(box->BoxIn);
	TreePrint(box->NextBox);
	printf("%s\n", box->BoxName);
}

void NewBox(Box ** box)
{
	Box * newBox = (Box*)malloc(sizeof(Box));
	if (*box == NULL)
	{
	    printf("Enter new box name>>");
		scanf("%s", newBox->BoxName);
		newBox->level = 1;
		newBox->FatherBox = NULL;
		newBox->NextBox = NULL;
		newBox->BoxIn = NULL;
		newBox->PreviousBox = NULL;
		*box = newBox;
	}
	else
	{
		printf("Enter new box name>>");
		scanf("%s", newBox->BoxName);
		newBox->FatherBox = *box;
		newBox->level = (*box)->level + 1;
		newBox->BoxIn = NULL;
		if ((*box)->BoxIn)
		{
			(*box)->BoxIn->PreviousBox = newBox;
			newBox->NextBox = (*box)->BoxIn;
			newBox->PreviousBox = NULL;
			(*box)->BoxIn = newBox;
		}
		else
		{
			newBox->NextBox = NULL;
			newBox->PreviousBox = NULL;
			(*box)->BoxIn = newBox;
		}
	}
}


Box *Search(char *str, Box *pointer)
{
	if (strcmp(pointer->BoxName, str))
		if (pointer->NextBox == NULL)
		{
			while (pointer->PreviousBox != NULL) pointer = pointer->PreviousBox;
			if (pointer->BoxIn != NULL) Search(str, pointer->BoxIn);
			else return NULL;//name not found
		}
		else Search(str, pointer->NextBox);
	else return pointer;
}

void Record(Box * box)
{
	FILE * FileToOpen;
	char FilePath[40];
	printf("Path>>");
	gets_s(FilePath, 40);
	FileToOpen = fopen(FilePath, "w+");
	while (FileToOpen == NULL)
	{
		printf("Couldn't open file\nPath>>");
		gets_s(FilePath, 40);
		FileToOpen = fopen(FilePath, "w+");
	}
	RecordCouples(box, FileToOpen);
	printf("Success\n");
}
void RecordCouples(Box * box,FILE * file)
{
	if (box == NULL)
		return;
	RecordCouples(box->NextBox, file);
	RecordCouples(box->BoxIn, file);
	fprintf(file,"%s\n\n%s\n\n", box->BoxName, box->FatherBox->BoxName);
}