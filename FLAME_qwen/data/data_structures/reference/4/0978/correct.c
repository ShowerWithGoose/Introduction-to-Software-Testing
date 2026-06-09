#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	char word[35];
	int count;
};
typedef struct node Word;
int SUM=0;//单词表中的总单词数 ,总数为SUM，数组下表为SUM 
Word List[1000];//词频统计 
FILE *in;
int getword(FILE *IN,char *w);
int searchword(char a[]) ;
int comp(const void* a,const void* b);
int main (){
	in=fopen("article.txt","r");
	int i;
	char WORD[35]; //每次出现的单词 
	while(getword(in,WORD)!=EOF){
		if(searchword(WORD)== -1){
			List[SUM].count=1;
			strcpy(List[SUM].word,WORD); 
			SUM++;
		}	
	}	 
	qsort(List,SUM,sizeof(List[0]),comp);
	for (i=0;i<SUM;i++){
		printf("%s %d\n",List[i].word,List[i].count);
	}
	return 0; 
}
int getword(FILE *in,char *w){
	int c;
	while(!isalpha(c=fgetc(in)))//如果不是字母，继续扫描 
	    if(c==EOF)return c;
	do{
		*w++=tolower(c);//转换成小写 
	}while(isalpha(c=fgetc(in)));
	*w='\0'; 
	return 1;
}
int searchword(char WORD[]){
	int i;
	if(List[0].word==NULL)return -1;
	for(i=0;i<SUM;i++){
		if(strcmp(List[i].word,WORD)==0){
			List[i].count++;
			return 1;
		}
	}
	return -1;
}
int comp(const void* a,const void* b){
   return  strcmp( (*(Word *)a).word , (*(Word *)b).word );
}

