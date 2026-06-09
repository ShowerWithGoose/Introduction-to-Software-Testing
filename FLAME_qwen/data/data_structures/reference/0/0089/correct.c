#include <stdio.h>
#include <string.h>
int judge(char a,char b)
{
	if(a<='z'&&a>='a'&&b>='a'&&b<='z') return 0;
	else if(a>='0'&&a<='9'&&b>='0'&&b<='9') return 0;
	else if(a<='Z'&&a>='A'&&b>='A'&&b<='Z') return 0;
	else return 1;
 } 
int main()
{
	char a[20];
	char ch;
	gets(a);
	int i,j;
	j=strlen(a);
	for(i=0;i<j;i++){
		if(a[i]!='-')
		printf("%c",a[i]);
		else if(a[i-1]<a[i+1]&&judge(a[i-1],a[i+1])==0){
			ch=a[i-1]+1;
			while(ch<a[i+1]){
			printf("%c",ch);
			ch++;	
			}
		}
		else printf("-");
	}
	return 0; 
 } 

