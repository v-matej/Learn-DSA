#ifndef stl_h
#define stl_h
#include <stdio.h>

typedef struct
{
	float i, j, x;
}Normal;

typedef struct
{
	float x, y, z;
}Vrh;

typedef struct
{
	Normal normal;
	Vrh v1;
	Vrh v2;
	Vrh v3;
	unsigned short int boja;
}Trokut;

typedef struct
{
	int n;
	Trokut* niz;
}Objekt3D;

Objekt3D* read_BIN(FILE* fp_BIN);
void write_BIN(Objekt3D* obj);
void write_TXT(Objekt3D* obj);
void free_obj(Objekt3D* obj);
#endif // stl.h

