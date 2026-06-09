#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct word {
	char str[100];
	int cnt;
} words[100];
int cmp(const void*p,const void*q) {
	struct word*a=(struct word*)p;
	struct word*b=(struct word*)q;
	return strcmp(a->str,b->str);
}
int fps[100];
int main() {
	char ch;
	FILE *fp;
	int i=0,j=0,t=1,flag=1,n,m;
	fp = fopen("article.txt", "r");
	while(fscanf(fp,"%c",&ch)!=EOF) {
		if(isalpha(ch)) {
			flag=0;
			ch=tolower(ch);
			words[i].str[j]=ch;
			j++;
		} else {
			if(flag!=1) {
				words[i].cnt=1;
				i++;
			}
			flag=1;
			j=0;
		}
	}
	qsort(words,i,sizeof(words[0]),cmp);
	for(n=0; n<i; n++) {
		for(m=n+1; m<i; m++) {
			if(strcmp(words[n].str, words[m].str)==0&&fps[n]==0) {
				words[n].cnt++;
				fps[m]++;
			}
		}
	}
	for (n=0; n<i; n++) {
		if(fps[n]==0) {
			printf("%s %d\n",words[n].str,words[n].cnt);
		}
	}
	fclose(fp);
	return 0;
}

