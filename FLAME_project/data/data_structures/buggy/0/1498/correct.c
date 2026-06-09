#include<stdio.h>

void expand(char p,char q)
{
	int i = 0;
	int k=p+1;
	for (i = 0; i <(q - p); i++)
	{
		printf("%c", k);
		k++;
	}
}

int toexpand(char p, char q)
{
	if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9'))
		return 1;
	else
		return 0;
}
 
int main(void)
{
	char A[50] ;
	gets(A);
	int i = 0;
	int k = 0;
	while (A[i] != '\0')
	{
		if (A[i] == '-')
		{
			k = toexpand(A[i - 1], A[i + 1]);
			if (k == 1)
			{
				expand(A[i - 1], A[i + 1]);
				i = i + 1;
			}
			if(k==0)
				printf("%c",A[i]);
		}
		else
			printf("%c", A[i]);
		i++;
	}
	return 0;
}
