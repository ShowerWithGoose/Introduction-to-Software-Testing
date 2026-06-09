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
	wordle words[1000];
	memset(words,0,sizeof(words));
	FILE *fo;
	char ch;
	fo=fopen("article.txt","r");
	int end[1000]= {0};
	int num=0,i=0;
	while((ch=fgetc(fo))!=EOF) {
		if(islower(ch)) {
			if(end[num]==1) {
				num++;
				i=0;
			}
			words[num].word[i++]=ch;
		} else if(isupper(ch)) {
			if(end[num]==1) {
				num++;
				i=0;
			}
			words[num].word[i++]=tolower(ch);
		} else
			end[num]=1;
	}
	//for(int j=0; j<=i; j++)
	//	printf("%s ",w[j].word);
	for(int j=0; j<=num; j++) {
		for(int m=0; m<=num; m++) {
			if(strcmp(words[j].word,words[m].word)==0) {
				words[j].time++;
			}
		}
	}
	qsort(words,num,sizeof(words[0]),cmp);
	for(int j=0; j<=num; j++) {
		if(strcmp(words[j].word,"\0")!=0) {
			for(int q=0; q<j; q++) {
				if(strcmp(words[j].word,words[q].word)==0)
					words[j].app=1;
			}
			if(words[j].app==0)
				printf("%s %d\n",words[j].word,words[j].time);
		}
	}
	return 0;
}

