#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
int main(){
	char c[105];
	char cc[105];
	gets(c);
	int a,b,d=0,e=0,f,g,h,i,j;
	if(c[1]=='.'&&c[0]=='0'){
		for(b=2;b<strlen(c);b++){
			if(c[b]=='0'){
				d++;
			}}
			
	pf("%c",c[2]);
	if(c[3]!='\0'){
	
	pf(".");pf("%s",&c[3]);}
	else{pf("%s",&c[3]);
	
	}pf("e-%d",d+1);
	
	}

else{
	for(b=0;b<strlen(c);b++){
		if(c[b]=='.'){
			break;
		}
	}
	strcpy(cc,&c[1]);
	pf("%c.",c[0]);
	for(i=0;i<strlen(cc);i++){
		if(cc[i]!='.'){
			pf("%c",cc[i]);
		}
	}pf("e%d",b-1);
}
	return 0;
} 


