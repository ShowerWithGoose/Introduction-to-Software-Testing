#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 


int main(){
	char str[1000000];
	char str2[1000000];
	char *c;
	gets(str);
	int j=strlen(str);
	if(j>=3){
		int i,j;
		
		for(i=1;i<j-1;i++){
			if(str[i]=='-'){
				if(str[i-1]<str[i+1]-1){
					char m[26]={0};
					if(str[i-1]>='0'&&str[i+1]<='9'){
						str[i]='\0';
						c=&str[i+1];
						strcpy(str2,c);
						for(j=0;j<str[i+1]-str[i-1]-1;j++)
							m[j]=str[i-1]+1+j;
						strcat(str,m);
						strcat(str,str2);
						
					}else if(str[i-1]>='A'&&str[i+1]<='Z'){
						str[i]='\0';
						c=&str[i+1];
						strcpy(str2,c);
						for(j=0;j<str[i+1]-str[i-1]-1;j++)
							m[j]=str[i-1]+1+j;
						strcat(str,m);
						strcat(str,str2);
	
					}else if(str[i-1]>='a'&&str[i+1]<='z'){
						str[i]='\0';
						c=&str[i+1];
						strcpy(str2,c);
						for(j=0;j<str[i+1]-str[i-1]-1;j++)
							m[j]=str[i-1]+1+j;
						strcat(str,m);
						strcat(str,str2);
		
					}
					j=strlen(str);	
					
				}
			}
		}
	}
	puts(str);
	return 0;
} 

