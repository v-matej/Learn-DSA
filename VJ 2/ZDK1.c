#include <stdio.h>
#include <stdlib.h>

void print_arr(int* niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", niz[i]);
	}
	printf("\n");
}

int* podniz(int* niz, int start, int stop)
{
	int n = stop - start;
	int* new_arr;
	new_arr = (int*)malloc(n * sizeof(int));
	if (!new_arr)
		return NULL;
	int j = 0;
	for (int i = start; i < stop; i++)
	{
		new_arr[j] = niz[i];
		j++;
	}
	return new_arr;

}

int main()
{
	int niz[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int start = 5;
	int stop = 15;
	int* p;
	int n = stop - start;
	p = podniz(niz, start, stop);
	print_arr(p, n);
	free(p);
	return 0;
}