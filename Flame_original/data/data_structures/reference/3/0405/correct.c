#include <stdio.h>
#include <string.h>


int main()
{
	char s[120];
	gets(s);
	int a[120];
	int dian,feiling,i,j;
	int flag=0,k=1;
	if(s[0]=='-')
	{
		printf("-");
	}
	
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		{
			dian=i;
		}
		if(s[i]!='0'&&s[i]!='.'&&s[i]!='-'&&flag==0)
		{
			feiling=i;
			flag=1;
			a[0]=s[i]-'0';
			continue;
		}
		if(flag==1&&s[i]!='.'&&s[i]!='-')
		{
			a[k]=s[i]-'0';
			k++;
		}
		
	}
	for(j=0;j<k;j++)
	{
		if(j==1)
		{
			printf(".%d",a[j]);
		}else{
			printf("%d",a[j]);
		}
	}
	int zhishu;
	if(dian<feiling)
	{
		zhishu=dian-feiling;
		printf("e%d",zhishu);
	}else{
		zhishu=dian-feiling-1;
		printf("e%d",zhishu);
	}
	return 0;
}

