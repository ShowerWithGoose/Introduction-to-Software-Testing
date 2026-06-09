#include <stdio.h>
#include <string.h>
char s[10000000];
int i,j,k,a,b=0,c=0,d=0,f;
int main(){
	gets(s);
	a=strlen(s);
	for(i=0;i<a;i++){
		if(s[i]=='.')
		b=i;
		if(s[i]!='0'&&s[i]!='.')
		d=i;
	}
	for(i=a-1;i>=0;i--){
		if(s[i]!='0'&&i!=b)
		c=i;
	}
	if(b-c>=1)
	f=b-c-1;
	else
	f=b-c;
	if(d-c==0){
		printf("%c",s[c]);
		printf("e%d",f);
	}
	else{
		printf("%c.",s[c]);
	    for(i=c+1;i<=d;i++){
		    if(b!=i)
		        printf("%c",s[i]);
	    }
	    printf("e%d",f);
	}
	return 0;
}

