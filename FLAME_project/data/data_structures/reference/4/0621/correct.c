#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node {
	char contain[105];
	int num;
}word[5000];

int cmp(const void* a, const void* b)
{
    struct node* c = (struct node*)a; 
    struct node* d = (struct node*)b;
    return strcmp(c->contain,d->contain);         //∂‘µ•¥ ◊÷µ‰–Ú≈≈–Ú
}

int main(){
	FILE* fp=fopen("article.txt","r");
	char string[11451];char ch;
	int i=0,j=0,k=0;
	while((ch=fgetc(fp))!=EOF){
		string[i++]=ch;
	}
	for(i=0;i<strlen(string);i++){
		if(isalpha(string[i])==0){
			j=0;
			k++;
		}
		if(isalpha(string[i])) word[k].contain[j++]=tolower(string[i]);
	}
	
	qsort(word,k,sizeof(word[0]),cmp);
	
	for(i=0;i<k;i++){
		if(strlen(word[i].contain)!=0) word[i].num=1;
	}
	
	for(i=0;i<k;i++){
		if(strcmp(word[i].contain,word[i+1].contain)==0){
			word[i+1].num+=word[i].num;
			word[i].num=0;
		}
	}
	
	for(i=0;i<k;i++){
		if(word[i].num!=0){
			printf("%s %d\n",word[i].contain,word[i].num);
		}
	}
	return 0;
} 

