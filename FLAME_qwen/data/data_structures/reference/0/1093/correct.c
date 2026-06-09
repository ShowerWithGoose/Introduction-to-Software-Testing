#include<stdio.h>
#include<string.h>
char a[10000];
int check(char a,char b)
{
	if(a<b)
	{
		if('0'<=a&&b<='9')return 1;
		if('A'<=a&&b<='Z')return 1;
		if('a'<=a&&b<='z')return 1;
	}
	return 0;
}
int main()
{
	int i,j,k,len;
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(i>=2&&a[i-1]=='-'&&check(a[i-2],a[i]));
		else printf("%c",a[i]);//避掉a-g-m中g的重复 
		if(i+2<len&&a[i+1]=='-'&&check(a[i],a[i+2]))//先越界判断 
		{
			for(j=a[i]+1;j<=a[i+2];j++)
			{
				printf("%c",j);
			}
			i++;//不加2 
		}
	}
	return 0;
}

