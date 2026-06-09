#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
struct letter{
	char word[200];
	int number;
};
char s[10000];
int cmp(const void *e1,const void *e2);
int main(){
	FILE *pf1=fopen("article.txt","r");
	if(pf1==NULL){
		printf("%s",strerror(errno));
		return 0;
	}
//	freopen("article.txt","r",stdin);
	int i=0,j=0,k=0;
	struct letter L[1000];
	char c;
	while((c=fgetc(pf1))!=EOF){
		s[i++]=c;
	}
	i=0;
	for(i=0;i<strlen(s);i++){
		if(!isalpha(s[i])){
			j++;
			k=0;
		}else{
			L[j].word[k++]=tolower(s[i]);
		}
	}
	qsort(L,j,sizeof(L[0]),cmp);
	for(i=0;i<j;i++){
		if(strlen(L[i].word)){
			L[i].number=1;
		}
	}
	for(i=0;i<j;i++){
		if(!strcmp(L[i].word,L[i+1].word)){
			L[i+1].number+=L[i].number;
			L[i].number=0;
		}
	}
	for(i=0;i<j;i++){
		if(L[i].number){
			printf("%s %d\n",L[i].word,L[i].number);
		}
	}
	return 0;
}
int cmp(const void *e1,const void *e2){
	return strcmp(((struct letter*)e1)->word,((struct letter*)e2)->word);
}

