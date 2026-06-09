#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int f(char **r);
int add(char **r);
int mul(char **r);

char s[1000],str[1000];
char *p=s;

int main(){
	gets(str);
	int i,j;
	for(i=0,j=1;str[i]!='\0';i++){
		if(str[i]!=' '&&str[i]!='=') s[j++]=str[i];
	}
	s[0]='+';
	s[j]='\0';
	printf("%d",f(&p));
	return 0;
} 

int f(char **r){
	int t=0;
	
	while(**r!=NULL){
		if(**r=='+') t+=add(r);
		else t-=add(r);
	}
	
	return t;
	
}

int add(char **r){
	int x=0;
	*r+=1;
	while(isdigit(**r)){
		x=10*x+(**r-'0');
		*r+=1;
	}
	while(**r=='*'||**r=='/'){
	    if(**r=='*'){
	    	*r+=1;
	        x*=mul(r);
	    }
    	else{
		    *r+=1;
    	    x/=mul(r);
	    }
	}
	return x;
}

int mul(char **r){
	int x=0;
	while(isdigit(**r)){
		x=10*x+(**r-'0');
		*r+=1;
	}
	return x;
}




