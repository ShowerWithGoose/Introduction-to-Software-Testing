#include<stdio.h>
#include<string.h>
char a[150];
int main(){
	int n=0,m=0,len;
	gets(a);
	len=strlen(a);
	n=len;
	if(len==1){
		printf("%ce0",a[0]);
	}else{
		for(int i=0;i<len;i++){
			if(a[i]=='.'){
				n=i;
				break;
			}
		}for(int j=0;j<len;j++){
			if(a[j]<='9'&&a[j]>'0'){
				m=j;
				break;
			}
		}
		if(m==len-1){
			printf("%ce%d",a[m],n-m);
		}else{
			printf("%c.",a[m]);
			for(int k=m+1;k<len;k++){
				if(a[k]=='.'){
					continue;
				}
				printf("%c",a[k]);
			}
			if(n<m){
				printf("e%d",n-m);
			}else{
				printf("e%d",n-m-1);
			}
		}
	}return 0;
} 

