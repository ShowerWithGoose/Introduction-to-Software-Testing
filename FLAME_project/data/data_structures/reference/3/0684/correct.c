#include<stdio.h>
int main()
{
	char s[105];
	int i,j,flag=0,dian,mo;
	gets(s);//meiwenti
	for(i=0;s[i]!='\0';i++)
	{
	    if(flag!=0)
		{
			s[i-1]=s[i];
		}
		else if(s[i]=='.')
	    {
	    	dian=i;flag++;
		}
	}
	mo=i-1;
	for(i=0;s[i]=='0';i++);
	{}
	if(i==mo-1)
	{
		printf("%ce%d",s[i],dian-i-1);return 0;
	}
	else 
	{
		printf("%c.",s[i]);
		for(j=i+1;j<mo;j++)
		{
			printf("%c",s[j]);
		}
		printf("e%d",dian-i-1);
	}
	return 0;
}

