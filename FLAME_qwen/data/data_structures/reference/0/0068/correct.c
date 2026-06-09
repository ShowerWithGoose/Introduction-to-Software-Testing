#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>//øÏ≈≈ 
#define eps 1e-8
#define pi 3.14
#define eof EOF
int  panduan(int i);
char original[1000],new[10000];
int main()
{
	int i=0;char j;
	gets(original);
	
	for(i=0;original[i]!='\0';i++)
	{
	if(original[i]!='-')
	printf("%c",original[i]); 
	else 
	{
	j=panduan(i);
	if(j==0)
	printf("-");
	else if(j==1)
	{for(j=original[i-1]+1;j<original[i+1];j++)
	printf("%c",j);
	}
	}
	}
	
	
}

int  panduan(int i)
{	
	if(((original[i-1]<='9'&&original[i-1]>='0')&&(original[i+1]<='9'&&original[i+1]>='0'))||
	((original[i-1]<='z'&&original[i-1]>='a')&&(original[i+1]<='z'&&original[i+1]>='a'))||
	((original[i-1]<='Z'&&original[i-1]>='A')&&(original[i+1]<='Z'&&original[i+1]>='A')))
	{
		if(original[i-1]<original[i+1])
		return 1;
		else
		return 0;
		
	}
	else 
	return 0;
	
}

//for(j=original[i-1];j<(original[i+1]-original[i-1]);j++)
//		printf("%c",j);



