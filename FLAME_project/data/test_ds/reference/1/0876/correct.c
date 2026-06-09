#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int flag1,flag2,flag3;

int judge(char ch){
	if (ch>='0'&&ch<='9') return 1;
	else if(ch>='A'&&ch<='Z') return 2;
	else if(ch>='a'&&ch<='z') return 3;
	else if(ch='-') return 4;
	else return 0;
}
int main()
{
	char s[100];
	int i,j;
	gets(s);
	int len=strlen(s);
	for(i=0;s[i]!='\0';i++){
		flag1=judge(s[i]);
		flag2=judge(s[i+1]);
		flag3=judge(s[i+2]);
		if(flag1==flag3&&flag2==4){
			int span=s[i+2]-s[i]-2;//length=span+3
			for(j=len+span;j>i+span+2;j--){
				s[j]=s[j-span];
			}
			for(j=i+1;j<=i+span+2;j++){
				s[j]=s[j-1]+1;
			}
			len=strlen(s);
		}
	}
	printf("%s",s);
	return 0; 
}


