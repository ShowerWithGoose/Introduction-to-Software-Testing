#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char m[100][100];
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	int i=0,j=0,p=0;
	int number[100]={0};
	char a;
	a=fgetc(fp);
	while(a!=EOF)
	{
		if(isalpha(a))
		{
			m[i][j]=a;
			j++;
		}
		if(isspace(a)||ispunct(a))
		{
			m[i][j]='\0';
			i++;
			j=0;
		}
		a=fgetc(fp);
	}
	int n=0;
	for(n=0;n<i;n++)
		{
			for(j=0;j<strlen(m[n]);j++)
			m[n][j]=tolower(m[n][j]);
		}			
	for(n=0;n<i;n++)
	{
		replace(m,i);
	}
	for(n=0;n<i;n++)
	{
		p=0;
		number[n]=1;
		for(j=n+1;j<i;j++)
		{
			if(!strcmp(m[n],m[j]))
			{
				p=1;
				number[n]++;
				m[j][0]='\0';
			}
			if(m[j][0]!='\0')
			{
				if(p==1)
				n=j-1;
				break;
			}
		}
	}
	for(n=0;n<i;n++)
	{
		if(m[n][0]!='\0')
		printf("%s %d\n",m[n],number[n]);
	}
	fclose(fp);
	return 0;
}
void replace(char m[][100],int i)
{
	char c[100];
	int m1,m2;
	for(m1=0;m1<i;m1++)
	{
		for(m2=m1+1;m2<i;m2++)
		{
			if(strcmp(m[m1],m[m2])>0)
			{
				strcpy(c,m[m2]);
				strcpy(m[m2],m[m1]);
				strcpy(m[m1],c);
			}
		}
	}
}


