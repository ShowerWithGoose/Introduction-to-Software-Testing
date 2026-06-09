#include <stdio.h> 
#include <string.h> 
int f(char n){
	if('a'<=n&&n<='z') return 1;
	if('0'<=n&&n<='9') return 2;
	if('A'<=n&&n<='Z') return 3;
}
int main(){
	int i,k,j;
	char a[70];
	scanf("%s",a);
	for(i=0;i<strlen(a);i++){
		if(a[i]!='-'){
			printf("%c",a[i]);
		}
		if(a[i]=='-'){
			if(f(a[i-1])!=f(a[i+1])) printf("-");
			for(j=i-1,k=1;a[i-1]+k!=a[i+1]&&a[i-1]+k!='Z'+1&&a[i-1]+k!='z'+1&&a[i-1]+k!='9'+1&&f(a[i-1])==f(a[i+1]);k++){
				printf("%c",a[j]+k);
			}
		}
	}
	return 0;
}



