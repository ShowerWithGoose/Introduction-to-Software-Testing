#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pr printf
#define sf scanf
#define rt return
#define gcr getchar
#define pcr putchar
#define pi 3.14159265
#define sw switch
#define brk break
#define ctn continue
#define sc(x) scanf("%d",&x)
#define ef else if
#define slf(x) scanf("%lf",&x)
#define pf(x) printf("%d\n",x)//\n
#define max(a,b) ((a)>=(b)?(a):(b))//可修改>=or>
#define min(a,b) ((a)<=(b)?(a):(b))
#define sl strlen
#define PR printf("\n");
#define For(n) for(int i=0;i<n;++i)
#define New(p) p=(node*)malloc(sizeof(node))
#define itn int
#define fsf fscanf
#define fpr fprintf

typedef struct node {
	char word[200];
	int cnt;
	struct node *next;
} node;

int getWord(FILE *bfp, char word[]) {
	int i = 0;
	char temp;

	while ((temp = fgetc(bfp)) != EOF) {
		if (isalpha(temp)) {
			word[i] = tolower(temp);
			i++;
		} else if (i > 0) { //说明i中已经至少有一个字符
			word[i] = '\0';
			return 0;
		}
	}
	return EOF;
}


void sort(node *L, int n) {//
	node T;
	for (itn i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (strcmp(L[i].word, L[j].word) > 0) {
				T = L[i];
				L[i] = L[j];
				L[j] = T;
				//
			}
		}
	}
}

void delRepeat(node *L, int n) {
	for (int i = 0; i < n; ++i) {
		//int cnt = 1;
		for (int j = i + 1; j < n; ++j) {
			if (isalpha(L[i].word[0]) == 0)
				;
			if (strcmp(L[i].word, L[j].word) == 0) {
				strcpy(L[j].word, "-1");
				L[i].cnt++;
			}
		}
	}
}

void Tolower(char *s) {
	for (int i = 0; i < sl(s); ++i) {
		s[i] = tolower(s[i]);
	}
}

int main() {
	node L[2000];
	FILE *in = fopen("article.txt", "r");
	int cnt = 0;
	for (int i = 0; getWord(in, L[i].word) != EOF; ++i) {
		cnt++;
		L[i].cnt = 1;
		//wash(L[i].word);
		//	puts(L[i].word);
		//Tolower(L[i].word);
	}
//	PR
//	for (int i = 0; i < cnt; ++i) {
//
//	}
//	for (int i = 0; i < cnt; ++i) {
//
//	}
	sort(L, cnt);
	delRepeat(L, cnt);
	for (int i = 0; i < cnt; ++i) {
		if (isalpha(L[i].word[0]))
			pr("%s %d\n", L[i].word, L[i].cnt);
	}
	rt 0;
}
/*
all 1
as 2
do 3
every 1
have 1
hear 1
heart 1
long 1
not 3
sleep 1
spend 1
take 1
that 1
thing 1
to 1
want 1
you 3
*/





















