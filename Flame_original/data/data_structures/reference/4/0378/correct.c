#include <stdio.h>
#include <string.h>
#define MAXSIZE 10000
typedef struct{
	char word[100];
	int cnt;
}list;
list l[MAXSIZE];
int cmp(const void *p1, const void *p2){
	list *q1=(list*)p1;
	list *q2=(list*)p2;
	return strcmp(q1->word,q2->word);
}
int isalpha(char c){
	if(c>='a' && c<='z'){
		return 1;
	}else if(c>='A' && c<='Z'){
		return 1;
	}else	return 0;
}
char tolower(char c){
	if(c>='A' && c<='Z'){
		return c-'A'+'a';
	}else	return c;
}
int getWord(FILE *fp, char *w){
	int c;
	while(!isalpha(c=fgetc(fp))) 
		if(c == EOF) return c; 
		else continue;
	do {
		*w++ = tolower(c);
	} while(isalpha(c=fgetc(fp))); 
	*w='\0';
	return 1;
} 



int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char s[100],tmp[100];
	int size=0,i,fl;
	for(i=0;i<MAXSIZE;i++){
		l[i].cnt=0;
	}
	
	while(getWord(in,s)!=EOF){	
		if(!size){
			l[size].cnt++;
			strcpy(l[size++].word,s);
		}else{
			fl=0;
			for(i=0;i<size;i++){
				if(!strcmp(l[i].word,s)){
					l[i].cnt++;
					fl=1;
				}
			}
			if(!fl){
				l[size].cnt++;
				strcpy(l[size++].word,s);
			}
		}	
	}
	qsort(l,size,sizeof(list),cmp);
	for(i=0;i<size;i++){
		printf("%s %d\n",l[i].word,l[i].cnt);
	}
	
	
	fclose(in);
	return 0;
}

