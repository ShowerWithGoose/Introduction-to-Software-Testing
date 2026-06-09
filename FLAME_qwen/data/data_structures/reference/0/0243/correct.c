#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 110
int judge(char a,char b)
{
	if(isdigit(a) && isdigit(b))
	return 1;
	else if(islower(a) && islower(b))
	return 1;
	else if(isupper(a) && isupper(b))
	return 1;
	return 0;
}

int main()
{
	char a[N],t;
	int i,len;
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(i==len-1 || a[i+1]!='-')
		{
			printf("%c",a[i]);
		}
		else
		{
			if(a[i]<a[i+2] && judge(a[i],a[i+2]))
			{
				for(t=a[i];t<a[i+2];++t)
				{
					printf("%c",t);
				}
				i++;
			}
			else
			{
				printf("%c-",a[i++]);
			 } 
		}
	}
	return 0;
}


