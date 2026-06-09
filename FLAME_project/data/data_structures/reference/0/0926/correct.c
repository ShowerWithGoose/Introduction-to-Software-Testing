#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//变量循环的初始化很关键，scanf的&

int main(){
	char a[150];
	char c;
	int i=0;
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(a[i]=='-'){
			if((((a[i-1]>='a')&&(a[i+1]<='z'))&&((a[i+1]>='a')&& (a[i-1] <='z')))&&(a[i+1]>a[i-1])){
				for(c=a[i-1]+1;c<a[i+1];c++){
					printf("%c",c);
				}
			}
			else if( a[i-1] >= 'A' && a[i+1] <= 'Z' && a[i+1] >= 'A' && a[i-1] <= 'Z' && a[i+1] > a[i-1]){
				for(c=a[i-1]+1;c<a[i+1];c++){
					printf("%c",c);
				}
			}
			else if( a[i-1] >= '0' && a[i+1] <= '9' && a[i+1] >= '0' && a[i-1] <= '9' && a[i+1] > a[i-1]){
				for(c=a[i-1]+1;c<a[i+1];c++){
					printf("%c",c);
				}
				}
				else{
					printf("%c",a[i]);
				}
		}
		else{
			printf("%c",a[i]);
		}
	}
  return 0;
}

