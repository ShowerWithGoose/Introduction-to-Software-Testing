#include<stdio.h>
#include<string.h> 
char ch[2000];
char bh[2000];
int main()
{
	scanf("%s", &ch);
	int i, j, k;
	char a;
	for(i = 0; i < strlen(ch); i++)
	{
		if(ch[i] == '.')
		{
			k = i;
			break;
		}
	}
	if(ch[0] == '0' && k == 1)
	{
		for(i = 2; i < strlen(ch); i++)
		{
			if(ch[i] != '0')
			{
				j = i;
				break;
			}
		}
		int d;
		bh[0] = ch[j];
		if(j == (strlen(ch) - 1))
		{
			d = 1;
		}
		else
		{
			bh[1] = '.';
			for(i = j + 1, d = 2; i < strlen(ch); d++)
			{
				bh[d] = ch[i];
				i++;
			}
		}	
		for(i = 0; i < d; i++)
			{
				printf("%c", bh[i]);
			}
			printf("e-%d", j - 1);
	}
	else if(ch[1] == '.' && k == 1)
	{
		j = strlen(ch) - 1;
		if(ch[j] != '0')
		{
			printf("%s", ch);
		    printf("e");
		    printf("0");
		}
		else
		{
			while(ch[j] == '0')
			{
				j--;
			}
			for(k = 0; k <= j; k++)
			{
				printf("%c", ch[k]);
			}
			printf("e");
		    printf("0");
		}
	}
	else
	{
		int l;
		bh[0] = ch[0];
	    bh[1] = '.';
	    int m, n;
	    int f = 0;
	    while(ch[f] != '.')
	    {
	    	f++;
		}
	    for(m = 2, n = 1; n < strlen(ch); n++)
	    {
		   if(ch[n] != '.')
		   {
		   	    bh[m] = ch[n];
		   	    m++;
		   }
	    }
	    int g; 
	    for(g = 0; g < strlen(ch); g++)
	    {
	    	printf("%c", bh[g]);
		}
		
	    printf("e%d", f - 1);
	}
	return 0;
}

