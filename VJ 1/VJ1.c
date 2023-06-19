#include <stdio.h>
#include <string.h>

int mystrlen(char* str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		;
	return i;
}

char* mystrcpy(char* str1, char* str2)
{
	char* str = str1;
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str;
}

int mystrcmp(char* str1, char* str2)
{
	while (*str1 == *str2) 
	{
		if(*str1 == '\0' || *str2 == '\0')
			break;

		str1++;
		str2++;
	}


	if (*str1 == '\0' && *str2 == '\0')
		return 0;
	else if (*str1 > *str2)
		return 1;
	else
		return -1;
	
}
char* mystrcat(char* str1, char* str2)
{
	char* i = str1;
	char* j = str2;
	while (*i)
		i++;
	while (*j)
	{
		*i = *j;
		i++;
		j++;
	}
	*j = '\0';
	return str1;
}

void reverse(char* str1, char* str2,int nstr1,int nstr2)
{
	int i = 0;
	str1+=nstr1-1;
	for (i; i<nstr2; i++)
	{
		*str2 = *str1;
		str1--;
		str2++;
	}
	*str2 = '\0';
}

char* mystrstr(const char str1[], const char str2[])
{
	int i, j;
	for (i = 0; str1[i]; i++)
	{
			for (j = 0; str2[j] && str1[i + j] == str2[j]; j++);
			
			if (!str2[j])  
				return (&str1[i]);
	}
	return NULL;
}



int main()
{
	char str1[100] = "xxxabaaaaabaa";
	char str2[100] = "Ovo je novi str.";
	char str3[100] = "aaab";
	int br = 0;
	int strlen1 = mystrlen(str1);
	int strlen2 = mystrlen(str2);
	int strlen3 = mystrlen(str3);
	printf("Ovo je prvi string: %s\n", str1);
	printf("Ovo je prvi string: %s\n", str2);
	printf("Ovo je prvi string: %s\n", str3);
	printf("\nOdaberite sto zelite s stringovima:\n 1)Izracunaj duljinu prvog stringa.\n 2)Kopriaj prvi u drugi string.\n 3)Usporedi prvi i drugi string.\n 4)Kopiraj drugi string na kraj prvoga.\n 5)Preokreni drugi u prvi string.\n 6)Provjeri postoji li treci string u prvom.\n");
	scanf("%d", &br);

	switch (br)
	{
	case 1:
		printf("Koristeci string.h fun: %d\n", strlen(str1));
		printf("Koristeci my fun: %d\n", mystrlen(str1));
		break;

	case 2:

		printf("Koristeci string.h fun: %s\n", strcpy(str1, str2));
		printf("Koristeci my fun: %s\n", mystrcpy(str1, str2));
		break;

	case 3:

		printf("Koristeci string.h fun: %d\n", strcmp(str1, str2));
		printf("Koristeci my fun: %d\n", mystrcmp(str1, str2));
		break;

	case 4:

		printf("Koristeci string.h fun: %s\n", strcat(str1, str2));
		printf("Koristeci my fun: %s\n", mystrcat(str1, str2));
		break;

	case 5:

		reverse(str1, str2, strlen1, strlen2);
		printf("Koristeci my fun(nepostoji u string.h): %s\n", str2);
		break;

	case 6:

		printf("Koristeci string.h fun: %s\n", strstr(str1, str3));
		printf("Koristeci my fun: %s\n", mystrstr(str1, str3));
		break;

	default:
		printf("Unijeli se bogrešan broj.");
	}

	return 0;
}