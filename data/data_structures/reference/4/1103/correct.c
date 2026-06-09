#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[50000],t[200],g;
struct word{
	char word[200];
	int num;
}w[300];
int letter(char s){
	if('a'<=s&&s<='z') return 1;
	if('A'<=s&&s<='Z') return 1;
	else return 0;
}
int cmp(const struct word *a,const struct word *b)
{
    if(strcmp(a->word,b->word)>0) return 1;
    else if(strcmp(a->word,b->word)<0) return -1;
}
int main () {
	FILE *in;
	int i,j=0,n=0,flag,k;
	in=fopen("article.txt","r");
	for(i=0;i<300;i++){
		w[i].num=0;
	}
	i=0;
	while((g=fgetc(in))!=EOF){
		s[i++]=g;
	}
	for(i=0;i<strlen(s);i++){
		if(letter(s[i])==1){
			j=0;flag=0;
			memset(t,'\0',sizeof(t));
			while(letter(s[i])==1){
				t[j++]=tolower(s[i]);
				i++;
			}
			if(n==0){
					strcpy(w[n].word,t);
					w[0].num=0;
					n++;
				}
			for(k=0;k<n;k++){
				if(strcmp(w[k].word,t)==0){
					w[k].num++;
					flag=1;
					break;
				}
			}
			if(flag==1) continue;
			else if(flag==0) {
				strcpy(w[n].word,t);
				w[n].num=1;
				n++;
			}
		}
	}
	qsort(w,n,sizeof(w[0]),cmp);
	for(i=0;i<n;i++){
		printf("%s",w[i].word);
		printf(" %d\n",w[i].num);
	}
	
	return 0;
}

