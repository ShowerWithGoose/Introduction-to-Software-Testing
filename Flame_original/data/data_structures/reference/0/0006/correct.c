#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

char s[1024], r[1024];
char *p, *q;
int l;
void expand();
void printout();

int main(){
	gets (s);
	l=strlen(s);
	q=s;
	for (p=strchr(s+1, '-'); p!=NULL; p=strchr(p+1, '-')){
		
		if (*(p-1)>='A'&&*(p+1)<='Z'&&*(p-1)<*(p+1) 
		||*(p-1)>='a'&&*(p+1)<='z'&&*(p-1)<*(p+1)
		||*(p-1)>='0'&&*(p+1)<='9'&&*(p-1)<*(p+1)) expand();
	}
	puts(q);
	return 0;
}

void expand(){
	if (p==q&&q!=s){
		for (char r=*(p-1)+1; r<=*(p+1); r++) putchar(r);
		q+=2;
	}
	else{
		printout();
		for (char r=*(p-1); r<=*(p+1); r++) putchar(r);
		q+=3;
	}
	
}
void printout(){
	for (; q<=p-2; q++) putchar(*q);
}



