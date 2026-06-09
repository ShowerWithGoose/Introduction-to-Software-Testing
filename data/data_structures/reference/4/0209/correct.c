#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct voc{
	char word[25];
	int flag;
}words[100];
int cmp(const void *p1,const void *p2){
	return strcmp(((struct voc*)p1)->word,((struct voc*)p2)->word);
}
char word_store[25];
char c_store;
int sum,sum_words;
int i,j,k;
void main(){
	//freopen("C:\\Users\\Dell\\Desktop\\article.txt.txt","r",stdin);
	freopen("article.txt","r",stdin);

	while(1){
		sum=0;
		c_store=getchar();
		if(isalpha(c_store)){
		    word_store[sum++]=tolower(c_store);
			while(isalpha(c_store=getchar()))
		    word_store[sum++]=tolower(c_store);
		    word_store[sum]='\0';
		    
			for(i=0;i<sum_words;i++){
			if(strcmp(word_store,words[i].word)==0)
			break;
		    } 
		    if(i==sum_words)
			strcpy(words[sum_words++].word,word_store);
			words[i].flag++;
		}
		if(c_store==EOF)
		break;
	}
	qsort(words,sum_words,sizeof(struct voc),cmp);
	for(i=0;i<sum_words-1;i++){
		printf("%s %d",words[i].word,words[i].flag);
		printf("\n\n");
	}
	printf("%s %d",words[i].word,words[i].flag);
}











