
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIGRAND (rand()*rand())


void shuffle(int* niz, int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = i + BIGRAND % (n - i);
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* generate(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	if (!niz)
		return NULL;
	niz[0] = 1 + BIGRAND % 3;
	for (int i = 1; i < n; i++)
		niz[i] = niz[i - 1] + BIGRAND % 3 + 1;
	shuffle(niz, n);
	return niz;
}

int myCmp(const void* a, const void* b)
{
	return (*((int*)a) - *((int*)b));
}

int MAX_arr(int* arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
int MIN_int(int a, int b)
{
	if (a < b) return a;
	else return b;
}

int presjek(int* skup1,int*skup2,int n)
{
	int br = 0;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (skup1[i] == skup2[j])
				br++;
		}
	}
	return br;
}

int presjek_jedan_sortiran(int* skup1, int* skup2, int n)
{
	qsort(skup2, n, sizeof(int), myCmp);
	int br = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (bsearch(&skup1[i], skup2, n, sizeof(int), myCmp)!=NULL)
			br++;
	}
	return br;
}

int presjek_oba_sortirana(int* skup1, int* skup2, int n)
{
	qsort(skup1, n, sizeof(int), myCmp);
	qsort(skup2, n, sizeof(int), myCmp);
	printf("\n");
	int br = 0;
	int i=0, j=0;
	while (i < n || j < n)
	{
		if (skup1[i] == skup2[j])
		{
			i++;
			j++;
			br++;
		}
		else if (skup1[i] < skup2[j])
			i++;
		else
			j++;
	}
	return br;
}

int	presjek_po_indeksima(int* skup1, int* skup2,int n)
{
	int i,j,br=0;
	const int max_1 = MAX_arr(skup1,n);
	const int max_2 = MAX_arr(skup2, n);
	int* bin_skup1 = (int*)malloc(sizeof(int) * max_1);
	int* bin_skup2 = (int*)malloc(sizeof(int) * max_2);
	for (i = 0; i < max_1 ; i++)
	{
		bin_skup1[i] = 0;
	}
	for (i = 0; i < max_2 ; i++)
	{
		bin_skup2[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		bin_skup1[skup1[i]] = 1;
	}
	for (i = 0; i < n; i++)
	{
		bin_skup2[skup2[i]] = 1;
	}
	int min = MIN_int(max_1, max_2);
	for (i = 0; i <= min; i++)
	{
		if (bin_skup1[i] == 1 && bin_skup2[i]==1)
		{
			br++;
		}
	}
	return br;
}


void main() {
	int ST1=0, ET1=0;
	int ST2=0, ET2=0;
	int ST3=0, ET3=0;
	int ST4=0, ET4=0;

	srand(time(NULL));
	int N = 10000;
	int n;
	
	/*
	for (int i = 0; i < 10; i++) {
		printf("%d \t", skup1[i]);
		printf("%d \n", skup2[i]);
	}
	printf("\n");
	*/

	for (N; N < 300000; N += 30000) {
		int* skup1 = generate(N);
		int* skup2 = generate(N);
		printf("%d\n", N);
		ST4 = clock();
		n = presjek_po_indeksima(skup1, skup2, N);
		ET4 = clock();
		printf("Broj presjeka: %d \n", n);
		printf("Vrijeme trajanja: %f\n", (((float)(ET4 - ST4)) / CLOCKS_PER_SEC));
		n = 0;
	}
	/*
	ST1 = clock();
	n = presjek(skup1, skup2, N);
	ET1 = clock();
	printf("Broj presjeka: %d \n", n);
	printf("Vrijeme trajanja: %f\n", (((float)(ET1 - ST1)) / CLOCKS_PER_SEC));
	ST2 = clock();
	n = presjek_jedan_sortiran(skup1, skup2, N);
	ET2 = clock();
	printf("Broj presjeka: %d \n", n);
	printf("Vrijeme trajanja: %f\n", (((float)(ET2 - ST2)) / CLOCKS_PER_SEC));
	n = 0;
	ST3 = clock();
	n = presjek_oba_sortirana(skup1, skup2, N);
	ET3 = clock();
	printf("Broj presjeka: %d \n", n);
	printf("Vrijeme trajanja: %f\n", (((float)(ET3 - ST3)) / CLOCKS_PER_SEC));
	n = 0;
	ST4 = clock();
	n = presjek_po_indeksima(skup1, skup2,N);
	ET4 = clock();
	printf("Broj presjeka: %d \n", n);
	printf("Vrijeme trajanja: %f\n", (((float)(ET4 - ST4)) / CLOCKS_PER_SEC));
	*/
	return 0;
}
