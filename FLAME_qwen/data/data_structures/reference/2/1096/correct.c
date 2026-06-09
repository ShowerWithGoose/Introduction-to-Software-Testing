#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<memory.h>
//1,+;2,-;3,+(*);4,+(/);5,-(*);6,-(/);
int main()
{
	char w[100000],s[100000],*p,*q;
	int a,b,ans=0,op=1,first=0,i,j;
	gets(w);
	for(i=0,j=0;i<strlen(w);i++)
	{
		if(w[i]!=' ')
		{
			s[j]=w[i];
			j++;
		}
	}
	p=s;
	for(;*p!='\0';)
	{
		if(isdigit(*p))
		{
			a=0;
			for(q=p;isdigit(*q);q++)
			{
				a*=10;
				a+=(*q-'0');
			}
			if(first==0)
			{
				b=a;
			}
			else 
			{
				if(op==3||op==5)b*=a;
				else b/=a;
			}
			if(*q=='+'||*q=='-'||*q=='=')
			{
				if(op==1||op==3||op==4)ans+=b;
				
				else if(op==2||op==5||op==6)ans-=b;
				
				if(*q=='='){
					printf("%d",ans);
					return 0;
				}
				first=0;
				if(*q=='+')op=1;
				else op=2;
			}
			else if(*q=='/'||*q=='*')
			{
				if(op==1){
					if(*q=='/')op=4;
					else if(*q=='*')op=3;
				}
				else if(op==2){
					if(*q=='/')op=6;
					else if(*q=='*')op=5;
				}
				else if(op==3||op==5){
					if(*q=='/')op++;
				}
				else if(op==4||op==6){
					if(*q=='*')op--;
				}
				first=1;
			}
			p=q+1;
		}
	}
	return 0;
}



