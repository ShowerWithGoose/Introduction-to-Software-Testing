#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
char expr[105];

void notation(char expr[]){
	int i=0;
	int dot_pos,num_pos,expo;
	if(expr[i]=='0'){//the initial num is zero
		while(expr[i]!='.'){
			i++;
		}
		dot_pos=i;
		i++;
		while(expr[i]=='0'){
			i++;
		}
		num_pos=i;
		expo=-1*(num_pos-1);
		printf("%c",expr[num_pos]);
		if(expr[num_pos+1]!='\0'){
			printf(".");
		}
		i++;
		while(expr[i]!='\0'){
			printf("%c",expr[i]);
			i++;
		}
		printf("e%d",expo);
	}
	else{//the initial num is not zero
		while(expr[i]!='.'){
			i++;
		}
		dot_pos=i;
		expo=dot_pos-1;
		printf("%c",expr[0]);
		int flag=0;
		for(int j=1;expr[j]!='.';j++){
			if(expr[j]!='0'){
				flag=1;//flag==1:the num after the 2nd are not all zero
			}
		}
		if(flag==1||dot_pos==1){
			printf(".");
		}
		else{
			printf("e%d",expo);
			return;
		}
		i=1;
		while(expr[i]!='\0'){
			if(expr[i]=='.'){
				i++;
			}
			else{
				printf("%c",expr[i]);
				i++;
			}
		}
		printf("e%d",expo);
	}
}

int main()
{
	gets(expr);
	notation(expr);	
	
 	return 0;
 }

