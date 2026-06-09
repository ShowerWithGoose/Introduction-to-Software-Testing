#include<stdio.h>
char str[210];int n,fl,q;
int main()
{
	str[0]=getchar();int i;
	while(str[n]!='\n')
	{
		if(str[n]=='.')
		{
			if(n==1)
			{
				if(str[0]=='0')fl=1;
				else fl=2;	
			}
			else q=n-1;
		}
		str[++n]=getchar();
	}//printf("%d\n",fl);
	for(i=n-1;i>=0;i--)
	{
		if(str[i]=='0')str[i]='\0';
		else if(str[i]=='.')continue;
		else break;
	}
	if(fl==0)
	{
		printf("%c",str[0]);int f=0;
		for(i=1;i<n;i++)
		{if(str[i]=='\0')break;
			if(str[i]!='.')
			{
				if(!f){f=1;printf(".");}
				printf("%c",str[i]);
			}
		}
			printf("e%d",q);
	}
	if(fl==2){str[n]='\0';printf("%se0",str);} 
	if(fl==1)
	{int pos,a=n-1;
		for(i=0;i<n;i++)
			if(str[i]!='0'&&str[i]!='.')
			{pos=i;break;}printf("%c",str[pos]);
		for(i=pos+1;i<n;i++)
		{
			if(str[i]=='\0'){a=i-1;break;}
			if(i==pos+1)printf(".");printf("%c",str[i]);
		}printf("e-%d",pos-1);
	}
}



