#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct cnm {
	char string[666];
	int count;
};
struct cnm word[6666];
char s[66666];
int p=0;
int cmp(const void*a,const void*b) {
	struct cnm *c=(struct cnm*)a;
	struct cnm *d=(struct cnm*)b;
	return strcmp(c->string, d->string);
}
int main() {
	FILE* fp=fopen("article.txt","r");
	int i,j=0;
	char c;
	while((c=fgetc(fp))!=EOF) {
		s[p]=c;
		p++;
	}

	int number=0,flag=1;
	for(i=0; i<p; i++) {
		if(isalpha(s[i])) {
			word[number].string[j]=tolower(s[i]);
			j++;
		word[number].count=1;
			flag=1;/*	*/
		}
		 if(!isalpha(s[i])&&flag==1) {
			flag=0;/**/
			number++;
			j=0;
		}
	}
	qsort(word,number,sizeof(word[0]),cmp);
	/*for(i=0;i<number;i++)
	printf("%s\n",word[i].string);*/
	for(i=0; i<(number-1); i++) {
		if(strcmp(word[i].string,word[i+1].string)==0) {
			word[i+1].count+=word[i].count;
			word[i].count=0;
		}
	}
	for(i=0; i<number; i++)
		if(word[i].count!=0)
			printf("%s %d\n",word[i].string,word[i].count);
	return 0;
}



