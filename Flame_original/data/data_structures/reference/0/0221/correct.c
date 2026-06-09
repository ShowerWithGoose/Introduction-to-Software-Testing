#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){

	
	char a[105];
	int i=0,j;
	gets(a);
	while(a[i]!='\0'){
		if(a[i]=='-'){
			if(islower(a[i-1])==islower(a[i+1])&&a[i+1]-a[i-1]>0&&islower(a[i-1])>0){
				for(j=1;j<a[i+1]-a[i-1];j++){
					printf("%c",a[i-1]+j);
				}
			}
			else if(isupper(a[i-1])==isupper(a[i+1])&&a[i+1]-a[i-1]>0&&isupper(a[i-1])>0){
				for(j=1;j<a[i+1]-a[i-1];j++){
					printf("%c",a[i-1]+j);
				}
			}
			else if('0'<=a[i-1]&&'9'>=a[i-1]&&'0'<=a[i+1]&&'9'>=a[i+1]&&a[i+1]-a[i-1]>0){
				for(j=1;j<a[i+1]-a[i-1];j++){
					printf("%c",a[i-1]+j);
			}}
			else printf("-");
			
		}
		else printf("%c",a[i]);
		i++;
	}

	return 0;
}

