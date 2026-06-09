#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define ll long long
char s[M],ch[M];
int head=0;
typedef struct {
	int cnt;
	char s[30];
} dict;
dict d[M];
int Max(int a,int b) {
	return a>b?a:b;
}
int Min(int a,int b) {
	return a<b?a:b;
}
//int *a=(int*)malloc(n*sizeof(int)+100);
void shellSort(dict *a, int len) {
	int i, j, k, gap;
	dict tmp;
	for (gap = len / 2; gap > 0; gap /= 2) {
		for (i = 0; i < gap; ++i) {
			for (j = i + gap; j < len; j += gap) {
				tmp = a[j];
				k = j - gap;
				while (k >= 0 && strcmp(a[k].s,tmp.s)>0) {
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = tmp;
			}
		}
	}
}
void check(char* ch) {
	int i,flag=0;
	for(i=0; i<head; i++) {
		if(strcmp(d[i].s,ch)==0) {
			d[i].cnt++;
			flag=1;
			break;
		}
	}
	if(flag==0) {
		strcpy(d[head].s,ch);
		d[head].cnt=1;
		head++;
	}
}
int main() {
	int i,j=0;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(s,M,in)!=NULL) {
		int len=strlen(s);
		for(i=0; i<len; i++) {
			if(isalpha(s[i])&&!isalpha(s[i+1])) {
				s[i]=tolower(s[i]);
				ch[j++]=s[i];
				check(ch);
				int lench=strlen(ch);
				for(j=lench-1; j>=0; j--) {
					ch[j]='\0';
				}
				j=0;
			} else if(isalpha(s[i])) {
				s[i]=tolower(s[i]);
				ch[j++]=s[i];
			}
		}
	}
	shellSort(d,head);
	for(i=0; i<head; i++) {
		printf("%s %d\n",d[i].s,d[i].cnt);
	}
	return 0;
}



