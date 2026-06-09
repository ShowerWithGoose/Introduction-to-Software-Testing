#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
char str[2000];
char string1[28]="abcdefghijklmnopqrstuvwxyz";
char string2[28]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char string3[11]="0123456789";
int main()
{
	gets(str);
	int len=strlen(str);
	int pot=-1;
	for(int i=0;i<len;i++)
	{
		if(i!=pot)
		printf("%c",str[i]);
		if(str[i+1]=='-'&&islower(str[i])!=0&&islower(str[i+2])!=0&&str[i+2]-str[i]>0)
		{
			pot=i+1;
			int b=str[i]-'a'+1;
			int c=str[i+2]-'a';
			str[i+1]=string1[b];
			printf("%c",str[i+1]);
			for(int j=b+1;j<c;j++)
			printf("%c",string1[j]);
		}
		else if(str[i+1]=='-'&&isupper(str[i])!=0&&isupper(str[i+2])!=0&&str[i+2]-str[i]>0)
		{
			pot=i+1;
			int b=str[i]-'A'+1;
			int c=str[i+2]-'A';
			str[i+1]=string2[b];
			printf("%c",str[i+1]);
			for(int j=b+1;j<c;j++)
			printf("%c",string2[j]);
		}
		else if(str[i+1]=='-'&&isdigit(str[i])!=0&&isdigit(str[i+2])!=0&&str[i+2]-str[i]>0)
		{
			pot=i+1;
			int b=str[i]-'0'+1;
			int c=str[i+2]-'0';
			str[i+1]=string3[b];
			printf("%c",str[i+1]);
			for(int j=b+1;j<c;j++)
			printf("%c",string3[j]);
		}
	} 
    return 0;
}


