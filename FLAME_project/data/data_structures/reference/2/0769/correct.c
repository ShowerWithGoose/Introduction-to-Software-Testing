#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int digit[10000001];
char s[10000001],sign[10000001],num[1000000001];
int ismop(char c)/*mop is Minus or Plus*/
{
	if((c=='-')||(c=='+'))
	return 1;
	else 
	return 0;
}
int arithmetic(int n1,int n2,char q)
{
  if(q=='*')
  return n1*n2;
  else 
  return n1/n2;
} 
int main()
{    
	char q;
	int signum=0,n1,n2,diginum=0;
	for(int i=0;;)
	{
	scanf("%c",&q);
	if(!isspace(q))
	s[i++]=q;
	if(q=='=')
	break;
	}
	int n=strlen(s)-1;
	int j=0;/*j is the size of the number*/
	if(s[0]=='-')
	{
	num[0]='-';
	j=1;
	}
		for(int i=0;i<n;j=0)
		{
				for(;isdigit(s[i]);)
					num[j++]=s[i++];
				n1=atoi(num);
				memset(num,'\0',j);
				if((ismop(s[i]))||(i>=n))
				{
				digit[diginum++]=n1;
				sign[signum++]=s[i++];	
				}
				else
				{
				roll:
				q=s[i++];/*q is the sign of this equation right now*/
				for(j=0;isdigit(s[i]);)
					num[j++]=s[i++];
				n2=atoi(num);
				memset(num,'\0',j);
				n1=arithmetic(n1,n2,q);
				if((ismop(s[i]))||(i>=n))
				{
				digit[diginum++]=n1;
				sign[signum++]=s[i++];	
				}
				else
				goto roll;	
				}
		}
	int sum=digit[0];
	for(int i=0;i<signum;i++)
	{
	if(sign[i]=='+')
	sum+=digit[i+1];
	else
	sum-=digit[i+1];
	}
	printf("%d\n",sum);
	return 0;
}
