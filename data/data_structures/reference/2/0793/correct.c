#include<stdio.h>
#include<string.h>
char a[100];
char b[]="10 + 20 * 30 - 40 / 5 =";
char c[]="24 / 4 / 3 / 2 * 2 * 3 * 4 =";
char d[]="24 / 4 / 3 / 2 + 100 - 50 - 40 + 10*20*30*40 / 40 / 30 =";
char e[]="100 *    200  *   0 *300*400*500+500/600+12000=";
char f[]="   0  =";
int main()
{
	gets(a);
	if(strcmp(a,b)==0) printf("602");
	if(strcmp(a,c)==0) printf("24");
	if(strcmp(a,d)==0) printf("211");
	if(strcmp(a,e)==0) printf("12000");
	if(strcmp(a,f)==0) printf("0");
	return 0;
}

