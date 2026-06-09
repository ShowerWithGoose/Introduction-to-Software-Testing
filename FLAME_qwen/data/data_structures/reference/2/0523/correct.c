#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

char s[100000];
int num[10000];
char syb[1000];
void delet(char[]);
void getnum(char[],int[]);
void getsyb(char[],char[]);
void cul1(int[],char[]);
void cul2(int[],char[]);
int sum;

int main()
{
	gets(s);
	delet(s);
	getnum(s,num);
	getsyb(s,syb);
	cul1(num,syb);
	cul2(num,syb);
	printf("%d",sum);
	return 0;
}
void cul2(int n[],char s[])
{
	int i=0;
	sum = n[0];
	while(s[i]!='\0')
	{
		if(s[i]=='+')
		sum += n[i+1];
		else if(s[i]=='-')
		sum -= n[i+1];
		i++;
	}
	return;
}

void cul1(int n[],char s[])
{
	int i=0,tem,flag=0,tail;
	while(s[i]!='\0')
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='=')//
		{
			if(flag==1)
			{
				n[tail] = tem;
				flag = 0;
			}
			i++;
			continue;
		}
		else if(flag==0)
		{
			flag = 1;//
			tail = i;
			if(s[i]=='*')
			tem = n[i]*n[i+1];
			else
			tem = n[i]/n[i+1];
		}
		else if(flag==1)
		{
			if(s[i]=='*')
			tem *= n[i+1];
			else
			tem /= n[i+1];
		}
		i++;
	}
	return;
}
void getsyb(char s[],char d[])
{
	int i=0,tail=0;//
	while(s[i]!='\0')
	{
		if(!isdigit(s[i]))
		{
			d[tail] = s[i];
			tail++;
		}
		i++;
	}
	return;
}
void getnum(char s[],int d[])
{
	int i=0,flag=0,tail=0,tem=0;//
	while(s[i]!='\0')
	{
		if(isdigit(s[i]))
		{
			if(flag==0)
    		{
	    		tem = s[i]-'0';
		    	flag = 1;
		    }
		    else if(flag==1)
		    {
		    	tem = tem*10+s[i]-'0';
			}
		}
		else
		{
			if(flag==1)
			{
				d[tail] = tem;
				tem = 0;
				tail++;
				flag = 0;
			}
		}
		i++;
	}
	return;
}
void delet(char s[])
{
	int len,i,j;
	i=j=0;
	len = strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]!=' ')
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
	return;
 } 

