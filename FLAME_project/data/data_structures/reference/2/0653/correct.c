#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main (void)
{
	char a[1001]="\0",b[1001]="\0",s[1001]="\0";
	int len,i,n=0,c[1001]={0},m=0,k=0,w=0,z=0,LEN;
	c[0]=0;
	gets(a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]==' ')continue;
		else b[n++]=a[i];
	}
	LEN=strlen(b);
	for(i=0;i<LEN;i++)
	{
		if(b[i]<'0'||b[i]>'9')
		s[m++]=b[i];
		else 
		{
		for(i;b[i]>='0'&&b[i]<='9';i++)
		{ 
			c[k]=c[k]*10+b[i]-'0';
		}	
		k++;
		i--;	
		}
	}
	for(i=0;i<strlen(s);i++)
	{
	 if(s[i]=='*'){
    c[i+1]=c[i]*c[i+1];
    c[i]=-1;
   }
   else if(s[i]=='/'){
    c[i+1]=c[i]/c[i+1];
    c[i]=-1;						
	 }	
	}
	int C[1001]={0};
	char S[1001]="\0";
	for(i=0;i<strlen(a);i++)
	{
	if(c[i]!=-1)C[w++]=c[i];
	if(s[i]=='+'||s[i]=='-')S[z++]=s[i];	
	}
	int sum=C[0];
	for(i=0;i<strlen(S);i++)
	{
		if(S[i]=='+')sum=sum+C[i+1];
		else sum=sum-C[i+1];
	}
	printf("%d\n",sum);
	return 0;
} 



