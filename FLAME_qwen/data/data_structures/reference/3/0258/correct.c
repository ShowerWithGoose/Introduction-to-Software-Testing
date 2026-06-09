#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	gets(s);
	int i,j,k,l;
	if(s[0]!='0'){
		for(i=0;i<strlen(s);i++){
			j=i; 
			if(s[i]=='.') break; 
		} 
		if(j==strlen(s)-1){
			printf("%c.",s[0]);
			for(k=1;k<strlen(s);k++) printf("%c",s[k]);
			printf("e%d",j);
		}
		else{
			printf("%c.",s[0]);
			for(k=1;k<j;k++) printf("%c",s[k]);
			for(k=j+1;k<strlen(s);k++) printf("%c",s[k]);
			printf("e%d",j-1);
		}
	}
	else{
		for(i=2;i<strlen(s);i++){
			j=i; 
			if(s[i]!='0') break; 
		}
		if(j!=strlen(s)-1){
			printf("%c.",s[j]);
			for(k=j+1;k<strlen(s);k++) printf("%c",s[k]);
			printf("e-%d",j-1);	
		}
		else{
			printf("%c",s[j]);
			for(k=j+1;k<strlen(s);k++) printf("%c",s[k]);
			printf("e-%d",j-1);	
		}
	}
	return 0;
}

