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
	char *p=NULL;
	int i,l;
	S("%s",s);
	p=strchr(s,'.');
	if(p==NULL)
	{
		puts(s);
	}
	else if(p-s==1){
		if(s[0]=='0'){
			for(i=2;i<strlen(s);i++){
				if(s[i]!='0'){
					l=i;
					break;
				}
			}
			if(l==strlen(s)-1){
				P("%c",s[l]);
				for(i=l+1;s[i]!='\0';i++)
				{
					P("%c",s[i]);
				}
				P("e-%d",l-1);
			}
			else{
				P("%c",s[l]);
				P(".");
				for(i=l+1;s[i]!='\0';i++){
					P("%c",s[i]);
				}
				P("e-%d",l-1);
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
		l=p-s;
		P("%c",s[0]);
		P(".");
		for(i=1;i<=l-1;i++)
			P("%c",s[i]);
		for(i=l+1;i<strlen(s);i++)
		    P("%c",s[i]); 
		P("e%d",l-1);
	}
	return 0;
}

