#include<stdio.h>
#include<string.h>
int main(){
	char a[1000];
	gets(a);
	int len,i,j,k;
	len=strlen(a);
	for(i=0;a[i]!='.';i++);
	if(i==1&&a[0]!='0'){
		printf("%se0",a);
		return 0;
	}
	else if(i==1&&a[0]=='0'){
		for(j=2;a[j]=='0';j++);
		printf("%c",a[j]);
		if(j==len-1){
			printf("e-%d",len-2);
		}
		else {
			printf(".");
			for(k=j+1;k<=len-1;k++){
				printf("%c",a[k]);
			}
			printf("e-%d",j-1);
		}
	}
	else {
		printf("%c.",a[0]);
		for(j=1;j<=len-1;j++){
			if(i==j) continue;
			else printf("%c",a[j]);
			
		}
		printf("e%d",i-1);
	}return 0;
}

