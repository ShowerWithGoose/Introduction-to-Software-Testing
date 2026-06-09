#include<stdio.h>
#include<string.h>
int main()
{
	char str[105],ans[105];
	int i,j,k=0,len=0;
	gets(str);
	if(str[0]=='0')
	{for(i=2;i<strlen(str);i++)
	{if(str[i]!='0')
	break;
	else
	len++;
	}
	for(;i<strlen(str);i++)
	{ans[k]=str[i];
	k++;
	}
	if(k>1)
	{printf("%c.",ans[0]);
	for(j=1;j<k;j++)
	printf("%c",ans[j]);
	printf("e-%d",len+1);
	}
	if(k==1)
	{printf("%c",ans[0]);
	printf("e-%d",len+1);
	}
	}
	
	if(str[0]!='0')
	{if(str[1]=='.')
	printf("%se0",str);
	if(str[1]!='.')
	{for(i=1;i<strlen(str);i++)
	{if(str[i]=='.')
	continue;
	else
	ans[k++]=str[i];
	}
	for(i=0;i<strlen(str);i++)
	{if(str[i]!='.')
	len++;
	else
	break;
	}
	printf("%c.",str[0]);
	for(j=0;j<k;j++)
	printf("%c",ans[j]);
	printf("e%d",len-1);
	}
	
	}
	return 0;
}


