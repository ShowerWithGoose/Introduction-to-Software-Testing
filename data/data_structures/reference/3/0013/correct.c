#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char a[10000];
	int len,i,flag=0,m=0,n=0,t=0,b=0;
	gets (a);
	len = strlen(a);
	if(a[0]=='0'){
		for(i=2;i<len;i++){
			if(a[i]!='0'&&flag==0){
				printf("%c",a[i]);
				t=1;
				n=i-1; 
			}
			if(a[i]!='0'&&flag==1){
				printf(".%c",a[i]);
			} 
			if(flag>=2){
				printf("%c",a[i]);
			}
			if(t==1){
				flag++;
			}
			if(flag>=1){
				m++;
			}
			
		}
		printf("e-%d",n);
	}
	else if(a[0]=='-'&&a[1]=='0'){
		for(i=3;i<len;i++){
			if(a[i]!='0'&&flag==0){
				printf("-%c",a[i]);
				t=1;
				n=i-2;
			}
			if(a[i]!='0'&&flag==1){
				printf(".%c",a[i]);
			} 
			if(flag>=2){
				printf("%c",a[i]);
			}
			if(t==1){
				flag++;
			}
			if(flag>=1){
				m++;
			}
		}
		printf("e-%d",n);
	}
	else if(a[0]=='-'&&a[1]!='0'){
		if(flag==0){
			printf("-%c",a[1]);
			flag=1;
		}
		for(i=0;i<len;i++){
			if(a[i]=='.'){
				b=1;
			}
		}
		if(b==1){
			printf(".");
		}
		for(i=2;i<len;i++){
			if(a[i]!='.'&&flag==1&&b==1){
				printf("%c",a[i]);
				m++;
			}
			if(a[i]!='.'&&flag==1&&b==0){
				n=len-2;
			}
			if(a[i]=='.'){
				n=m;
			}
		}
		printf("e%d",n);
	}
	else{
		if(flag==0){
			printf("%c",a[0]);
			flag=1;
		}
		for(i=0;i<len;i++){
			if(a[i]=='.'){
				b=1;
			} 
		}
		if(b==1){
			printf(".");
		}
		for(i=1;i<len;i++){
			if(a[i]!='.'&&flag==1&&b==1){
				printf("%c",a[i]);
				m++;
			}
			if(a[i]!='.'&&flag==1&&b==0){
				n=len-1;
			}
			if(a[i]=='.'){
				n=m;
			}
		}
		printf("e%d",n);
	}



	return 0;
}


