#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
void f(int i);
char c[1024];
int main(int argc, char *argv[]) {
	int i,j,k,x;
	gets(c);
	for(i=0;c[i]!='\0';i++)	{
		if(c[i+1]!='-'){
			if(c[i]!='-')printf("%c",c[i]);
			continue;
		}	
		else f(i);
	}
	
		return 0;
}
void f(int i){
	char j;
	if(('a'<=c[i]&&c[i+2]<='z'||'A'<=c[i]&&c[i+2]<='Z'||'0'<=c[i]&&c[i+2]<='9')&&(c[i]<c[i+2])){
		for(j=c[i];j<c[i+2];j++){
			printf("%c",j);
		}
		return;
	}
	else printf("%c%c",c[i],c[i+1]);
	return;	
}

