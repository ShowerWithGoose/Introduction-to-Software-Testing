#include<stdio.h>
#include<string.h>
int main(){
	char c[256]="0";
	gets(c);
	printf("%c",c[0]);
	for(int i=1;i<255;i++){
		int p=0;
		if(c[i]=='-'){
			if(c[i-1]<c[i+1]){
				if(c[i-1]>='a'&&c[i+1]<='z'){
					p=1;
			  		int j;
			  		j=c[i+1]-c[i-1]-1;
				  	for(int k=1;k<=j;k++){
				  		printf("%c",c[i-1]+k);
					}
				}
				else if(c[i-1]>='A'&&c[i+1]<='Z'){
					p=1;
			  		int j;
			  		j=c[i+1]-c[i-1]-1;
				  	for(int k=1;k<=j;k++){
				  		printf("%c",c[i-1]+k);
					}
				}
				else if(c[i-1]>='0'&&c[i+1]<='9'){
					p=1;
			  		int j;
			  		j=c[i+1]-c[i-1]-1;
				  	for(int k=1;k<=j;k++){
				  		printf("%c",c[i-1]+k);
					}
				}
			}
			if(p==0) printf("-");
		}
		else{
			printf("%c",c[i]);
		}
	}
	return 0;
}


