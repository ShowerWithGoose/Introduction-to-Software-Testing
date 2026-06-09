#include<stdio.h>

void ks(char* str)
{
	char* p=str;
	char* q=str;
	while (*q)
	{
     	if(*q!=' ')
		{
  			*p++=*q;
		}
		q++;
	}
 	*p='\0';

}

char a[10000];
int main()
{
	int f=0,ans=0,ans1=0;
	gets(a);
	ks(a);
	int lp=0;
	int sum=0; 
	while(isdigit(a[lp]))
	{
		
		ans=ans*10+a[lp]-'0';
		lp++;
	}
	while(1)
	{
		switch(a[lp])
		{
			case '+':
				f=1;
				break;
			case'-':
				f=2;
				break;
			case'*':
				f=3;
				break;
			case'/':
				f=4;
				break;
			case'=':
				f=5;
				break;
		}
		lp++;
		if(f==5)
		{
			printf("%d",sum+ans);
			break;
		}
		else
		{
			if(f==1||f==2)
			{
				sum =sum+ans;
				ans=0;
				while(isdigit(a[lp]))
				{
					ans=ans*10+a[lp]-'0';
					lp++;
				}
				if(f==2)
				{
					ans=-ans;
				}				
			}
			if(f==3||f==4)
			{
				while(isdigit(a[lp]))
				{
					ans1=ans1*10+a[lp]-'0';
					lp++;
				}
				if(f==3)
				ans=ans*ans1;
				else
				ans=ans/ans1;
				ans1=0;
			}
		}
	}
}

