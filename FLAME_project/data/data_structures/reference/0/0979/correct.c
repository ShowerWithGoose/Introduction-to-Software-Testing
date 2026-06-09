#include <stdio.h>
int main(){
	char a[100], c;
	gets(a);
	int i;
	for(i=0; i<strlen(a); i++){
		if(a[i]=='-'){
			if (a[i-1]<='Z'&&a[i-1]>='A'){
				if((a[i+1]<='Z'&&a[i+1]>='A')&&a[i+1]>a[i-1]){
					for(c=a[i-1]+1; c<a[i+1]; c++){
						printf("%c",c);
					}
				}
				else {
				printf("-");
			}
			}
			else if (a[i-1]<='z'&&a[i-1]>='a'){
				if((a[i+1]<='z'&&a[i+1]>='a')&&a[i+1]>a[i-1]){
					for(c=a[i-1]+1; c<a[i+1]; c++){
						printf("%c",c);
					}
				}
				else {
				printf("-");
			}
			}
			else if (a[i-1]<='9'&&a[i-1]>='0'){
				if((a[i+1]<='9'&&a[i+1]>='0')&&a[i+1]>a[i-1]){
					for(c=a[i-1]+1; c<a[i+1]; c++){
						printf("%c",c);
					}
				}
				else {
				printf("-");
			}
			}
			i+=1;
		}
		printf("%c",a[i]);
	}
	return 0;
}

