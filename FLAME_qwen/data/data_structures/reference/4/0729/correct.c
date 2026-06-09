#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ll long long
struct line{
	char word[10];
	int time;
};
struct line sta[50000];
int num=0;
int cmp(const void *a, const void *b) {
	struct line *p = (struct line *)a, *q = (struct line *)b;
	if(strcmp(p->word, q->word) > 0){
		return 1;
	}else
		return -1;
}

int __strcmp(char ax[] ,char bx[]) {
	int i;
	for(i=0;ax[i] != '\0'; i++) {
		if(ax[i] != bx[i]) return -1;
	}
	return ax[i] != bx[i];
} 
int main()
{
	FILE *in,*out;
	char ch;
	in=fopen("article.txt","r");
	out=fopen("art.txt","w");
	while(fscanf(in,"%c",&ch)!=EOF){
		if(ch>='A'&&ch<='Z'){
			fputc(ch-'A'+'a',out);
		}
		else if(ch>='a'&&ch<='z'){
			fputc(ch,out);
		}
		else{
			fputc(' ',out);
		}
	}
	fclose(in);
	fclose(out);
	in=fopen("art.txt","r");
	char s[10];
	int j=0;
	while(fscanf(in,"%s",s)!=EOF){
		int flag=1,t=1;
		for(int i=0;i<j;i++){
			t=strcmp(sta[i].word,s);
			if(t==0){
				sta[i].time++;
				break;
			}
		}
		if(t!=0){
			sta[j].time=1;
			strcpy(sta[j].word,s);
			j++;
		}
	}
	qsort(sta,j,sizeof(struct line),cmp);
	for(int i=0;i<j;i++){
		printf("%s %d\n\n",sta[i].word,sta[i].time);
	}
	return 0;
}


