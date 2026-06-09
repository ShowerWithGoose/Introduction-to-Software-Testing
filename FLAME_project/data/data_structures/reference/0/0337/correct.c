#include <stdio.h>

char s[100000];

int main(){
	gets(s);
	int j=0;
	for(;s[j]!='\0';j++){
		if(s[j+1] != '-') printf("%c",s[j]) ;
		else if(s[j]<='z'&&s[j]>='a'&&s[j+2]<='z'&&s[j+2]>s[j]) 
			{
				int n=0;
				for(;n<=s[j+2]-s[j]-1;n++)
					printf("%c",s[j]+n);
				j+=1;
			}
		else if(s[j]<='9'&&s[j]>='0'&&s[j+2]<='9'&&s[j+2]>s[j]) 
			{
				int n=0;
				for(;n<=s[j+2]-s[j];n++)
					printf("%c",s[j]+n);
				j+=2;
			}
		else if(s[j]<='Z'&&s[j]>='A'&&s[j+2]<='Z'&&s[j+2]>s[j]) 
			{
				int n=0;
				for(;n<=s[j+2]-s[j];n++)
					printf("%c",s[j]+n);
				j+=2;
			}
		else printf("%c",s[j]) ;
		
}
	
	
	
	return 0;
}

