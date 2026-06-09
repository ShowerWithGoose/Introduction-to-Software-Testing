#include<stdio.h>
#include<string.h>
int main(){
	char a[1000];
	gets(a);
	int i,j,k,l;
	if(a[0]=='0') for(i=2;i<strlen(a);i++) if(a[i]>'0'){
		printf("%c",a[i]);
		if(i<strlen(a)-1){
			printf(".");
			for(j=i+1;j<strlen(a);j++) printf("%c",a[j]);
		}				
		printf("e-%d",i-1);
		break;
	}
	if(a[0]>'0'){
		printf("%c.",a[0]);
		for(i=1;i<strlen(a);i++){
			if(a[i]=='.'){
				j=i-1;
				k=i+1;
				for(l=1;l<=j;l++) printf("%c",a[l]);
				for(l=k;l<strlen(a);l++) printf("%c",a[l]);
				printf("e%d",j);
				break;
			}
			
		}
	}
}

