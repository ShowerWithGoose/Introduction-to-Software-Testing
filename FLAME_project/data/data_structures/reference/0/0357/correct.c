#include<stdio.h>
#include<string.h>
#include<ctype.h>
char p[10000];

int main()
{
	gets(p);
	for(int i=0; i<(int)strlen(p);i++){
	if(p[i]!='-'){putchar(p[i]);}
	else{
		char c=p[i-1],d=p[i+1];
		if(d>c&&((islower(c)&&islower(d))||(isupper(c)&&isupper(d))||(isdigit(c)&&isdigit(d)))){
		for(int j=c+1;j<=d-1;j++){
			putchar(j);
		}  
		}
		else printf("-");
	}		
		
	}	
}

