#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]="";
	gets(s);
	
	if(s[0]=='0')
	{
		int i,a,b;
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]!='0'&&s[i]!='.')
			{
				a=i;
				b=a;
				break;
			}
		}
		if(a==strlen(s)-1)
		printf("%c",s[a]);
		else
		{
			printf("%c.",s[a]);
			a++;
			do{printf("%c",s[a]);
			a++;
			}while(a<strlen(s));
		}
		printf("e-%d",b-1);
	}
	else if(s[0]=='-')
	{
		if(s[1]=='0')
		{
			int i,a,b;
			for(i=0;i<strlen(s);i++)
			{
				if(s[i]!='0'&&s[i]!='.'&&s[i]!='-')
				{
					a=i;
					b=a;
					break;
				}
			}
			if(a==strlen(s)-1)
			printf("-%c",s[a]);
			else
			{
				printf("-%c.",s[a]);
				a++;
				do{printf("%c",s[a]);
				a++;
				}while(a<strlen(s));
			}
			printf("e-%d",b-2);
		}
		else
		{
			int j,b;
			for(j=0;j<strlen(s);j++)
			{
				if(s[j]=='.')
				{
					b=j;
					break;
				}
			}
			int i,a,c,flag1=0,flag2 = 0;
			for(i=strlen(s)-1;i>b;i--)
			{
				if(s[i]!='0')
				{
					a=i;
					flag1 = 1;
					break;
				}
			}
			for(i=b-1;i>1;i--)
			{
				if(s[i]!='0')
				{
					c=i;
					flag2 = 1;
					break;
				}
			}
			if(flag1==1)
			{
				int p=2;
				printf("-%c.",s[1]);
				do{if(p==b)
				{
					p++;
					continue;
				}
				printf("%c",s[p]);
				p++;
				}while(p<=a);
				printf("e%d",b-2);
			}
			else if(flag1==0)
			{
				int q=2;
				if(flag2==0)
				printf("-%ce%d",s[1],b-2);
				else
				{
					printf("-%c.",s[1]);
					do{printf("%c",s[q]);
					q++;}while(q<=c);
					printf("e%d",b-2);
				}
			}
		}
	}
	else
	{
		int j,b;
		for(j=0;j<strlen(s);j++)
		{
			if(s[j]=='.')
			{
				b=j;
				break;
			}
		}
		int i,a,c,flag1=0,flag2 = 0;
		for(i=strlen(s)-1;i>b;i--)
		{
			if(s[i]!='0')
			{
				a=i;
				flag1 = 1;
				break;
			}
		}
		for(i=b-1;i>1;i--)
		{
			if(s[i]!='0')
			{
				c=i;
				flag2 = 1;
				break;
			}
		}
		if(flag1==1)
		{
			int p=1;
			printf("%c.",s[0]);
			do{if(p==b)
			{
				p++;
				continue;
			}
			printf("%c",s[p]);
			p++;
			}while(p<=a);
			printf("e%d",b-1);
		}
		else if(flag1==0)
		{
			int q=1;
			if(flag2==0)
			printf("%ce%d",s[0],b-2);
			else
			{
				printf("%c.",s[0]);
				do{printf("%c",s[q]);
				q++;}while(q<=c);
				printf("e%d",b-1);
			}
		}
	}
	return 0;
}

