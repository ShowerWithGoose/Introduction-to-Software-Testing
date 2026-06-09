#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int delect(char *str,int *buf)
{
	int i,top=0,Buf=0,k=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='-')
		k=1;
		else if(str[i]>='0'&&str[i]<='9')
		Buf=Buf*10+str[i]-'0';
		else
		{
			if(k==1)
			{
				buf[top]=-Buf;
				top++;
				Buf=0;
				k=0;
			}
			else
			{
				buf[top]=Buf;
				top++;
				Buf=0;
			}
		}
	}
	return top;
}
char op[1000];
int stack[100],buf[500];
int main()
{
	fgets(op,1000,stdin);
	int i,top=0,op;
	op=delect(op,buf);
	for(i=0;i<op;i++)
	{
		if(buf[i]==1)
		{
			if(top>=100)
			printf("error ");
			else
			{
				stack[top]=buf[i+1];
				top++;
			}
			i++;
		}
		else if(buf[i]==0)
		{
			if(top<=0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",stack[top-1]);
				top--;
			}
		}
		else
		break;
	}
	return 0;
}

