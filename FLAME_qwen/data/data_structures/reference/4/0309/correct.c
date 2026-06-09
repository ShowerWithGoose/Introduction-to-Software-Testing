#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
void lower(char * ch, char * sh);
void swap(char *a,char *b);
int main()
{
	char s[1000][100], S[1000][100], S1[1000][100];
    FILE* in;
    in = fopen("article.txt","r");
    //in = fopen("C:\\Desktop\\article.txt","r");
    char ch;
    int n=0, u=0, num[1000], num1[1000]={0}, cishu=0;
    for(int i=0;i<1000;i++)
    	num[i]=1;
	while((ch = fgetc(in))!=EOF)//不能写成char ch=fgetc(fp)否则该语句不仅如此循环 
	{
		if((ch<='Z'&&ch>='A')||(ch<='z'&&ch>='a'))
		{
			s[n][u]=ch;
			u++;
		}
		else
		{
			s[n][u]='\0';
			n++;
			u=0;
		}
	}
	n++;
	for(int i=0;i<n;i++)
		lower(s[i],S[i]);
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-2;j>=i;j--)
		{
		   	if(strcmp(S[j],S[j+1])>0)
		    {
		    	swap(S[j],S[j+1]);
			}
		}
	}
	
	for(int j=0;j<n-1;j++)
	{
		if(strcmp(S[j],S[j+1])==0)
		{
			S[j][0]='\0';
			num[j+1]+=num[j];
		}
	}
	/*for(int i=0;i<n;i++)
		printf("%s %d\n",S[i],num[i]);*/
	for(int i=0,j=0;i<n;i++)
	{
		if(S[i][0]!='\0')
		{
			strcpy(S1[j],S[i]);
			num1[j]=num[i];
			j++;
			cishu=j;
		}
	}
	for(int i=0;i<cishu;i++)
	{
		printf("%s %d\n",S1[i],num1[i]);
	}
	return 0;
}
void lower(char * ch, char * sh)
{
	int L;
	L=strlen(ch);
	for(int i=0;i<L;i++)
	{
		if(ch[i]>='A'&&ch[i]<='Z')
			sh[i]=ch[i]+'a'-'A';
		else
			sh[i]=ch[i];
	}
	sh[L]='\0';
}
void swap(char *a,char *b)
{
	char s[200];
	strcpy(s,a),strcpy(a,b),strcpy(b,s);
}

