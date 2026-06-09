#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct alphabeta{
	
	char word[50];
	int num;
	
} Word;
Word list[1005];

char w[1005][50]; 

int cmp(const void *p1, const void *p2){
	
	Word *d1 =  (Word *)p1;
	Word *d2 =  (Word *)p2;
	
	if(strcmp(d1->word, d2->word) > 0)  return 1;
	else if(strcmp(d1->word, d2->word) < 0)  return -1;
	else return 0;

}
int find(char str[], int a){
	
	int i;
	for(i = 1; i <= a; i++){
		if(strcmp(list[i].word, str) == 0)  return i;
	}
	
	return -1;
}

int main(){

	FILE *in;
	in = fopen("article.txt","r");
	int all = 0, i = 0, pos = 0, c, flag = 0, ALL = 0;
	
	while((c = fgetc(in)) != EOF){
		if(c >= 'a' && c <= 'z'){
			w[all + 1][i] = c;
			i++;
			flag = 1;
		}else if(c >= 'A' && c <= 'Z'){
			w[all + 1][i] = c - 'A' + 'a';
			i++;
			flag = 1;
		}else{
			if(flag == 1){
				w[all + 1][i] = '\0';
				all++;
				i = 0;
			}
			flag = 0;
		}
	}
	
//	for(i = 1; i <= all; i++){
//		printf("%d %s\n", i, w[i]);
//	}
	
	for(i = 1; i <= all; i++){
		pos = find(w[i], ALL);
		if(pos >= 0){
			list[pos].num++;
		}else{
			strcpy(list[ALL + 1].word, w[i]);
			list[ALL + 1].num = 1;
			ALL++;
		}
	}
	qsort(list, ALL + 1, sizeof(Word), cmp);
	for(i = 1; i <= ALL; i++){
		printf("%s %d\n", list[i].word, list[i].num);
	}
	
	return 0;

}


