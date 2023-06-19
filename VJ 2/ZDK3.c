#include <stdio.h>
#include <stdlib.h>

void print_arr(int* niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
	printf("\n");
}

int** podijeli(int* niz, int n)
{
	int x1 = n / 2;
	int x2 = n - x1;
	int* prvi_niz;
	prvi_niz = (int*)malloc(x1 * sizeof(int));

	int* drugi_niz;
	drugi_niz = (int*)malloc(x2 * sizeof(int));

	int** pointer_niz;
	pointer_niz = (int**)malloc(2 * sizeof(int*));

	int i=0;
	int j = 0;
	for (i; i < x1; i++)
	{
		prvi_niz[j] = niz[i];
		j++;
	}
	j = 0;
	for (i; i < n; i++)
	{
		drugi_niz[j] = niz[i];
		j++;
	}
	print_arr(prvi_niz, x1);
	print_arr(drugi_niz, x2);
	pointer_niz[0] = prvi_niz;
	pointer_niz[1] = drugi_niz;
	return pointer_niz;
}

int main()
{
	int niz[] = { 0,20,1,19,2,18,3,17,4,16,5,15,6,14,7,13,8,12,9,11,10 };
	int n = 20;
	int** p;
	p=podijeli(niz, n);
	printf("%p\n", p[0]);
	printf("%p\n", p[1]);
	return 0;
}