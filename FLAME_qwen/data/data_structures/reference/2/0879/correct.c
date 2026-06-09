#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void qspace(char*);
int calcc();
int putout();
int sum,i,sign=1; //i ÊÇ ¹â±ê 
char ch[1000];
int main()
{
    gets(ch);
    qspace(ch);
    while(1)
    {
    	int temp = calcc();
		switch (sign)
		{
			case 1 : sum+=temp;break;
			case 2 : sum-=temp;break;
			default : break;
		}
		if(ch[i] == '=')
		{
			break;
		}
		else if(ch[i] == '-')
		{
			sign = 2;
		}
		else
		{
			sign = 1;
		}
		i++;
	}
	printf("%d",sum);
	return 0;
}
void qspace(char *p)
{
	int i=0,j=0;
	while(*(p+i)!='\0')
	{
		if(*(p+i)!=' ')
		{
			*(p+(j++))=*(p+i);
		}
		i++;
	}
	*(p+j)='\0';
	return ;
}
int calcc()
{
	int temp = putout(),sign;
	int temsum = temp;
	while(1)
	{
	if(*(ch+i)!='*'&&*(ch+i)!='/')
	{
		return  temsum;
	}
	else
	{
		if(*(ch+i)=='*')
		{
			sign = 1;
		}
		else
		{
			sign = 2;
		}
		i++;
	}
	temp = putout();
	switch (sign)
	{
		case 1:temsum *= temp;break;
		case 2:temsum /= temp;break;
		default:break;
	}
	}
}
int putout()
{
	int temporarysum=0;
	while(*(ch+i)>='0'&&*(ch+i)<='9')
	{
		temporarysum=(temporarysum*10)+(*(ch+i)-'0');
		i++;
	}
	return temporarysum;
}



