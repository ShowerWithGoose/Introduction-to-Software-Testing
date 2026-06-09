#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int panduan (char c,int judge)
{
	int j=0;
	if(c>='a'&&c<='z') j=1;
	else if(c>='A'&&c<='Z') j=2;
	else if(c>='0'&&c<='9') j=3;
	return (judge==j);
}
int main()
{
	char s[1010];
	int i,j=0,k;
	int n,m,x;
	gets(s);
	char a[1100];
	char mark;
	int key=0;
	char front;
	int judge=0;
	for(i=0;s[i]!='\0';i++){
		if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
			if(key==1&&panduan(s[i],judge)){
				for(front=mark+1;front<s[i];front++){
					a[j++]=front;
				}
				key=0;
				judge=0;
			}
			else if(key==1&&!panduan(s[i],judge)){
				a[j++]='-';
				key=0;
				judge=0;
			}
			mark=s[i];
			a[j++]=s[i];
		}
		else if(s[i]=='-'){
			key=1;
			front=mark;
			if(mark>='a'&&mark<='z') judge=1;
			else if(mark>='A'&&mark<='Z') judge=2;
			else if(mark>='0'&&mark<='9') judge=3;
		}
	}
	a[j]='\0';
	puts(a);
	return 0;
 } 

