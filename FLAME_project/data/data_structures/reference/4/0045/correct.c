#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char a[100000],wr[10000][10000],word[100];
int t=1;
int main()
{
	freopen("article.txt","r",stdin);
	int i,flag=0,fl=0,j,ft=1;
	while(gets(a)!=NULL)
	{
		if(ft==0)
		{
			flag++;
			fl=0;
			ft=1;
		}
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]>='A'&&a[i]<='Z')
			{
				a[i]+=32;
			}
			if(a[i]>='a'&&a[i]<='z')
			{
				ft=0;
				wr[flag][fl]=a[i];
				fl++;	
			}
			else
			{
				if(ft==0)
				{
					fl=0;
					flag++;
					ft=1;
				}
			}
		}
	}
	for(i=0;i<flag-1;i++)
	{
		for(j=0;j<flag-i-1;j++)
		{
			if(strcmp(wr[j],wr[j+1])>0)
			{
				strcpy(word,wr[j]);
				strcpy(wr[j],wr[j+1]);
				strcpy(wr[j+1],word);
			}
		}
	}
	printf("%s ",wr[0]);
	for(i=1;i<flag;i++)
	{
		if(strcmp(wr[i],wr[i-1])==0)
		{
			t++;
		}
		else
		{
			printf("%d\n%s ",t,wr[i]);
			t=1;
		}
	}
	printf("%d",t);
}



