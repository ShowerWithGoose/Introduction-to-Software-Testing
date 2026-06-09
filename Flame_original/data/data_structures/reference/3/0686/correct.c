#include<stdio.h>
#include<math.h>
#include <string.h>


int main ()
{
	char s[2000];
	gets(s);
	int len=strlen(s);
	int noI0=len-1,noF0=0,p; 
	p=len;
	for(int i=len;i>=0;i--){
		if(s[i]=='.'){
			p=i;break;
		}
	}
	for(int i=0;s[i]!='\0';i++){
		if(s[i]!='0'&&s[i]!='.') {
			noI0=i;
			break;
		}
		
	}
	for(int i=len-1;i>=0;i--){
		if(s[i]!='0'&&s[i]!='.') {
			noF0=i;
			s[i+1]='\0';
			break;
		}
	}
	len=strlen(s);

	for(int i=noI0;;i++){
		s[i-noI0]=s[i];
		if(s[i]=='\0') break;
	}
	if(noF0<noI0) printf("0");
	else if(noF0==noI0){
		if(p-noI0-1!=0)
			printf("%ce%d",s[0],p-noI0-1>=0?p-noI0-1:p-noI0);
		else printf("%c",s[0]);
	}else if(noF0>noI0){
		
		int ans=p-noI0-1;
		if(ans==0) {
			for(int i=0;s[i]!='\0';i++){
					printf("%c",s[i]);
			}
			printf("e0");	
		}else {
			printf("%c.",s[0]);
			for(int i=1;s[i]!='\0';i++){
				if(s[i]!='.')
					printf("%c",s[i]);
			}
			if(ans>0)
				printf("e%d",ans);
			else printf("e%d", ans+1);
		}
	}
	
    return 0;
 }

