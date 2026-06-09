#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	char in[105]={0};
	int i,p;
	gets(in);
	if(in[0]=='0'){
		for(i=2;in[i]=='0';i++);
		p=1-i;
		if(in[i+1]=='\0'){
			printf("%c",in[i++]);}
		else{
			printf("%c.",in[i++]);}
		for(;in[i]!='\0';i++) printf("%c",in[i]);
		printf("e%d",p);
	}
	else{
		printf("%c.",in[0]);
		for(p=1;in[p]!='.';p++);
		p--;
		for(i=1;in[i]!='\0';i++){
			if(i!=p+1) printf("%c",in[i]);
		}
		printf("e%d",p);
	}
	return 0;
}

