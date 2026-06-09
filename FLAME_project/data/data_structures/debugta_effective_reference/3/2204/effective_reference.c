#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
int main(){
	char s[105];
	char *wc=NULL;
	int i,wd;
	S("%s",s);
	wc=strchr(s,'.');
	if(wc==NULL)
	{
		puts(s);
	}
	else if(wc-s==1){
		if(s[0]=='0'){
			for(i=2;i<strlen(s);i++){
				if(s[i]!='0'){
					wd=i;
					break;
				}
			}
			if(wd==strlen(s)-1){
				P("%c",s[wd]);
				for(i=wd+1;s[i]!='\0';i++)
				{
					P("%c",s[i]);
				}
				P("e-%d",wd-1);
			}
			else{
				P("%c",s[wd]);
				P(".");
				for(i=wd+1;s[i]!='\0';i++){
					P("%c",s[i]);
				}
				P("e-%d",wd-1);
			}
		}
		else{
			for(i=0;i<strlen(s);i++)
			{
				P("%c",s[i]);
			}
			P("e0");
		} 
	}
	else{
		wd=wc-s;
		P("%c",s[0]);
		P(".");
		for(i=1;i<=wd-1;i++)
			P("%c",s[i]);
		for(i=wd+1;i<strlen(s);i++)
		    P("%c",s[i]); 
		P("e%d",wd-1);
	}
	return 0;
}

