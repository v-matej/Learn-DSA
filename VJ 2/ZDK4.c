#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float x;
	float y;
}tocka;

typedef struct
{
	int n;
	tocka* niz;
}poligon;

poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{
	poligon* p_1=(poligon*)malloc(n*sizeof(poligon));
	p_1->n = n;
	p_1->niz= (tocka*)malloc(n * sizeof(tocka));
	for (int i = 0; i < n; i++)
	{
		p_1->niz[i].x = niz_x[i];
		p_1->niz[i].y = niz_y[i];
	}
	return p_1;
}

tocka** pozitivni(poligon* p, int* np)
{
	int br = 0;
	for (int i = 0; i < p->n; i++)
	{
		if (((p->niz[i].x) >= 0) && ((p->niz[i].y) >= 0))
			br++;
	}
	tocka** tocka_niz;
	tocka_niz = (tocka**)malloc(br * sizeof(tocka*));
	if (!tocka_niz)
		return NULL;
	int j = 0;
	for (int i = 0; i < p->n; i++)
	{
		if (((p->niz[i].x) >= 0) && ((p->niz[i].y) >= 0))
		{	
			tocka_niz[j] = &p->niz[i];
			j++;
			/*
			tocka_niz[j] = (tocka*)malloc(sizeof(tocka));
			if (!tocka_niz[j])
				return NULL;
			tocka_niz[j]->x = p->niz[i].x;
			tocka_niz[j]->y = p->niz[i].y;
			j++;
			*/
		}
	}
	*np = br;
	return tocka_niz;
}

void print_poligon(poligon* p)
{
	for (int i = 0; i < p->n; i++)
	{
		printf("%f %f\n", p->niz[i].x, p->niz[i].y);
	}
	printf("\n");
}

void print_poz_t(tocka** p_t, int n)
{
	for (int i = 0;i < n; i++)
	{
		printf("%f %f \n", p_t[i]->x, p_t[i]->y);
	}
	printf("\n");
}

/*
void free_all(tocka** p_t, int n)
{
	for(int i = 0; i < n; i++)
	{
		free(p_t[i]);
	}
}
*/

int main()
{
	int* np;
	tocka** poz_niz;
	poligon* p;
	float niz_x[] = { -5,-4,-3,-2,-1,0,1,2,3,4,5 };
	float niz_y[] = { -5,-4,-3,-2,-1,0,1,2,3,4,5 };
	int n = sizeof(niz_y) / sizeof(int);
	p = novi_poligon(niz_x, niz_y, n);
	print_poligon(p);
	poz_niz = pozitivni(p, &np);
	print_poz_t(poz_niz, np);
	//free_all(poz_niz, np);
	free(p);
	return 0;
}