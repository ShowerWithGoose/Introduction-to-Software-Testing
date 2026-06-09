#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE (105)

char buffer[MAX_SIZE];
int len;
int dotpos=-1;
int first_NZ=-1;
int last_NZ=-1;
int size_NZ=0;

int main(){
	gets(buffer);
	len=(int)strlen(buffer);
	for(int i=0;i<len&&dotpos==-1;i++)
		if(buffer[i]=='.')dotpos=i;
	if(dotpos==-1)
		dotpos=len;
	for(int i=0;i<len&&first_NZ==-1;i++){
		if('1'<=buffer[i]&&buffer[i]<='9')
			first_NZ=i;
	}
	for(int i=len-1;i>=0&&last_NZ==-1;i--){
		if('1'<=buffer[i]&&buffer[i]<='9')
			last_NZ=i;
	}
	for(int i=0;i<len;i++){
		if('1'<=buffer[i]&&buffer[i]<='9')
			size_NZ++;
	}
	int dist=dotpos-first_NZ-(dotpos>first_NZ);
	if(first_NZ==-1){
		printf("0e0");
		return 0;
	}
	else printf("%c",buffer[first_NZ]);
	if(size_NZ>1){
		printf(".");
		for(int i=first_NZ+1;i<=last_NZ;i++){
			if(buffer[i]!='.')printf("%c",buffer[i]);
		}
	}
	printf("e%d",dist);
	return 0;
}
/*
123.456
*/


