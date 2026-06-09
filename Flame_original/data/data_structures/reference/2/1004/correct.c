#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int f(int x){
	int count=0;
	while(x!=0){
		x=x/10;
		count++;
	}
	return count;
}
int check(char b1,char b2){
	if(b1=='*'||b1=='/')
	return 0;
	else if(b2=='*'||b2=='/')
		return 1;
		else return 0;
}
int jisuan(int x,char b,int y){
	if(b=='+')
		return x+y;
	if(b=='-')
		return x-y;
	if(b=='*')
		return x*y;
	if(b=='/')
		return x/y;
}

char s[2000];
int main(){
	
	gets(s);
	int i=0,j=0;
	for(i=j=0;s[i]!='\0';i++)
		if(s[i]!=' ')
		s[j++]=s[i];
		s[j]='\0';
	
		
	int a1,a2,a3,m;
	char b1,b2,b3;
		a1=atoi(&s[0]);
		b1=s[0+f(a1)];
		m=0+f(a1)+1;
		
		if(b1=='=')
			printf("%d",a1);
		
		else{
			a2=atoi(&s[m]);
			b2=s[m+f(a2)];
			m=m+f(a2)+1;
			if(b2=='=')
				printf("%d",jisuan(a1,b1,a2));
				
			else{
				while(b2!='='){
					a3=atoi(&s[m]);
					b3=s[m+f(a3)];
					if(check(b1,b2)==0){
						a1=jisuan(a1,b1,a2);
						a2=a3;
						b1=b2;
					}
					else{
						a2=jisuan(a2,b2,a3);
					}
					b2=b3;
					m=m+f(a3)+1;	
				}
				printf("%d",jisuan(a1,b1,a2));
			}
		}
return 0;
}


