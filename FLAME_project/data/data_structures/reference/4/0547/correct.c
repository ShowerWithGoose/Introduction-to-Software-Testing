#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 1024
#define tolower(c) ((c>='A'&&c<='Z')?'a'+c-'A':c)

struct key{
	char name[80];
	int num;
};
struct key word[1005];
int k=0;

int iszimu(char c){
	if(((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))) return 1;
	return 0;
}

int iscunzai(char s[],int k){
	int i;
	for(i=0;i<k;i++){
		if(strcmp(word[i].name,s)==0) return i;
	}
	return -1;
}

int cmp(const void *a,const void *b){
	struct key *x=(struct key*)a;
	struct key *y=(struct key*)b;
	return strcmp(x->name,y->name);
}

int main() {
	int i,j;
	char line[MAXLINE],tmpword[80];
	FILE *fp;
	if((fp=fopen("article.txt","r"))==NULL){
		printf("Can't open file article.txt\n");
		return 1;
	}
	while(fgets(line,MAXLINE-1,fp)!=NULL){
		for(i=0;line[i]!='\0';){
			if(iszimu(line[i])==1){
				memset(tmpword,0,80);
				j=0;
				tmpword[0]=tolower(line[i]);
				i++;
				for(j=1;iszimu(line[i])==1;i++,j++){
					tmpword[j]=tolower(line[i]);
				}
				int f=iscunzai(tmpword,k);
				if(f!=-1) word[f].num++;
				else if(f==-1){
					strcpy(word[k].name,tmpword);
					word[k].num=1;
					k++;
				}
			}
			else i++;
		}
	}
	qsort(word,k,sizeof(word[0]),cmp);
	for(i=0;i<k;i++){
		printf("%s %d\n",word[i].name,word[i].num);
	}
	return 0;
}

