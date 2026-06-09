#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[103]; 
//char s1[103]; 

int main(){
	int i,j,k,l,m,n;
	int len=-1,zero=0;
	gets(s);
	if(s[1]=='0'&&s[0]=='-'){
			
			zero++;
			for(k=3;s[k]=='0';k++){
				zero++;
			}
			printf("-%c",s[k]);
			k++;
			if(s[k]!='\0'){
				printf(".");
			}
			for(;s[k]!='\0';k++){
				printf("%c",s[k]);
			}
			printf("e-%d",zero);
			goto out;
		}
		else if(s[0]=='0'){
			zero++;
			for(k=2;s[k]=='0';k++){
				zero++;
			}
			printf("%c",s[k]);
			k++;
			if(s[k]!='\0'){
				printf(".");
			}
			for(;s[k]!='\0';k++){
				printf("%c",s[k]);
			}
			printf("e-%d",zero);
			goto out;
		}
	for(i=0;s[i]!='.'&&s[i]!='\0';i++){
		    len++;
		}
		//s1[0]=s[0];
		//s1[1]='.';	
		if(s[0]=='-'){
			printf("-%c.",s[1]);
			for(j=2;s[j]!='.'&&s[j]!='\0';j++){
				printf("%c",s[j]);
			}
			if(s[j]!='\0'){
				for(j++;s[j]!='\0';j++){
					printf("%c",s[j]);
				}
			}
			len--;
			printf("e%d",len);
		}
		else{
			printf("%c.",s[0]);
			for(j=1;s[j]!='.'&&s[j]!='\0';j++){
				printf("%c",s[j]);
			}
			if(s[j]!='\0'){
				for(j++;s[j]!='\0';j++){
					printf("%c",s[j]);
				}
			}
			
			printf("e%d",len);
		}
		
		
	
	out :
	
	
	
	return 0;
}



