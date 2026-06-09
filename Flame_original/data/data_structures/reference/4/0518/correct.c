#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int i,k;
int t[10005],cnt;
char a[10005],u;
typedef struct words {
	char word[100];
	int time;
} W;
W b[10005];
int cmp(const void *a , const void *b) {
	W *p= (W*)a;
	W *q=(W*)b;
	return strcmp(p->word,q->word);
}

void Lower(char a[]) {
	int l=strlen(a),h;
	for(h=0; h<l; h++)
		a[h]=tolower(a[h]);
}
void Writein() {
	int h,n=0;
	for(h=0; h<strlen(a); h++) {
		if(isalpha(a[h])) {
			b[cnt].word[n++]=a[h];
			b[cnt].time=1;
		} else {
			cnt++;
			n=0;
		}
	}
	cnt++;
}

int main() {
	FILE *in;
	char FILENAME[]="article.txt";
	in=fopen(FILENAME,"r");
	if((in=fopen(FILENAME,"r"))==NULL) {
		printf("cannot open file\n");
		return;
	}
	while((u=fgetc(in))!=EOF)
		a[i++]=u;
	fclose(in);
	Lower(a);
	Writein();
	for(k=0; k<cnt; k++) {
		if(strlen(b[k].word))
			b[k].time=1;
	}
	qsort(b,cnt,sizeof(W),cmp);
	for(i=0; i<cnt; i++) {
		for(k=i+1; k<cnt; k++) {
			if(strcmp(b[i].word,b[k].word)==0) {
				b[i].time++;
				t[k]=1;
			}
		}
	}
	for(k=1; k<cnt; k++) {
		if(!t[k]&&b[k].time) {
			printf("%s %d\n",b[k].word,b[k].time);
		}
	}
	return 0;
}


