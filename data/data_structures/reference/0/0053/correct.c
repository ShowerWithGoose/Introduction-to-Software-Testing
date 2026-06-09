#include<stdio.h>

int main(){
	char a[1024];
	int i=0;
	scanf("%s",a);
	if(a[i]=='-'){
		printf("-");
		i++;
	}
	for(;a[i]!=0;i++){
		if(a[i]!='-'){
			printf("%c",a[i]);
		}else if(a[i]=='-'){
			if(a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a'&&a[i+1]>a[i-1]){
				for(a[i-1]++;a[i-1]<=a[i+1];a[i-1]++){
					printf("%c",a[i-1]);
				}
				i++;
			}else if(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A'&&a[i+1]>a[i-1]){
				for(a[i-1]++;a[i-1]<=a[i+1];a[i-1]++){
					printf("%c",a[i-1]);
				}
				i++;
			}else if(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'&&a[i+1]>a[i-1]){
				for(a[i-1]++;a[i-1]<=a[i+1];a[i-1]++){
					printf("%c",a[i-1]);
				}
				i++;
			}else printf("-");
			
		}
	}
	return 0;
}

