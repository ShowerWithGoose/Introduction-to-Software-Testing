#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[1000];
int main(){
    int i; 
    char a;
	gets(s);
    for(i=0;i<strlen(s);i++){
    	if(s[i]=='-'){
    		if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<=s[i+1])
    			for(a=s[i-1]+1;a<s[i+1];a++)
    			  printf("%c",a);
			else if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<=s[i+1])
				for(a=s[i-1]+1;a<s[i+1];a++)
			      printf("%c",a);
			else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<=s[i+1])
			    for(a=s[i-1]+1;a<s[i+1];a++)
			      printf("%c",a);
			else printf("%c",s[i]);
		}
		else
		   printf("%c",s[i]);
	}
    
	return 0;
}

