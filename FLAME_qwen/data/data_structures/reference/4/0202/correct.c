#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct WORDS{
	char name[100];
	int num;
}word;

int cmp(const void*p1,const void*p2){
	word*a=(word*)p1;
	word*b=(word*)p2;
	return strcmp(a->name,b->name);
}
word line[3333];
char art[10009];
int main(){
	FILE *fp=fopen("article.txt","r");
	char ch;
	int i=0;
	while((ch=fgetc(fp))!=EOF){
		art[i++]=ch;
	}
	int len=strlen(art);
	int cnt=0,j=0;
	for(i=0;i<len;i++){
		if(isalpha(art[i])){
				line[cnt].name[j++]=tolower(art[i]);
		}
		if(!isalpha(art[i])){
		    cnt++;
		    j=0;
		}
	}
	qsort(line,cnt,sizeof(line[0]),cmp);
	for(i=0;i<cnt;i++){
		if(strlen(line[i].name)!=0) line[i].num=1;
	}
	for(i=0;i<cnt;i++){
		if(strcmp(line[i].name,line[i+1].name)==0){
			line[i+1].num+=line[i].num;
			line[i].num=0;
		}
	}

	for(i=0;i<cnt;i++){
		if(line[i].num!=0){
			printf("%s %d\n",line[i].name,line[i].num);
		}
    }
	return 0;
} 

