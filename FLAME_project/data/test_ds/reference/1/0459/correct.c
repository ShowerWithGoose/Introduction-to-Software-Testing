#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char s[10000],a[10000];
	scanf("%s",s);
	int j=0,p=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]!='-'){
			a[j++]=s[i];
			continue;
		}
		if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]){
			p=1;
			for(int k=1;s[i-1]+k<s[i+1];k++){
				a[j++]=s[i-1]+k;
			}
		}
		if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]){
			p=1;
			for(int k=1;s[i-1]+k<s[i+1];k++){
				a[j++]=s[i-1]+k;
			}
		}
		if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]){
			p=1;
			for(int k=1;s[i-1]+k<s[i+1];k++){
				a[j++]=s[i-1]+k;
			}
		}
		if(p==0){
			a[j++]='-';			
		}
		p=0;
	}
	a[j]='\0';
	printf("%s",a);
	return 0;
}
