#include<string.h>
#include<stdio.h>
int main()
{
	char a[20],rest[20];
	int judge=0,judge1=0,first=0,mark=0,point,power,powerful;
	scanf("%s",a);
	int i1,i2,i3,i4;
	int len=strlen(a);
	for( i1=len-1;i1>=0;i1--)
	{
		if(a[i1]=='0')len--;
		else break;
	}
	for(i2=1;i2<=len;i2++)
	{
		if(a[i2-1]=='0')judge+=1;
		if(mark==0&&a[i2-1]!='0'&&a[i2-1]!='.')
		{
			mark=1;
			first=a[i2-1]-48;
			power=i2-1;
		}
		if(a[i2-1]=='.')
		{
			point=i2-1;
		}
		
	}
	for(i3=power+1;i3<=len-1;i3++)
	{
		if(a[i3]!='0'&&a[i3]!='.')judge1++;
	}

	if(power<=point)powerful=point-power-1;
	else  powerful=point-power;
	int len1=strlen(rest);
	if(first==0)printf("0");
	else if(first!=0&&len1!=0)
	{	printf("%d",first);
		if(judge1!=0){printf(".");
		for(i4=power+1;i4<=len-1;i4++)
		{
			if(a[i4]=='.')continue;
			else printf("%c",a[i4]);
		}}
	}
	if(first!=0)printf("e%d",powerful);
	return 0;
}

