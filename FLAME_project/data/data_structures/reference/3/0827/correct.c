#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
int main(){
	char a[10000]={};
	int before=0,after=0,nosense=0,zero=0,i;
	gets(a);
	int m=strlen(a);
	for(i=0;a[i]!='.';i++)
		before++;
	for(i=before+1;a[i]=='0';i++)
	    zero++;
	for(i=m-1;a[i]=='0';i--)
	    nosense++;
	    after=m-nosense-before-1;
	if(before>=1&&a[before-1]>='1'){
		printf("%c.",a[0]);
		for(i=1;i<before;i++)
		printf("%c",a[i]);
		for(i=before+1;i<after+before+1;i++)
		printf("%c",a[i]);
		printf("e%d",before-1);
	}
	else{
		if(m-after-zero-1!=1)
		printf("%c.",a[zero+2]);
		else
		printf("%c",a[zero+2]);
		for(i=zero+3;i<after+before+1;i++)
		printf("%c",a[i]);
		printf("e%d",-zero-1);
	}
}


