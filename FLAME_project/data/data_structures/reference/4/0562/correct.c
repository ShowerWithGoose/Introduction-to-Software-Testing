#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct words {
	char word[1000];
	int time;
	int app;
};
typedef struct words wordle;
int cmp(const void*a,const void*b) {
	struct words* aa=(struct words*)a;
	struct words* bb=(struct words*)b;
	return (strcmp(aa->word,bb->word));
}
int main() {
	wordle w[1000];
	memset(w,0,sizeof(w));
	FILE *fo;
	char ch;
	fo=fopen("article.txt","r");
	int end[1000]= {0};
	int i=0,u=0;
	while((ch=fgetc(fo))!=EOF) {
		if(islower(ch)) {
			if(end[i]==1) {
				i++;
				u=0;
			}
			w[i].word[u++]=ch;
		} else if(isupper(ch)) {
			if(end[i]==1) {
				i++;
				u=0;
			}
			w[i].word[u++]=tolower(ch);
		} else
			end[i]=1;
	}
	//for(int j=0; j<=i; j++)
	//	printf("%s ",w[j].word);
	for(int j=0; j<=i; j++) {
		for(int m=0; m<=i; m++) {
			if(strcmp(w[j].word,w[m].word)==0) {
				w[j].time++;
			}
		}
	}
	qsort(w,i,sizeof(w[0]),cmp);
	for(int j=0; j<=i; j++) {
		if(strcmp(w[j].word,"\0")!=0) {
			for(int q=0; q<j; q++) {
				if(strcmp(w[j].word,w[q].word)==0)
					w[j].app=1;
			}
			if(w[j].app==0)
				printf("%s %d\n",w[j].word,w[j].time);
		}
	}
	return 0;
}

