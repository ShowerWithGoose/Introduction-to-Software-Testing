#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[1000],b[1000];
int i,j,len;

int main(){
	scanf("%s",a);
	len = strlen(a);
	for(i=0;i<len;i++){
		if(a[i+1]!='-') printf("%c",a[i]);
		else{
			if((isupper(a[i])==isupper(a[i+2]))&&(islower(a[i])==islower(a[i+2]))&&(isdigit(a[i])==isdigit(a[i+2]))){
				j = a[i];
				while(j<a[i+2]){
					printf("%c",j++);
				}
				i++;
			}
			else printf("%c",a[i]);
		}
	}
	return 0;
} 

