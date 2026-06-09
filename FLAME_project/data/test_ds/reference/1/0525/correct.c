#include<stdio.h>
#include<string.h>
char a[100],b[100],c[100];
int main() {
	int i=0;
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='-'){
			if((a[i-1]>='A'&&a[i-1]<='Z')&&(a[i+1]>='A'&&a[i+1]<='Z')&&a[i+1]>a[i-1]){
				for(int j=1;j<(a[i+1]-a[i-1]);j++){
					printf("%c",a[i-1]+j);
				}
				continue;
			}
			else if((a[i-1]>='a'&&a[i-1]<='z')&&(a[i+1]>='a'&&a[i+1]<='z')&&a[i+1]>a[i-1]){
				for(int j=1;j<(a[i+1]-a[i-1]);j++){
					printf("%c",a[i-1]+j);
				}
				continue;
			}
			else if((a[i-1]>='0'&&a[i-1]<='9')&&(a[i+1]>='0'&&a[i+1]<='9')&&a[i+1]>a[i-1]){
				for(int j=1;j<(a[i+1]-a[i-1]);j++){
					printf("%c",a[i-1]+j);
				}
				continue;
			}
		}
		printf("%c",a[i]);
	}
	return 0;
}


