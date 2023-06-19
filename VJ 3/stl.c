#include "stl.h"
#include <stdlib.h>

Objekt3D* read_BIN(FILE* fp_BIN)
{
	
	Objekt3D* obj_1;
	obj_1 = (Objekt3D*)malloc(sizeof(Objekt3D));
	fseek(fp_BIN, 80, SEEK_SET);
	fread(&obj_1->n, sizeof(int), 1, fp_BIN);
	obj_1->niz = (Trokut*)malloc(obj_1->n * sizeof(Trokut));
	int i;
	for (i = 0; i < obj_1->n; i++)
	{
		fread(&obj_1->niz[i], 50, 1, fp_BIN);
	}
	return obj_1;
}

void write_BIN(Objekt3D* obj)
{
	FILE* fp_new_BIN;
	fp_new_BIN = fopen("nova_BIN.stl", "wb+");
	int i;
	char empty_arr[80] = { 0 };
	fwrite(&empty_arr, sizeof(char), 80, fp_new_BIN);
	fwrite(&obj->n,sizeof(int), 1, fp_new_BIN);
	for (i = 0; i < obj->n; i++)
	{
		fwrite(&obj->niz[i], 50, 1, fp_new_BIN);
	}
	fclose(fp_new_BIN);
}

void write_TXT(Objekt3D* obj)
{
	FILE* fp_new_TXT;
	fp_new_TXT = fopen("nova_TXT.stl", "w+");
	int i;
	fprintf(fp_new_TXT, "solid OpenSCAD_Model");
	for (i = 0; i < obj->n; i++)
	{
		fprintf(fp_new_TXT, "facet normal %f %f %f\n", obj->niz[i].normal.i, obj->niz[i].normal.j, obj->niz[i].normal.x);
		fprintf(fp_new_TXT, "\touter loop\n");
		fprintf(fp_new_TXT, "\t\tvertex %f %f %f\n", obj->niz[i].v1.x, obj->niz[i].v1.y, obj->niz[i].v1.z);
		fprintf(fp_new_TXT, "\t\tvertex %f %f %f\n", obj->niz[i].v2.x, obj->niz[i].v2.y, obj->niz[i].v2.z);
		fprintf(fp_new_TXT, "\t\tvertex %f %f %f\n", obj->niz[i].v3.x, obj->niz[i].v3.y, obj->niz[i].v3.z);
		fprintf(fp_new_TXT, "\tendloop\n");
		fprintf(fp_new_TXT, "endfacet\n");
	}
	fprintf(fp_new_TXT, "endsolid OpenSCAD_Model");
	fclose(fp_new_TXT);
}

void free_obj(Objekt3D* obj)
{
	free(obj->niz);
	free(obj);
}