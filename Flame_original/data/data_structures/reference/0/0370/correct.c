#include<stdio.h>
int main(){
	char s[100]={},j;
	int i;
	gets(s);
	for(i=0;s[i];i++){
		if(s[i]!='-') printf("%c",s[i]);
		else if(s[i]=='-'){
			if((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9')){
				j=s[i-1]+1;
				while(j<s[i+1]){
					printf("%c",j);
					j++;
				}
			}
			else printf("-");
		}
	}
	return 0;
	
	
	
}

