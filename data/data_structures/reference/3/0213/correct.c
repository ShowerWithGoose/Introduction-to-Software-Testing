#include<stdio.h>
#include<string.h>
int main(){
	char a[1000];
	int i=0,k=0,j=0;
	gets(a);
	for(;a[i]!='.';i++){
		k++;
	}
	if(k==1){
		if(a[0]=='0'){         //0.xxxxx
			for(i=2;a[i]=='0';i++){
			j++;
			}
			printf("%c",a[i]);
			if(a[++i]!='\0'){
				printf(".");
			}
			for(;a[i]!='\0';i++){
				printf("%c",a[i]);
			}
			printf("e-%d",j+1);
		}else{
			printf("%se0",a);     //x.xxxxx
		}
	}else{
		printf("%c.",a[0]);
		for(i=1;a[i]!='\0';i++){      //xxx.xxx
			if(a[i]!='.'){
				printf("%c",a[i]);
			}
		}
		printf("e%d",k-1);
	}
	return 0; 
}

