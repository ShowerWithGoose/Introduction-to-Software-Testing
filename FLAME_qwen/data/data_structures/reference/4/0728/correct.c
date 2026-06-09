#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
char word;
char sum[200][30];
char hold[30];
int num[200]; 
int main()
{
	FILE *open;
	open=fopen("article.txt","r");
	int i=0,j=0;
	word=fgetc(open);
	while(word!=EOF)
	{
		if((word>='a'&&word<='z'))
		{
			sum[i][j]=word;
			j++;
		}
		else if(word>='A'&&word<='Z')
		{
			word=tolower(word);
			sum[i][j]=word;
			j++;
		}
		else
		{
			sum[i][j]='\0';
			j=0;
			i++;
		}
		word=fgetc(open);
	}
	int k=0,l=0;
	for(k=0;k<i;k++)
	{
		for(l=k+1;l<i;l++)
		{
			if(strcmp(sum[k],sum[l])>0)
			{
				strcpy(hold,sum[k]);
				strcpy(sum[k],sum[l]);
				strcpy(sum[l],hold);
			}
		}
	}
	int n=0;
	for(k=0;k<i;k++)
	{
		if(sum[k][0]!='\0')
		{
			for(l=k+1;l<i;l++)
			{
				if(strcmp(sum[k],sum[l])==0)
				{
					num[k]=num[k]+1;
					sum[l][0]='\0';
				}
			}
		}
	}
	for(n=0;n<=i;n++)
	{
		if(sum[n][0]!='\0')
		{
			printf("%s %d\n",sum[n],num[n]+1);
		}
	}
	fclose(open); 
	return 0;
}

