#include<stdio.h>
char str[210];int l,n,count;
int main()
{
	str[0]=getchar();int i;
	while(str[l]!='\n')
	{
		if(str[l]=='.')
		{
			if(l==1)
			{
				if(str[0]=='0')n=1;
				else n=2;	
			}
			else count=l-1;
		}
		str[++l]=getchar();
	}//printf("%d\n",fl);
	for(i=l-1;i>=0;i--)
	{
		if(str[i]=='0')str[i]='\0';
		else if(str[i]=='.')continue;
		else break;
	}
	if(n==0)
	{
		printf("%c",str[0]);int f=0;
		for(i=1;i<l;i++)
		{if(str[i]=='\0')break;
			if(str[i]!='.')
			{
				if(!f){f=1;printf(".");}
				printf("%c",str[i]);
			}
		}
			printf("e%d",count);
	}
	if(n==2){str[l]='\0';printf("%se0",str);} 
	if(n==1)
	{int pos,a=l-1;
		for(i=0;i<l;i++)
			if(str[i]!='0'&&str[i]!='.')
			{pos=i;break;}printf("%c",str[pos]);
		for(i=pos+1;i<l;i++)
		{
			if(str[i]=='\0'){a=i-1;break;}
			if(i==pos+1)printf(".");printf("%c",str[i]);
		}printf("e-%d",pos-1);
	}
}



