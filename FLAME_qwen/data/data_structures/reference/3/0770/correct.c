#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	double in;
	char ch[999];
	gets(ch);
	sscanf(ch,"%lf", &in);
	if(1<=abs(in) && abs(in)<10){
		printf("%se0",ch);
		return 0;	
	}
	int p=0;
	while(ch[p] != '.')	p++;
	if(p >= 2){
		for(int i=0; ch[i]!='\0'; i++){
			if(1==i)	printf(".");
			if(ch[i] == '.')	continue;
			printf("%c", ch[i]);
		}
		printf("e%d", p-1);
		return 0;
	}
	int wei=1;
	while(ch[++p]=='0')	wei++;
		for(int i=0; ch[p+i]!='\0'; i++){
			if(1==i)	printf(".");
			printf("%c", ch[p+i]);
		}
		printf("e-%d", wei);
		return 0;
}

