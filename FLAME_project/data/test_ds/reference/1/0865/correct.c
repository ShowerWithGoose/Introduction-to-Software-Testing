#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main(){
	char s[1005];
	gets(s);
	int i,j,len,flag=0;
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]=='-'){
			if(s[i+1]>s[i-1]){
				if((isdigit(s[i-1])&&isdigit(s[i+1]))||('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i+1]&&s[i+1]<='Z')||('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z')){
					for(j=s[i-1]+1;j<s[i+1];j++){
						printf("%c",j);
						flag=1;
					}
				}
			}
			if(flag==0) printf("-");
			flag=0;
		}
		else printf("%c",s[i]);
	}
	return 0;
}


