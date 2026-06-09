#include <stdio.h>
#include <ctype.h>
#include<string.h>
int num_a=0,num_b=0,sum=0,num_c=0,a[1000],cnum=0,dai=0,n;
char fuhao;
int math(int a,int b,char c)
{
	if (c=='+')
		return a+b;
	else if (c=='-')
		return a-b;
	else if (c=='*')
		return a*b;
	else
		return a/b;
}
int main()
{
	char s[10000];
	char opp[1000],op2[1],op;
	int numm[1000],array[2],cnt;
	int nn=0,np=0,num;
	gets(s);
	int i=0,k=0,j=0;
	for (i=0,j=0;s[i]!='\0';i++)
		if (s[i]!=' ')
			s[j++]=s[i];
	s[j]='\0';
	for (int i=0;i<strlen(s);i++)
	{
		if(isdigit(s[i]))
		{
			num_a=s[i]-'0';
			for (k=i+1;isdigit(s[k]);k++)
			{
				num_a=num_a*10+(s[k]-'0');
			}
			i=k-1;
			numm[nn]=num_a;
			nn++;
		}
		else
		{
			opp[np]=s[i];
			np++;
		}
	}
	nn=0;
	np=0;
	array[0]=numm[nn++];
		op2[0]=opp[np++];
		if (op2[0]!='=')
		array[1]=numm[nn++];
		while(op2[0]!='=')
		{
			if(op2[0]=='*'|| op2[0]=='/')
			{
				array[0]=math(array[0],array[1],op2[0]);
				op2[0]=opp[np++];
				if(op2[0]!='=')
				array[1]=numm[nn++];
			}
			else if (op2[0]=='+'||op2[0]=='-')
			{
				op=opp[np++];
				if(op=='+'||op=='-'||op=='=')
				{
					cnt++;
					array[0]=math(array[0],array[1],op2[0]);
					op2[0]=op;
					if(op!='=')
					array[1]=numm[nn++];
				}
				else if(op!='=')
				{
				num=numm[nn++];
				array[1]=math(array[1],num,op);
				cnt--;
				}
				else
				op2[0]=op;
			}
			else
			op2[0]=op;
			if(op2[0]=='=')
			break;
		}
		
		printf("%d",array[0]);
	return 0;
}



