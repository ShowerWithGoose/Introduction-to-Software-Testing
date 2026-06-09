#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char s[200],a[200],ch;
	int i,j,k,len;
	gets(s);
	len=strlen(s);
	for(i=0,j=0;i<len;i++){
		if(s[i]=='-'){
			if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<=s[i+1]){
				for(ch=s[i-1]+1;ch<s[i+1];ch++){
					a[j++]=ch;
				}
			}
			 else if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<=s[i+1]){
				for(ch=s[i-1]+1;ch<s[i+1];ch++){
					a[j++]=ch;
				}
			}
			else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<=s[i+1]){
				for(ch=s[i-1]+1;ch<s[i+1];ch++){
					a[j++]=ch;
				}
			}
			else{
				a[j++]=s[i];
			}
		}
		else{
			a[j++]=s[i];
		}
	}
	a[j]='\0';
	puts(a);
	return 0;
}



