#include<stdio.h>
#include<math.h>
#include<string.h>
char s[150];
int main()
{
	gets(s);
	int a=strlen(s),temp,flag,hold;
	if(s[0]=='-')
	{
		flag=0;
	}
	else
	flag=1;
	

	
	for(int i=0;i<a;i++)
	{
		if(s[i]=='.')
		{
			temp=i;//整数0-i位 负数1-i 
		}
	}

	
	if(flag==1)//+
	{
		if(temp==1&&s[0]=='0')//chun小数 
		{
			for(int i=temp+1;i<a;i++)
			{
				if(s[i]!='0')
				{
					hold=i;
					break;
				}
			}
			printf("%c",s[hold]);
			if(hold+1<a)//bushizuihouyiwei
			{
				printf(".");
				for(int j=hold+1;j<a;j++)
				{
					printf("%c",s[j]);
				}
			
			}	printf("e-%d",hold-1);

		}
		else
		{int count=0;
			printf("%c",s[0]);
			for(int j=a-1;j>=1;j--)
			{
				if(s[j]!='0')
				{
				break;
				}
			count++;//e前数末尾几个0 
			}
			if(count!=a-2)
			{
				printf(".");
				for(int j=1;j<a-count;j++)//
				{
					if(s[j]!='.')
					{
						printf("%c",s[j]);
					}
				}
			}
		printf("e%d",temp-1); 
		}
	}
	else//-
	{
		printf("-");
			if(temp==2&&s[1]=='0')//chun小数 
		{
			for(int i=temp+1;i<a;i++)
			{
				if(s[i]!='0')
				{
					hold=i;
					break;
				}
			}
			printf("%c",s[hold]);
			if(hold+1<a)//bushizuihouyiwei
			{
				printf(".");
				for(int j=hold+1;j<a;j++)
				{
					printf("%c",s[j]);
				}
			
			}	printf("e-%d",hold-2);

		}
		else
		{int count=0;
			printf("%c",s[1]);
			for(int j=a-1;j>=2;j--)
			{
				if(s[j]!='0')
				{
				break;
				}
			count++;//e前数末尾几个0 
			}
			if(count!=a-3)
			{
				printf(".");
				for(int j=2;j<a-count;j++)//
				{
					if(s[j]!='.')
					{
						printf("%c",s[j]);
					}
				}
			}
		printf("e%d",temp-2); 
		}
	}
 	return 0;
}



