#include<stdio.h>
#include<string.h>
int main()
{
	char all[200];
	int a[100], ch=0, i=0;
	int step=0, le;
	int link=0;
	gets(all);
	le=strlen(all);
	for(i=0; i<=le; i++)
	{
		if(all[i]=='-')
		step=-1;
		else if(all[i]!=' ')
		{
			ch=ch*10+all[i]-'0';
		}
		else
		{
			if(step==-1)
			{
				step=0;
				ch=ch-2*ch;
			}
			if(ch==-1)
			break;
			else if(ch==0&&link==0)
			printf("error ");
			else if(ch==0)
			printf("%d ",a[--link]);
			else if(ch==1)
			{
				ch=0;
				continue;
			}
			else
			a[link++]=ch;
			ch=0;
		}
	}
} 

