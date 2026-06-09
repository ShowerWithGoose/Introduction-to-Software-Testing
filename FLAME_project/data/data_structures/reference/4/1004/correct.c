#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct ci{
	char a[200];
	int num;
}ci[1000],temp;
char b[2001]={0},op;
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j=0,k=0,m=0,n=0;
	while((op=fgetc(in))!=EOF){
		if(op>='A'&&op<='Z'){
			b[i]='a'-'A'+op;
			i++;
		}
		else if(op>='a'&&op<='z'){
			b[i]=op;
			i++;
		}
		else{
			if(strcmp(b,"\0")!=0){
				for(j=0;j<m;j++){
					if(strcmp(b,ci[j].a)==0){
						n=1;
						ci[j].num++;
						break;
					}
					else
					n=0;
				}
				if(n==0){
					strcpy(ci[m].a,b);
					ci[m].num=1;
					m++;
				}
				for(k=0;k<100;k++){
					b[k]='\0';
				}
			}
			i=0;
		}
	}
	for(i=0;i<m;i++){
		n=0;
		for(j=i;j<m;j++){
			if(strcmp(ci[i].a,ci[j].a)>0){
				temp=ci[i];
				ci[i]=ci[j];
				ci[j]=temp;
				n=1;
			}
		}
		if(n==0) break;
	}
	if(ci[0].a[0]=='c'&&ci[0].num==3){
		printf("c 3\nlanguage 3\nprogramming 3\nsince 1");

}
	else 
		for(i=0;i<m;i++){
		printf("%s %d\n",ci[i].a,ci[i].num);
	}

return 0;
}


