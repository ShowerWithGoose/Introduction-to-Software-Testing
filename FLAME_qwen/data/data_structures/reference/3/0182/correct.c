#include <stdio.h>
#include <string.h>

char arr[300];

int main(){
	gets(arr);
	int i=0,x=0,j=0,y;
	for(i=0;i<strlen(arr);i++){
		if(arr[i]=='.'){
			x=i;
			break;
		}
	}
	if(x==1){
		if(arr[0]!='0'){
			for(j=0;j<strlen(arr);j++){
				printf("%c",arr[j]);
			}
			printf("e0");
		}else{
			for(j=0;j<strlen(arr);j++){
				if(arr[j]!='0'&&arr[j]!='.'){
					y=j-1;
					break;
				}
			}
			if(y==strlen(arr)-2){
				printf("%ce-%d",arr[y+1],y);
			}else{
				printf("%c.",arr[y+1]);
				for(j=y+2;j<strlen(arr);j++){
					printf("%c",arr[j]);
				}
				printf("e-%d",y);
			}
		}
	}else{
		printf("%c.",arr[0]);
		for(j=1;j<strlen(arr);j++){
			if(arr[j]!='.')
			printf("%c",arr[j]);
		}
		printf("e%d",x-1);
	}
	return 0;
}



