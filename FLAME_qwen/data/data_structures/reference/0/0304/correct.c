#include <stdio.h>
#include <string.h>
int main(){
	char a[1000];
	scanf("%s",a);
	int i,j;
	for(i=0;a[i]!='\0';i++){
		if(a[i+1]!='-'){
			printf("%c",a[i]);
		}
		else{
			if(a[i+2]>a[i]){
				if(a[i]-'0'>=0&&'9'-a[i]>=0&&'9'-a[i+2]>=0){
					for(j=0;j<a[i+2]-a[i];j++){
						printf("%c",a[i]+j);
					}
					i=i+1;
				}
				else if(a[i]-'A'>=0&&'Z'-a[i]>=0&&'Z'-a[i+2]>=0){
					for(j=0;j<a[i+2]-a[i];j++){
						printf("%c",a[i]+j);
					}
					i=i+1;
				}
				else if(a[i]-'a'>=0&&'z'-a[i]>=0&&'z'-a[i+2]>=0){
					for(j=0;j<a[i+2]-a[i];j++){
						printf("%c",a[i]+j);
					}
					i=i+1;
				}
				else{
					printf("%c",a[i]);
				}
			}
			else{
				printf("%c",a[i]);
			}
		}
	}
	return 0;
} 



