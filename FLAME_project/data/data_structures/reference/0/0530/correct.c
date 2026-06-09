#include <stdio.h>
#include <string.h>
char save[1000]={'\0'},loc[1000]={'\0'};
int cnt=0,use=0;
int judge(char save[]);
int main()
{
	int x,j,lent;
	char k;
	scanf("%s",&save);
	lent=strlen(save);
	x=judge(save);
	if(x==1)
	{
		for(j=0,cnt=0 ;j<lent ;j++)
		{
			if(j==loc[cnt])
			{
				for(k=save[j-1]+1;k<save[j+1];k++)
					printf("%c",k);
				cnt++;
			}	
			else
				printf("%c",save[j]);
		}	
	}
	else
		puts(save);
	return 0;
}

int judge(char save[])
{
	int i=0,len=strlen(save),flag=0;
	for(i=0 ;i<len ;i++)
	{
		if(save[i]=='-')
		{
			if(i==0||i==len-1)
				continue;
			else
			{
				if(save[i-1]>='a'&&save[i+1]<='z'&&save[i+1]>save[i-1])
				{
					loc[cnt]=i;
					cnt++;flag=1;
				}
				if(save[i-1]>='A'&&save[i+1]<='Z'&&save[i+1]>save[i-1])
				{
					loc[cnt]=i;
					cnt++;flag=1;
				}
				if(save[i-1]>='0'&&save[i+1]<='9'&&save[i+1]>save[i-1])
				{
					loc[cnt]=i;
					cnt++;flag=1;
				}
			}
		}
	}
	use=cnt;
	if(flag==1)
		return 1;
	return -1;
}



