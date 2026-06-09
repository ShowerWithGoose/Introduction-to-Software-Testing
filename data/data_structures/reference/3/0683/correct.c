#include<stdio.h>
#include<string.h>
char s[10000];
int main(){
	int i=0,len=0,t=0;
	char *p;
	gets(s);
	p=strstr(s,".");
	len=strlen(s);
		if(p==NULL){
			if(len==1){
				printf("%s",s);
			}else{
				printf("%c",s[0]);
				for(t=len-1;s[t]=='0';t--);
				if(t!=0){
				printf(".");
				for(i=1;i<=t;i++){
					printf("%c",s[i]);
				}					
				}
				printf("e%d",len-1);
			}
		}else{
			if((p-s)==1){
				if(s[0]=='0'){
					p+=1;
					for(t=0;*p=='0';p++){
						t++;
					}
					if((p-s)==len-1){
						printf("%ce-%d",*p,len-2);
					}else{
						printf("%c.%se-%d",*p,p+1,t+1);
					}
				}else{
					printf("%se0",s); 
				}
			}else{
				printf("%c.",s[0]);
				for(i=1;s[i]!='.';i++){
					printf("%c",s[i]);
				}
				printf("%se%d",p+1,p-s-1);
			}
		}
	return 0;
}

