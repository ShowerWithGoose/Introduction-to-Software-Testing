#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	int c=0,k=0,i,n;
	gets(s);
	n=strlen(s);
	if(s[0]==48){
		for(i=1;s[i]!='\0';i++){
            if(s[i]==48&&c==0){
			k-=1;
			}
			else if(s[i]!=48&&s[i]!=46&&c==0){
			   printf("%c",s[i]);
			   c=1;
			   k-=1;
			}
			else if(s[i]!=46&&c==1) {
				printf(".%c",s[i]);	
				c=2;
			}
			else if(s[i]!=46&&c==2) {
				printf("%c",s[i]);
			}	
		}
	}
	else if(s[0]!=48){
	while(s[n-1]==48){
		k+=1;
		n=n-1;
	}
		printf("%c",s[0]);
		for(i=1;i<n;i++){
			if(s[i]!=46&&c==0){
				printf(".%c",s[i]);
				k+=1;
				c=1;
			}
			else if(s[i]!=46&&c!=0){
				printf("%c",s[i]);
				if(c==1)k+=1;
			}
			else if(s[i]==46){
				if(c==0)printf(".");
				c=2;}
		}
	}
	printf("e%d",k);
	return 0;
}

