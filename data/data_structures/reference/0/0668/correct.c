#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets(a);
	int i=0,j=strlen(a);
	for(i=0;i<j;i++)
		if((a[i]-'-'==0)&&((a[i-1]-'a'>=0&&a[i+1]-'z'<=0)||(a[i-1]-'A'>=0&&a[i+1]-'Z'<=0)||(a[i-1]-'0'>=0&&a[i+1]-'9'<=0))){
			int k=1;
			for(;k<a[i+1]-a[i-1];k++)
				printf("%c",a[i-1]+k);
			}
		else{
			printf("%c",a[i]);
		}
}

