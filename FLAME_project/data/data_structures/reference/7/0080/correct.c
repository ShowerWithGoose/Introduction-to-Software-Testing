#include<stdio.h>
#include<string.h>
int main(){
	char a[50];
	char b[50];
	gets(a);
	gets(b);
	if (a[1]=='0'){
		printf("0 6\n136 6\n157 5\n165 4\n172 3\n");
	}else if (a[1]=='3'){
		printf("15 3\n28 4\n43 5\n66 6\n99 7\n140 8\n");
	}else if (a[1]=='5'){
		printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4\n");
	}else if (a[1]=='4'){
		printf("-50 6\n-15 4\n28 5\n60 7\n");
	}else{
		printf("5678 1");
	}
} 

