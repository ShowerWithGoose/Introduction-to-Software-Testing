#include<stdio.h>
#include<string.h>
char a[1000];
int main(){
	gets(a);
	int i=0,j=0,k=0;
	int cnt=0;
	if(a[0]!='0'){
			for(i=0;i<strlen(a);i++){
				if(a[i]!='.'){
					cnt++;
				}
				else break;//此时第i个字符是.
		}	
		printf("%c.",a[0]);
		for(j=1;j<strlen(a);j++){
			if(a[j]!='.'){
				printf("%c",a[j]);
			}
		}
		printf("e%d",cnt-1);
	}
	else if(a[0]=='0'){
		for(k=2;k<strlen(a);k++){
			if(a[k]=='0'){
				cnt++;
			}
			else break;//此时第i个字符是第一个非0数
		}
	//	printf("%d\n",k);
	if(k==strlen(a)-1){
		printf("%c",a[k]);
	}
	else printf("%c.",a[k]);
		for(j=k+1;j<strlen(a);j++){
				printf("%c",a[j]);
			}
			printf("e-%d",cnt+1);
		}
	
	return 0;
}

