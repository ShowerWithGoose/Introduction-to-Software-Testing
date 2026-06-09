#include<stdio.h>
char num[200];
void ks(char* str ,char a)
{
	char* p=str;
	char* q=str;
	while (*q)
	{
     	if(*q!=a)
		{
  			*p++=*q;
		}
		q++;
	}
 	*p='\0';

}
int main()
{
	int d_p=0,fi_p=0;
	gets(num);
	int e; 
	int lp,lp1;
	int df=0,nf=0;
	for(lp=0;num[lp]!='\0';lp++)
	{
		if(num[lp]=='.')
		{
			df=1;
			break;
		}
	}
	if(df)
	{
		d_p=lp;
	}
	else
	{
		d_p=strlen(num)-1;
	}
	for(lp=0;;lp++)
	{
		if(isdigit(num[lp])&&num[lp]!='0')
		{
			nf=1;
			break;
		}
		if(num[lp]=='\0')
		{
			break;
		}
	}
	if(nf)
	{
		fi_p=lp;
	}
	else
	{
		fi_p=strlen(num)-1;
	}
	ks(num,'.');
	for(lp1=strlen(num)-1;lp1>fi_p&&num[lp1]=='0';lp1--)
	{
		if(num[lp1]=='0')
		{
			num[lp1]=' ';
		}
	}
	ks(num,' ');
	for(lp1=0;lp1<fi_p&&num[lp1]=='0';lp1++)
	{
	}
	if(num[lp1+1]=='\0')
	{
		printf("%c",num[lp1]);
	}
	else
	{
		printf("%c.",num[lp1]);
		while(1)
		{
			lp1++;
			if(num[lp1]=='\0')
			{
				break;
			}
			printf("%c",num[lp1]);
		}
	}
	if(fi_p>=d_p)
	{
		printf("e%d",d_p-fi_p);
	}
	else
	{
		printf("e%d",d_p-fi_p-1);
	}

	
	return 0;
}

