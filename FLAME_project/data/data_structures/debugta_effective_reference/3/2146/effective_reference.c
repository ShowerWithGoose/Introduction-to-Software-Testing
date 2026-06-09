#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
char s[100];
int main()
{
	gets(s);
	int i,len= strlen(s),first,last;
	for(i=len-1;i>=0;i--){
		if(isdigit(s[i])){
			break;
		}
	}
	len=i+1;
	for(i=len-1;i>=0;i--){
		if(isdigit(s[i])&&s[i]!='0'){
			last=i;
			break;
		}
	}
	int d=i,dygsz=-1;
	for(i=0;i<len;i++){
		if(s[i]=='.'){
			d=i-1;
		}
		if(isdigit(s[i])&&s[i]!='0'&&dygsz==-1){
			first=i;
			dygsz=i;
			if(d<dygsz) dygsz--;
		}
	}
	for(i=first;i<=last;i++){
		if(isdigit(s[i])){
			putchar(s[i]);
		}
		if(i==first&&i!=last){
			putchar('.');
		}
	}
	printf("e");
	printf("%d\n",d-dygsz);
	return 0 ;
 } 

