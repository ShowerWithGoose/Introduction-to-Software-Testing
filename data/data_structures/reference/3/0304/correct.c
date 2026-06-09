#include <stdio.h>
#include <string.h>
int main(){
	char a[105];
	gets(a);
	int i,k,cnt;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='.'){
			for(k=i;k<strlen(a)-1;k++){
				a[k]=a[k+1];
			}
			break;
		}
	}
	if(i!=1){
		cnt=i-1;
		for(i=0;i<strlen(a)-1;i++){
			if(i==0){
				printf("%c.",a[i]);
			}
			else{
				printf("%c",a[i]);
			}
		}
		printf("e%d",cnt);
		return 0;
	}
	else{
		for(i=0;i<strlen(a)-1;i++){
			if(a[i]!='0'){
				cnt=i;
				break;
			}
		}
		for(k=i;k<strlen(a)-1;k++){
			if(k==i&&k<strlen(a)-2){
				printf("%c.",a[k]);
			}
			else{
				printf("%c",a[k]);
			}
		}
		if(cnt==0){
			printf("e0");
		}
		else{
			printf("e-%d",cnt);
		}
		return 0;
	}
}

