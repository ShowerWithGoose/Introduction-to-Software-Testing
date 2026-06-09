#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void bubbleSort(char b[][50], int n)   // n¸öÊý £¬ 0 ~ n-1 
{
	int i, j, flag;
	char hold[50];
	for (i = 0; i < n-1; i++)
	{
		flag = 0;
		for (j = 0; j < n-1-i; j++)
		{
			if ( strcmp(b[j],b[j + 1]) > 0 )
			{
				strcpy(hold, b[j]);
				strcpy(b[j], b[j + 1]);
				strcpy(b[j + 1], hold);
				flag = 1;
			}
		}
		if (0 == flag)
		break;
	}
}

int main()
{
	int i,j,k,t,s;
	char a[1000];
	char b[500][50];
	
	FILE *in;
	in = fopen("article.txt","r");
	k=0;
	while(fgets(a, 1000, in)!=NULL)
	{
		i=0;
		j=0;
		
		while(a[i]!='\0')
		{
			if( (a[i]>='a' && a[i]<='z') || ( a[i]>='A' && a[i]<='Z') )
			{
				if(a[i]<'Z') a[i]+='a'-'A';
				b[k][j] = a[i];
				j++;
			}
			else
			{
				if(j>0)
				{
					b[k][j] = '\0';
					j = 0;
					k++;
				}
			}
			i++;
		}
	}
	
	bubbleSort(b, k);
	bubbleSort(b, k);
	
	char c[50];
	
	strcpy(c, b[0]);
	t=1;
	for(i=1;i<k;i++)
	{
		
		if( strcmp(c, b[i])==0 )
		{
			t++;
		}
		else
		{
			printf("%s",c);
			printf(" %d\n",t);
			strcpy(c, b[i]);
			t=1;
		}
	}
	printf("%s",c);
	printf(" %d\n",t);
	
	return 0;
}


