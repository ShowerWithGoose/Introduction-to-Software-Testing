#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(type,a,b) {type t=a;a=b;b=t;}
int main()
{	char A[1005];
	gets(A);
	char B[1005];
	int i,j;
	
	char * p1;//
	for(i=0;;i++)
	{if(A[i]!='0'&&A[i]!='.')
		{
		p1=&A[i];break;}
	}
	char * p2;
	for(i=0;;i++)
	{	if(A[i]=='.')
	{p2=&A[i];break;
	}
	}
	
	char D[1005];
	memset(D,'\0',1);

	for(i=1,j=0;*(p1+i)!='\0';i++)
	{	if(*(p1+i)!='.')
		{
		D[j]=*(p1+i);j++;}
			
	}
	int E;
	int len=0;
	
	
	if(A[0]=='0')
	E=p2-p1;
	else E=p2-p1-1;
	if(D[0]!='\0') 
	{
	
	
	printf("%d.%se%d",*p1-'0',D,E);}
	else printf("%de%d",*p1-'0',E);
	
	return 0;}
	
	
	
	
	
	
	
	
	
	
	
	

