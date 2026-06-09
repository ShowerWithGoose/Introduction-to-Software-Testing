#include<stdio.h>
#include<string.h>
int main()
{
	char s[110];
	int i,j,k=0,p=0,q=0,a[110],n=0;
	scanf("%s",s);
	if(s[0]=='-')
    {
		j=-1;
	}
	else
	{
		j=0;
	}
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		{
			k=i;
		}
		else if(k>0)
		{
			p++;
		}
		if(s[i]!='0'&&s[i]!='-'&&s[i]!='.')
		{
			n=1;
		}
		if(n==1&&s[i]!='.')
		{
			a[q]=s[i]-'0';
			q++;
		}
	}
	if(j<0)
	{
		printf("-");
	}
	for(i=0;i<q;i++)
	{
		if(i!=1)
		{
			printf("%d",a[i]);
		}
		else
		{
			printf(".%d",a[i]);
		}
	}
	printf("e");
	if(k==0&&p==0)
	{
		printf("%d\n",q-1);
	}
	else
	{
		printf("%d\n",q-p-1);
	}
	return 0;
}

