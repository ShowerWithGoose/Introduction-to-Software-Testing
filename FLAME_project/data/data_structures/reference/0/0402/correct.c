#include <stdio.h>
#include <math.h>
int main(){
	char s[10000];
	gets(s);
	int i,k;
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='-') printf("%c",s[i]);
		else{
			if((s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])||(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])||(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])){
				for(k=1;s[i-1]+k<s[i+1];k++) printf("%c",s[i-1]+k);
			}
			else printf("-");
		}
	}
	return 0;
} 

