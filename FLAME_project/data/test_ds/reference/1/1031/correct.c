#include<stdio.h>
#include<string.h>
int main(){
	char a[100000];
	gets(a);
	int i,j,k;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='-'&&i<strlen(a)-1){
			if(((a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'))&&a[i+1]>a[i-1]){
				for(j=1;j<a[i+1]-a[i-1];j++){
					printf("%c",a[i-1]+j);
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

