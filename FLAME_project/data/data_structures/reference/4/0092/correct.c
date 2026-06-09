#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int num[1000]={0},i=0,j=0;
	char word[1000][50],e,a[1000][50];
	FILE *fp;
	fp=fopen("article.txt","r");
	while((e=fgetc(fp))!=EOF)
	{
		if(e>='a'&&e<='z')
		{
			word[i][j]=e;
			j++;
		}
		else if(e>='A'&&e<='Z')
		{
			word[i][j]=e-'A'+'a';
			j++;
		}
		else
	    {
			j=0;
			i++;
		}
	}
	int n=i;
	int h,k=0;
	strcpy(a[0],word[0]);
	num[0]=1;
	k++;
	int judge=0;
	for(h=1;h<n;h++)
	{
		judge=0;
		for(j=0;j<k;j++)
		{
			if(strcmp(a[j],word[h])==0)
			{
				judge=1;
				break;
			}
		}
		if(judge==0)
		{
			strcpy(a[k],word[h]);
			num[k]++;
			k++;
		}
		if(judge==1)
		{
			num[j]++;
		}
	}
	char temp[50];
	int index;
	for(i=0;i<k;i++)
	{
		for(j=k-1;j>i;j--)
		{
			if(strcmp(a[j],a[j-1])<0)
			{
				strcpy(temp,a[j]);
				strcpy(a[j],a[j-1]);
				strcpy(a[j-1],temp);
			    index=num[j];
			    num[j]=num[j-1];
			    num[j-1]=index;
			}
		}
	}
	for(i=1;i<k;i++)
	{
		printf("%s %d\n",a[i],num[i]);
	}
}



