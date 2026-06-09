#include<stdio.h>
#include<string.h>
#include<ctype.h> 
char c[2000];
int main(){
	scanf("%s",c);
	int n=strlen(c); 
	for(int i=0;i<n;++i){
		printf("%c",c[i]);
		if(c[i+1]=='-'){
			int f=0;
			if(islower(c[i])&&islower(c[i+2])){
				f=c[i]<c[i+2]; 
			}
			else if(isupper(c[i])&&isupper(c[i+2])){
				f=c[i]<c[i+2];
			}
			else if(isdigit(c[i])&&isdigit(c[i+2]))
				f=c[i]<c[i+2];
			if(f){
				for(int s=c[i]+1;s<=c[i+2]-1;++s)
					printf("%c",s);
				i++;
			}
		}
	}
	return 0;
}

