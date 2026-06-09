/*
1.判断是否是字母

isalpha()，若是返回true，否则返回false

2.判断是否是数字

isdigit(),若是返回true，否则返回false

3.判断是否是大写字母

isupper(),  若是返回true，否则返回false；

4.判断是否是小写字母

islower(),若是返回true，否则返回false;

5.大写转化为小写字母

tolower()

6.小写转化为大写字母

toupper()

*/
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ll long long

typedef struct Word {
	char c[20];
	int len;
	bool ok;
	int count;
} word;

word w[1000];

int i=0,j=0,k=0,m=0;//i结构体下标；j结构体字符串下标

int judge(word a,word b) {
	if(strcmp(a.c,b.c)==0) return 1;
	return 0;
}

int cmp(const void* a,const void* b) {
	word *c=(word*)a,*d=(word*)b;
	if(strcmp(c->c,d->c)>0)	return 1;
	if(strcmp(d->c,c->c)<0)	return -1;
	return 0;
}

int main() {
	char in;
	freopen("article.txt","r",stdin);
	while((in = getchar()) != EOF) {
//		putchar(in);
//		in=getchar();
//		if(in==EOF) break;
		if(isalpha(in)) {
			w[i].len ++;
			if(isupper(in)) {
				w[i].c[j++]=tolower(in);
			} else {
				w[i].c[j++]=in;
			}
		} else {
			if(w[i].len ==0) {
				j=0;
				continue;
			} else {
				i++;
				j=0;
			}
		}
	}
	for(k=0; k<i; k++) {
		if(w[k].ok ==true)continue;
		for(m=0; m<i; m++) {
			if(w[m].ok ==true)continue;
			if(k==m) {
				w[k].count ++;
				continue;
			} else {
				if(judge(w[k],w[m])) {
					w[k].count ++;
					w[m].ok =1;
				}
			}
		}
	}
	qsort(w,i,sizeof(word),cmp);
	for(k=0; k<i; k++) {
		if(w[k].ok==false) {
			printf("%s %d\n",w[k].c ,w[k].count );
		}
	}
	return 0;
}

