#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

char s[10000];

int main(){
	gets(s);
	
	int l=strlen(s);
	
	for(int i=0;i<l;i++){
		
		if(s[i]=='-'){
			if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1]){
				for(int j=1;s[i-1]+j<=s[i+1];j++) printf("%c",s[i-1]+j);
				i+=1;
				continue;
			}
			else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1]){
				for(int j=1;s[i-1]+j<=s[i+1];j++) printf("%c",s[i-1]+j);
				i+=1;
				continue;
			}
			else if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<s[i+1]){
				for(int j=1;s[i-1]+j<=s[i+1];j++) printf("%c",s[i-1]+j);
				i+=1;
				continue;
			}
		}
		
		printf("%c",s[i]);
		
	}
    
	return 0;
}



