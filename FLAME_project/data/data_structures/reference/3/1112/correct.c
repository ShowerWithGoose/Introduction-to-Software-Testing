#include<stdio.h>
char s[200],a[200];
int main()
{
	int i,flag1=0,num=-1,numdian=0,flag3=0;
	gets(s+1);
	for(i=1;s[i]!='.';i++)
	{
		if(s[i]>='1'&&s[i]<='9') flag1=1;
		num++;
	}
	numdian=i;
	if(flag1==1)
	{
		printf("%c.",s[1]);
		for(i=2;s[i]!='\0';i++)
		{
			while(s[i]=='.')
			i++;
			printf("%c",s[i]);
		}
		printf("e%d",num);
		return 0;
	}
	else
	{
		for(i=numdian+1;s[i]!='\0';i++)
		{	
		    if(flag3==1)
			{
				printf("%c",s[i]);
			}
		    if(flag3==0&&s[i]>='1'&&s[i]<='9')
			{
				flag3=1;
				if(s[i+1]!='\0')printf("%c.",s[i]);
				else printf("%c",s[i]);
				num++;
			}
			if(flag3==0)
			{
				num++;
				continue;
			}
		}
		printf("e-%d",num);
		return 0;
	}
}

