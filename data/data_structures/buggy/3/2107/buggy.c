#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char a[200];char c;int i,j;
int main(){
	gets(a);
	if(a[0]=='0'){
		for(i=2;a[i]=='0';i++){
			
		}
		if(a[i+1]=='\0'){
			printf("%c",a[i]);printf("e");
			printf("%d",1-i);
		}
		else{
			printf("%c.",a[i]);
			for(j=i+1;a[j]!='\0';j++){
				printf("%c",a[j]);
			}
			printf("e%d",1-i);
		}
	}
	return 0;
}

