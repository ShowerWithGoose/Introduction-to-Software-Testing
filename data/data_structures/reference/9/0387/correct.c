#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define LL long long
typedef struct  {
	int a;
	int b;
	int c;
	int d;
} LINE;


int main() {
	int i=0,n=0;
	int f,l;
	LINE line[111];
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d %d %d %d",&line[i].a,&line[i].b,&line[i].c,&line[i].d) ;
		//	printf("%d %d %d %d",line[i].a,line[i].b,line[i].c,line[i].d) ;
	}
	int j=0;
	int max=0;
	for (i = 0; i<n ; i++ ) {
		for (j = i+1; j<n; j++) {
			if(line[j].a < line[i].a) {
				LINE  p = line[i];
				line[i] = line[j];
				line[j] = p;
			}
		}
	}
//	for(i=0; i<n; i++) {
//		//	scanf("%d %d %d %d",&line[i].a,&line[i].b,&line[i].c,&line[i].d) ;
//		printf("%d %d %d %d \n",line[i].a,line[i].b,line[i].c,line[i].d) ;
//	}
	for(i=0; i<n; i++) {
		int t=i;
		int num=0;
		for(j=i+1; j<n; j++) {
			if(line[j].a == line[t].c && line[j].b == line[t].d) {
				num++;
				t=j;
			}
		}
		if(num > max) {
			max=num;
			f=line[i].a;
			l=line[i].b;
		}
	}
	printf("%d %d %d",max+1,f,l);
	return 0;
}


