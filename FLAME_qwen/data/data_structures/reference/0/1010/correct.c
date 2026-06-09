#include<stdio.h>
#include<string.h>
int main(){
	int j;
	char s[1000];
	gets(s);
	j=strlen(s);
	for(int i=0;i<j;i++){
		if(s[i]=='-'){
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]){
				for(char c=s[i-1]+1;c<s[i+1];c++){
					printf("%c",c);
					
					
				}
			}
		else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]){
						for(char c=s[i-1]+1;c<s[i+1];c++){
							printf("%c",c);
							}
		}
		else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]){
								for(char c=s[i-1]+1;c<s[i+1];c++){
									printf("%c",c);
				}
	}
        else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	
		
return 0;
}

