#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAXN 120
//define mst(s) memset(s,0,sizeof(s))
char s[MAXN];
int main(void)
{
	gets(s);
	int i,j,k,n,m;
	int fst=-1,pt;
	int idx;


	for(i=0; s[i]!='\0'; i++) {
		if(s[i]=='.') {
			pt=i;
		} else;
		if(fst==-1) {
			if('1'<=s[i]&&s[i]<='9') {
				fst=i;
			} else;
		} else;
	}
	if(fst<pt) { //get the index
		idx=pt-1-fst;
	} else {
		idx=-1*(fst-pt);
	}
	printf("%c",s[fst]);
	if(s[fst+1]!='\0') {
		printf(".");
	} else;
	for(i=fst+1; s[i]!='\0'; i++) {
		if(s[i]!='.'){
			printf("%c",s[i]);
		}else;
	}
	printf("e%d\n",idx);



	return 0;
}



