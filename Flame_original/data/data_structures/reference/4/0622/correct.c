#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vocabularies{
	char words[10];
	int times;
}vocabulary;

int cmp_words(const void*a,const void*b){
	vocabulary *m=(vocabulary *)a;
	vocabulary *n=(vocabulary *)b;
	return strcmp(m->words,n->words);
}

int main() {
	FILE *fp=NULL;
	fp=fopen("article.txt","r");
	char str[200],word[10];
	int i,t;
	vocabulary list[1000];
	while(fgets(str,200,fp)){
		for(i=0;str[i]!='\0';i++){
			if(str[i]>='A'&&str[i]<='Z')
				str[i]=str[i]+32;
		}
		for(i=0;str[i]!='\n';i++){
			if(str[i]>='a'&&str[i]<='z'){
				for(t=0;str[i]>='a'&&str[i]<='z';i++,t++){
					word[t]=str[i];
				}
				for(t=0;t<1000;t++){
					if(list[t].words[0]=='\0'){
						strcpy(list[t].words,word); 
						list[t].times=1;
						break;
					}
					else if(strstr(list[t].words,word)){
						list[t].times++;
						break;
					}
				}
				memset(word,0,sizeof(word));
				i--;
			}
		}
	}
	for(t=0;list[t].words[0]!='\0';t++);
	qsort(list,t,sizeof(list[0]),cmp_words);
	for(t=0;list[t].words[0]!='\0';t++)
		printf("%s %d\n\n",list[t].words,list[t].times);
	fclose(fp);
	return 0;
}


