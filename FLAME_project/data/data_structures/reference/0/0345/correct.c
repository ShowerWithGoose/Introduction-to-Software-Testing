#include <stdio.h>
#include <string.h>
int main(){
	int i,j;
	char a[1000];
	scanf("%s",a);
	printf("%c",a[0]);
	for(i=1;i<strlen(a);i++){
		if(a[i]=='-'){
			if((a[i-1]<='z'&&a[i-1]>='a')&&(a[i+1]<='z'&&a[i+1]>='a')){
				for(j=a[i-1]+1;j<a[i+1];j++){
					printf("%c",j);
				}
			}else if((a[i-1]<='Z'&&a[i-1]>='A')&&(a[i+1]<='Z'&&a[i+1]>='A') ){
				for(j=a[i-1]+1;j<a[i+1];j++){
					printf("%c",j);
				}
			}else if((a[i-1]<='9'&&a[i-1]>='0')&&(a[i+1]<='9'&&a[i+1]>='0') ){
				for(j=a[i-1]+1;j<a[i+1];j++){
					printf("%c",j);
				}
			}else{
				printf("-");
			}
		}else{
			printf("%c",a[i]);
		}
	}
	return 0;
}

