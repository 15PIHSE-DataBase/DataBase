#pragma once
#include "stdafx.h"

FOLDER* InputTree(FOLDER **currPtr, char *newname); //���������� ����� �����

void goToPath(char*); //������ �� ������, ���������� �� ����, ���������: ����

void goToFolder(char*); //������� � �����, �� ���� ������ �������� �����, � ������� ����� �����

FOLDER* DeleteFolders(Node);// �������� ����������� ������� �����

FOLDER Delete(FOLDER*);//�������� ����� �����

struct folder* findfolder(char*, struct folder*); //����� �����

struct folder* scanfile(FILE*); //�������� ���� �� �����

