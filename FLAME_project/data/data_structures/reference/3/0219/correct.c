#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s[1000];
int main(){
	int cntn=1,cntp=-1,len,i,j,k;
	gets(s);
	len=strlen(s);
	if (s[0]=='0'){
		for (i=2;i<len;i++){
			if (s[i]=='0') cntn++;
			else {
				j=i;
				break;
			}
		}
		
		if (j==len-1) {
			printf("%c",s[len-1]);
			printf("e-%d",cntn);
			
		}
		else{
			printf("%c.",s[j]);
			for (i=j+1;i<len;i++){
				printf("%c",s[i]);
		}
			printf("e-%d",cntn);
		}
		
		
	}
	else {
		for (i=0;i<len;i++){
			if (s[i]!='.') cntp++;
			if (s[i]=='.') break;
		}
		printf("%c.",s[0]);
		for (i=1;i<len;i++){
			if (s[i]=='.') continue;
			else printf("%c",s[i]);
		}
		printf("e%d",cntp);
	}
	
		
	

	
	
	
	
	return 0;
}

