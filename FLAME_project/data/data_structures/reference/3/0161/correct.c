#include<stdio.h>
#include<string.h>

char str[1000];
int main()
{
	int i,j,len,flag=0;
	gets(str);
	len = strlen(str);
	for(i=0;str[i]!='.'&&i<len;i++);
	if(len==1) printf("%c",str[0]);
	else if(str[0]=='0')
	{
		for(i=2;str[i]=='0';i++);
		printf("%c",str[i]);
		for(j=len-2;j>2&&str[j]=='0';j--);
		if(j!=2&&len>3) printf(".");
		for(j=i+1;j<len;j++)
		printf("%c",str[j]);
		printf("e-%d",i-1);
	}
	else if(i==len)
	{
		for(j=len-1;str[j]=='0'&&j>0;j--);
		printf("%c",str[0]);
		if(j!=0){
			printf(".");
			for(i=1;i<=j;i++)
			printf("%c",str[i]);
		}
		printf("e%d",len-1);
	}
	else{
		printf("%c.",str[0]);
		for(j=1;j<len;j++)
		{
			if(j==i) continue;
			printf("%c",str[j]);
		}
		printf("e%d",i-1);
	}
	return 0;
}

