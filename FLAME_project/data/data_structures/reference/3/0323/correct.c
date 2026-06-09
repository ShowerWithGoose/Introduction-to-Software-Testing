#include<stdio.h>
#include<string.h>
int main()
{
	char num[1000],string[1000];
	int flag1=0,n=0,cnt=0;/*flag1判断是否小数点前都是0*/
	char c;
	gets(num);
	if(num[0]=='0')
	{
		cnt=0;
		for(int i=0;i<strlen(num);i++)
		{
			if(num[i]=='0'&&flag1==0)
			{
				cnt++;
			}
			else if(num[i]!='0'&&num[i]!='.')
			{
				flag1++;
				string[n]=num[i];
				n++;
			}
			else if(flag1>0&&num[i]=='0')
						{
							flag1++;
							string[n]=num[i];
							n++;
						}
		}
		if(flag1>1)
		{
			for(int k=n+1;k>1;k--)
			{
				string[k]=string[k-1];
			}
			string[1]='.';
			string[n+1]='\0';
			printf("%s",string);
			printf("e");
			printf("-%d\n",cnt);
		}
		else
		{
			printf("%c",string[0]);
			printf("e");
			printf("-%d\n",cnt);
		}
	}
	
		
	
	else
	{
		cnt=-1;
		for(int i=0;i<strlen(num);i++)
		{
			if(num[i]=='.')
			{
				n=i;
				flag1=1;
				for(int k=n;k>1;k--)
				{
					string[k]=string[k-1];
				}
				string[1]='.';
			}
			else
			{
				string[i]=num[i];
				if (flag1==0)
					cnt++;
			}
			n=i;
		}
		string[n+1]='\0';
		printf("%s",string);
		printf("e");
		printf("%d\n",cnt);
		
	}
	return 0;}

