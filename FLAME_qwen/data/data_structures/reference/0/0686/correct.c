#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 10000000

void expand(char* in, char* ret);

char input[M], output[M];
int main(){
	gets(input);
	expand(input, output);
	puts(output);
	return 0;
}

void expand(char* in, char* ret){
	int i, j, k;
	i = j = 0;
	for(i; in[i]!='\0'; i++){
		if(in[i] == '-'){
			if(in[i-1]<='9'&&in[i+1]<='9' && in[i-1]>='0'&&in[i+1]>='0' && in[i-1]<in[i+1]){
				for(k=in[i-1]+1; k<=in[i+1]-1; k++)
					ret[j++] = k;
			}
			else
			if(in[i-1]<='z'&&in[i+1]<='z' && in[i-1]>='a'&&in[i+1]>='a' && in[i-1]<in[i+1]){
				for(k=in[i-1]+1; k<=in[i+1]-1; k++)
					ret[j++] = k;
			}
			else
			if(in[i-1]<='Z'&&in[i+1]<='Z' && in[i-1]>='A'&&in[i+1]>='A' && in[i-1]<in[i+1]){
				for(k=in[i-1]+1; k<=in[i+1]-1; k++)
					ret[j++] = k;
			}
			else ret[j++] = '-';
		}
		else {
			ret[j++] = in[i];
		}
	}
	ret[j] = '\0';
}

