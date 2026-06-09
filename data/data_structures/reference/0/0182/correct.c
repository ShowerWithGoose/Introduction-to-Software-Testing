#include <stdio.h>
#include <string.h>
	char arr[3000];

int main(){
	scanf("%s",arr);
	int i=0;
	for(i=0;i<strlen(arr);i++){
		if(arr[i]=='-'){
			if((arr[i-1]>='0'&&arr[i-1]<='9'&&arr[i+1]>='0'&&arr[i+1]<='9')||(arr[i-1]>='a'&&arr[i-1]<='z'&&arr[i+1]>='a'&&arr[i+1]<='z')||(arr[i-1]>='A'&&arr[i-1]<='Z'&&arr[i+1]>='A'&&arr[i+1]<='Z')){
				if(arr[i-1]<arr[i+1]){
					char j;
					for(j=arr[i-1]+1;j<arr[i+1];j++){
						printf("%c",j);
					}
				}else{
					printf("%c",arr[i]);
				}
			}else{
				printf("%c",arr[i]);
			}
		}else{
			printf("%c",arr[i]);
		}
	}
	
	
	return 0;
} 



