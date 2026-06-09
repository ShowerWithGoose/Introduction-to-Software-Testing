#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 201
struct s{
	int lev;
	char op;
};
struct s opstack[MAX];
int  num[MAX];
int n=0,option ;
int pnum;
int popstack(int a[],struct s b[],int c,int d)
{
	if(b[c].op=='+')
		return a[d]+a[d-1];
	if(b[c].op=='-')
		return a[d-1]-a[d];
	if(b[c].op=='*')
		return a[d]*a[d-1];
	if(b[c].op=='/')
		return a[d-1]/a[d];
}
int main()
{
    int optop=-1,numtop=-1;
	char c[101];
	opstack[++optop].lev=-1;
	gets(c);
    for(int i=0;c[i]!='=';i++)
	{
		if(isdigit(c[i]))
		{
			while(isdigit(c[i]))
			{	n=n*10+c[i]-'0';
			i++;
			}
			num[++numtop]=(double)n;
				n=0;
			i--;
		}
		else if(c[i]!=' ')
		{
			if(c[i]=='+'||c[i]=='-')
				option=1;
			else if(c[i]=='*'||c[i]=='/')
				option=2;
			else if(c[i]=='(')
				option=4;
			else if(c[i]==')')
				option=5;
			if(option==5)
			{
				while(opstack[optop].lev!=4)
				{
					pnum=popstack(num,opstack,optop,numtop);
					num[--numtop]=pnum;
					optop--;
					
						
				}
				optop--;
				continue;
			}
			if(option>opstack[optop].lev)
			{
				opstack[++optop].op=c[i];
				opstack[optop].lev=option;
			}
			else if(	option<=opstack[optop].lev&&opstack[optop].lev!=4)
			{
				pnum=popstack(num,opstack,optop,numtop);
				num[--numtop]=pnum;
				opstack[optop].op=c[i];
				opstack[optop].lev=option;

			
			}
			else if(option<=opstack[optop].lev&&opstack[optop].lev==4)
			{
				opstack[++optop].op=c[i];
				opstack[optop].lev=option;
			}
		   
		}
	}

	int j=1;//2+3  010
	for(int i=1;i<=optop;i++)
	{
		if(opstack[optop].op=='*'||opstack[optop].op=='/')
		{num[numtop-1]=popstack(num,opstack,optop,numtop);
			optop--;}
		if(optop==0)
			break;
		pnum=popstack(num,opstack,i,j);
		num[j++]=pnum;
	
}
	printf("%d",num[j-1]);
}


