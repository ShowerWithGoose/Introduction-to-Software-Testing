#include<stdio.h>
#include<string.h>
char a[1000];
int main(){
	int b,k=0,c;
	gets(a);
	b=strlen(a);
	for(int i=0;i<b;i++){
		if(a[i]=='-'){
			if(a[i-1]<a[i+1]){
				if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'){
					k=1;
				}
				if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'){
					k=1;
				}
				if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'){
					k=1;
				}
			}if(k==1){
				c=a[i+1]-a[i-1];
				for(int j=1;j<c;j++){
					printf("%c",a[i-1]+j);
				}k=0;
			}else{
				printf("-");
			}
		}else{
			printf("%c",a[i]);
		}
	}return 0;
} 

