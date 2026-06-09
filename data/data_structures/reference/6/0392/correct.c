#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int delect(char *str,int *buf)
{
	int i,j=0,Buf=0,k=0;
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
				buf[j]=-Buf;
				j++;
				Buf=0;
				k=0;
			}
			else
			{
				buf[j]=Buf;
				j++;
				Buf=0;
			}
		}
	}
	return j;
}
char op[1000];
int stack[100],buf[500];
int main()
{
	fgets(op,1000,stdin);
	int i,j=0,n;
	n=delect(op,buf);
	for(i=0;i<n;i++)
	{
		if(buf[i]==1)
		{
			if(j>=100)
			printf("error ");
			else
			{
				stack[j]=buf[i+1];
				j++;
			}
			i++;
		}
		else if(buf[i]==0)
		{
			if(j<=0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",stack[j-1]);
				j--;
			}
		}
		else
		break;
	}
	return 0;
}

