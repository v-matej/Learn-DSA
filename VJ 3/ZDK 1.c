#include "stl.h"
#include <stdio.h>


int main()
{
	FILE* fp;
	fp = fopen("primjerbin.stl", "rb");
	if (!fp)
		return 1;
	Objekt3D* p_obj;
	p_obj = read_BIN(fp);
	write_BIN(p_obj);
	write_TXT(p_obj);
	free_obj(p_obj);
	fclose(fp);
	return 0;
}