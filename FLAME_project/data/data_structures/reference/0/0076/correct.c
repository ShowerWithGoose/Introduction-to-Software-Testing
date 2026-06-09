#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
int main(){
	int i;
	char a[1000],c;
	gets(a);
	int L=strlen(a);
	for(i=0;i<L;i++){
		if(a[i]=='-'){
			if((a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])){
				for(c=a[i-1]+1;c<a[i+1];c++){
					printf("%c",c);
				}
			}
			else{
				printf("%c",a[i]);
			} 
		}
		else{
			printf("%c",a[i]);
		}
	}
	return 0;
}



