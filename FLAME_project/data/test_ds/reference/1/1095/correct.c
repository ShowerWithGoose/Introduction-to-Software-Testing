#include <stdio.h>
int main(){
	char arr[10000];
	gets(arr);
	int i=0;
	int j=1; 
	for(i=0;arr[i]!='\0';i++){
		if(arr[i]!='-'){
			printf("%c",arr[i]);
		}else{
			if((arr[i-1]>='a'&&arr[i+1]<='z')||(arr[i-1]>='A'&&arr[i+1]<='Z')||(arr[i-1]>='0'&&arr[i+1]<='9')){
		        if(arr[i-1]<arr[i+1]){
		            int x=arr[i+1]-arr[i-1];
			for(j=1;j<x;j++){
					printf("%c",arr[i-1]+j);
			        } 	
		    	}
				else printf("%c",arr[i]);
	        } else{
				printf("%c",arr[i]);
			}
	}
}
	return 0;
}



