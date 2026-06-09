#include<stdio.h>
#include<string.h>

int search(char ch[],int n)
{
	int ans=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(ch[i]=='.')
		{
			ans=i;break;
		}
	}
	return ans;
}

int main()
{
	char ch[105];gets(ch);
	int len=strlen(ch);
	int i;
	if(ch[1]=='.')
	{
		if(ch[0]=='0')
		{
			int num=2;
			while(ch[num]=='0')num++;
			printf("%c",ch[num]);
			if(num<len-1)printf(".");
			for(i=num+1;i<len;i++)printf("%c",ch[i]);
			printf("e-%d\n",num-1);
		}
		else
		{
			printf("%s",ch);
			printf("e0");
		}
	}
	else
	{
		int s=search(ch,len);
		for(i=s-1;i>=1;i--)
		ch[i+1]=ch[i];
		ch[1]='.';
		printf("%s",ch);
		printf("e%d\n",s-1);
	}
	return 0;
}

