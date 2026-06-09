#include<stdio.h>
int main(){
	char s[80];
    gets(s);
	int i,j; 
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='-')
		printf("%c",s[i]);
		else {
			if(s[i-1]>=65&&s[i+1]>s[i-1]&&s[i+1]<=90){
				for(j=0;s[i-1]<s[i+1];j++){
					s[i-1]+=1;
					printf("%c",s[i-1]);
				}
				i=i+1;
			}
		    else if(s[i-1]>=97&&s[i+1]>s[i-1]&&s[i+1]<=122){
				for(j=0;s[i-1]<s[i+1];j++){
					s[i-1]+=1;
					printf("%c",s[i-1]);
				}
				i=i+1;
		    }
		    else if(s[i-1]>=48&&s[i+1]>s[i-1]&&s[i+1]<=57){
		    	for(j=0;s[i-1]<s[i+1];j++){
					s[i-1]+=1;
					printf("%c",s[i-1]);
				}
				i=i+1;
	}
	else printf("%c",s[i]);
	}}
	return 0;
}

