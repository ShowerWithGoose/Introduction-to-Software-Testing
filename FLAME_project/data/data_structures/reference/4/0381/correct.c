#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
char a[105][20];
void tihuan(char a[][20],int n);
int main()
{	
	char ch;
	int i=0,j=0,n=0;
	FILE *in;
	in=fopen("article.txt","r");
	ch=fgetc(in);
	while(ch!=EOF)
	{
		if(ispunct(ch)||isspace(ch))
		{
			a[i][j]='\0';
			j=0;
			i++;
		}
		else if(isalpha(ch))
		{
			a[i][j]=ch;
			j++;
		}
		ch=fgetc(in);
	}
	n=i;
	for(i=0;i<n;i++)
		for(j=0;j<strlen(a[i]);j++)
			a[i][j]=tolower(a[i][j]);
	int num[105]={0},flag=0;
	for(i=0;i<n;i++)
		tihuan(a,n);
	for(i=0;i<n;i++)
	{
		flag=0;
		num[i]=1;
		for(j=i+1;j<n;j++)
		{	
			if(a[j][0]=='\0')
				continue;
			if(!strcmp(a[i],a[j]))
			{
				num[i]++;
				a[j][0]='\0';
				flag=1;
			}
			else
			{
				if(flag==1)
					i=j-1;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
		if(a[i][0]!='\0')
			printf("%s %d\n",a[i],num[i]);
	fclose(in);
	return 0;	
}
void tihuan(char a[][20],int n)
{
	char temp[20];
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(strcmp(a[i],a[j])>0)
			{
				strcpy(temp,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],temp);
			}
}



