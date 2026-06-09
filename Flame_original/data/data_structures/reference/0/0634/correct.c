#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[5];
int main(){
	int k=0;
	scanf("%s",a);
	while(a[k]){
		if(a[k]!='-'){
			printf("%c",a[k]);
			k++;
			continue;
		}
		else{
			int j=k;
			if(isdigit(a[j-1])&&isdigit(a[j+1])&&a[j+1]>a[j-1]){
				for(int i=1;i<a[j+1]-a[j-1];i++)
					printf("%c",a[j-1]+i);
			}
			else if(isupper(a[j-1])&&isupper(a[j+1])&&a[j+1]>a[j-1]){
				for(int i=1;i<a[j+1]-a[j-1];i++)
					printf("%c",a[j-1]+i);
			}
			else if(islower(a[j-1])&&islower(a[j+1])&&a[j+1]>a[j-1]){
				for(int i=1;i<a[j+1]-a[j-1];i++)
					printf("%c",a[j-1]+i);
			}
			else{
				printf("%c",a[k++]);
				continue;
			}
			k++;
		}
	}
	return 0;
}



