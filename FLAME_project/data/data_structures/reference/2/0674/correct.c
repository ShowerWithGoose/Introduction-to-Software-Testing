#include <stdio.h>
char string[100];
int number[100];
int re[100];
char sign[100];	
int main()
{
	int non = 0;
	int m = 0;
	int n = 0;
	int f = 0;
	int i = 0;
	gets(string);
	for (int i = 0; string[i] !='\0'; ++i)
	{		
		if (string[i]>='0'&&string[i]<='9')
		{
			number[m] *= 10;
			number[m] += (string[i] - '0');
		}
		else if (string[i]!=' ')
		{
			sign[n++] = string[i];
			m++;
		}
	}
	m = 0;
	sign[n] ='\0';
	while(sign[i]!='\0')	
	{		
		while (sign[i]=='*'||sign[i]=='/')
		{
			
			if (sign[i]=='*')
			{
				i++;
				number[m] *= number[i];			
			}
			else if (sign[i]=='/')
			{
				i++;
				number[m] /= number[i];
			}
		}
		re[f] = number[m];
		f++;
		i++;
		m=i;		
	}
	non += re[0];
	m = 1;
	for (i = 0; sign[i]!='\0'; ++i)
	{		
		if (sign[i]=='+')
		{
			non += re[m];
			m++;
		}
		else if (sign[i]=='-')
		{
			non -= re[m];
			m++;
		}
	}
	printf("%d\n", non);
	return 0;
}
