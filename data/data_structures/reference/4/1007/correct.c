#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct w{
	char word[50];
	int num;
}list[1000];
int compare(const void* a,const void* b){
	struct w* c=(struct w*)a;
	struct w* d=(struct w*)b;
	return strcmp(c->word,d->word); 
}
int main()
{
	FILE *fp=fopen("article.txt","r");
	char word,map[1000];
	int i=0,count=0,k=0;
	while((word=fgetc(fp))!=EOF){
		map[i++]=word;
	}
	for(i=0;i<strlen(map);i++){
		if(!isalpha(map[i])){
			count++;
			k=0;
		}else if(isalpha(map[i]))
		list[count].word[k++]=tolower(map[i]);
	}
	qsort(list,count,sizeof(list[0]),compare);
	for(i=0;i<count;i++){
		if(strlen(list[i].word)!=0)
		list[i].num=1;
	}
	for(i=0;i<count;i++){
		if(strcmp(list[i].word,list[i+1].word)==0){
			list[i+1].num+=list[i].num;
			list[i].num=0;
		}
	}
	for(i=0;i<count;i++){
		if(list[i].num!=0)
		printf("%s %d\n",list[i].word,list[i].num);
	}
 	return 0;
}


