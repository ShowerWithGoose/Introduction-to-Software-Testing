#include<stdio.h>
#include<string.h>
int main(){
	char s[1005];
	gets(s);
	int i;
	for(i=1;s[i]!='\0';i++){
		if(s[i]=='-'&&s[i-1]<s[i+1]){
			if(s[i-1]>=48&&s[i-1]<=59&&s[i+1]>=48&&s[i+1]<=59||s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90||s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122){
				int j=s[i+1]-s[i-1];
				int k=strlen(s)-1;
				for(k=strlen(s)-1;k>i+1;k--){
					s[k+j-2]=s[k];
				}
				k=i;
				for(k=i;k<i+j;k++){
					s[k]=s[k-1]+1;
				}
			}
		}
	}
	puts(s);
	return 0;
}


