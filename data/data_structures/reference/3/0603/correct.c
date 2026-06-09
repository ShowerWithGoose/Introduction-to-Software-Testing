#include<stdio.h>
#include<string.h>
char a[10001];
int main()
{
	gets(a);int len=strlen(a),flag;
	for(int i=0;i<len;i++)
	{
		if(a[i]=='.'){flag=i;break;}
	}
	if(flag==1){
		if(a[0]>48){printf("%se0",a);return 0;}
		else{
			flag=1;
			for(int i=2; ;i++)
			{
			if(a[i]==48)flag++;
			else break;	
			}
			printf("%c",a[flag+1]);
			if(flag+2<len){
			printf(".");
			for(int i=flag+2;i<len;i++)
			printf("%c",a[i]);}
			printf("e-%d",flag);
			return 0;
		}
		}
	printf("%c.",a[0]);
	for(int i=1;i<len;i++)
	{if(i!=flag)printf("%c",a[i]);
	 else continue;}
	 printf("e%d",flag-1);
	return 0;
}

