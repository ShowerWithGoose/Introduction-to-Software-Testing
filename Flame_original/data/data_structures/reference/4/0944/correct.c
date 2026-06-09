#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct wordscount{
	char word[2000];
	int cnt;
}; 
typedef struct wordscount def;
def words[2000];
int cmp(const void *p1,const void *p2);
char article[2000];
char store[2000];
char mark;
int i,j,k;
int count=0;
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	mark=fgetc(in);
	i=0;
	while(mark!=EOF){
		article[i]=mark;
		i++;
		mark=fgetc(in);
	}
	for(i=0;i<strlen(article);i++){
		if(isalpha(article[i])){
			article[i]=tolower(article[i]);
		}
	}
	for(i=0;i<strlen(article);i++){
		if(isalpha(article[i])){
			for(j=i;j<strlen(article);j++){
				if(!isalpha(article[j])){
					break;
				}
			}
			memset(store,0,sizeof(store));
			for(k=0;k<j-i;k++){
				store[k]=article[i+k];
			}
			strcpy(words[count].word,store);
			i=j;
			count++;
		}
		else
			continue;
	}
	qsort(words,count,sizeof(def),cmp);
	for(i=0;i<count;i++){
		words[i].cnt=1;
	}
	for(i=0;i<count;i++){
		if(strcmp(words[i].word,words[i+1].word)==0){
			words[i+1].cnt+=words[i].cnt;
			words[i].cnt=0;
		}
	}
	qsort(words,count,sizeof(def),cmp);
	for(i=0;i<count;i++){
		if(words[i].cnt==0)
			continue;
		else{
			printf("%s %d\n",words[i].word,words[i].cnt);
		}
	}
	fclose(in);
	return 0;
}

int cmp(const void *p1,const void *p2)
{
	struct wordscount *a=(struct wordscount *)p1;
	struct wordscount *b=(struct wordscount *)p2;
	return strcmp(a->word,b->word);
}

