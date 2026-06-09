#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

char s[10000];

int main(){
	gets(s);
	
	int l=strlen(s);
	
	int flag1=0,flag2=0,k;
	
	while(s[flag1]=='0'||s[flag1]=='.') flag1++;
	
	while(s[flag2]!='.'&&flag2<l) flag2++;
	
    k=flag1;
    
    printf("%c",s[flag1]);
    
    if(flag1!=l-1) printf(".");
    
    for(flag1++;flag1<l;flag1++){
    	if(flag1!=flag2) printf("%c",s[flag1]);
	}
    
    printf("e");
    
    if(flag2>k) printf("%d",flag2-k-1);
    
    else printf("%d",flag2-k);
		    
	return 0;
}

