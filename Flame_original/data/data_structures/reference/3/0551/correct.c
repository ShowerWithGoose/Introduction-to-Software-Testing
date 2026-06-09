#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
char a[100];
int main()
{
	gets(a);
	int i,len= strlen(a),first,last;
	for(i=len-1;i>=0;i--){
		if(isdigit(a[i])){
			break;
		}
	}
	len=i+1;
	for(i=len-1;i>=0;i--){
		if(isdigit(a[i])&&a[i]!='0'){
			last=i;
			break;
		}
	}
	int d=i,s=-1;
	for(i=0;i<len;i++){
		if(a[i]=='.'){
			d=i-1;
		}
		if(isdigit(a[i])&&a[i]!='0'&&s==-1){
			first=i;
			s=i;
			if(d<s) s--;
		}
	}
	for(i=first;i<=last;i++){
		if(isdigit(a[i])){
			putchar(a[i]);
		}
		if(i==first&&i!=last){
			putchar('.');
		}
	}
	printf("e");
	printf("%d\n",d-s);
	return 0 ;
 } 

