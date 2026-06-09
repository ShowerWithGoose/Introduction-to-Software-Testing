#include<stdio.h>
#include<string.h>
int main(){
	char a[105]={0};
	int i=0,j=0,c;
	scanf("%s",a);
	c=strlen(a);
	if(a[0]!='0'){
		printf("%c.",a[0]);
		for(i=1;i<c;i++){
			if(a[i]=='.'){
				break;
			}
			if(a[i]!='.'){
				j++;
				printf("%c",a[i]);
			}
		}
		for(i=i+1;i<c;i++){
			printf("%c",a[i]);
		}
		printf("e%d\n",j);
	}
	else{
		for(i=2;i<c;i++){
			if(a[i]!='0'){
				printf("%c",a[i]);
				j++;
				break;
			}
			else{
				j++;
			}
		}
		if(i+1<c){
			printf(".");
		}
		for(i=i+1;i<c;i++){
			printf("%c",a[i]);
		}
		printf("e-%d\n",j);
	}
	return 0;
}

