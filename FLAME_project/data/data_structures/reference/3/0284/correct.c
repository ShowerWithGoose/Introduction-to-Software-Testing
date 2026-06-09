#include<stdio.h>
char s[120];
int main(){
	gets(s);
	int i=0,j=0,k;
	for(i=0;s[i]!='.';i++){};
	for(j=0;s[j]=='0'||s[j]=='.';j++){};
	k=i-j;
	if(k>0)k--;
	i=0;
	while(s[i]=='0'||s[i]=='.')i++;
	printf("%c",s[i]);
	if(s[i+1]!=0)printf(".");
	i++;
	while(s[i]!=0){
		if(s[i]=='.'){
			i++;
			continue;
		}
		else printf("%c",s[i]);
		i++;
	}
	printf("e%d",k);
}
