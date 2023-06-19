
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void print_arr(int* niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
	printf("\n");
}

int* filtriraj(int* niz, int n, int th, int* nth)
{
	int br=0;
	int j = 0;
	int* new_arr;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] > th)
			br++;
	}
	new_arr = (int*)malloc(br*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		if (niz[i] > th)
		{
			new_arr[j] = niz[i];
			j++;
		}
	}
	*nth = br;
	return new_arr;
}

int main()
{
	int niz[] = { 0,20,1,19,2,18,3,17,4,16,5,15,6,14,7,13,8,12,9,11,10};
	int n=20;
	int th = 10;
	int nth;
	int* p;
	p=filtriraj(niz, n, th, &nth);
	printf("%d\n", nth);
	print_arr(p, nth);
	return 0;
}