#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define wordSize 50
typedef struct WORD{
	int number;
	char c[wordSize];
}word,*wordptr;
int count=0;//count表示已经录入了count个单词 
FILE *in; 
wordptr list[100000];
int input(char *str){
	int i=0;
	char c;
	while(1){
		c=fgetc(in);
		if(c==EOF){
			return 0;
		}
		if(isalpha(c)){
			break;
		}
	}
	do{
		c=tolower(c);
		str[i++]=c;
	}while(isalpha(c=fgetc(in)));
	str[i]='\0';
	return 1;	
}
void output(){
	for(int i=0;i<count;i++){
		printf("%s %d\n",list[i]->c,list[i]->number);
	}
	return;
}
int cmp(const void *a,const void *b){
	wordptr *x=(wordptr*)a;
	wordptr *y=(wordptr*)b;
	return strcmp((*x)->c,(*y)->c);
}
int main(){
	in=fopen("article.txt","r");
	char str[wordSize];
	while(input(str)){
		for(int i=0;i<=count;i++){
			if(i==count){
				list[count]=(wordptr)malloc(sizeof(word));
				list[count]->number=1;
				strcpy(list[count]->c,str);
				count++;
				break;
			}
			if(strcmp(str,list[i]->c)==0){
				list[i]->number++;
				break; 
			}
		}
	}
	qsort(list,count,sizeof(wordptr),cmp);
	output();
	return 0;
}


