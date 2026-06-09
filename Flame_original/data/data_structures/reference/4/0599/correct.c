#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list{
	char word[32];
	int cnt;
}list[1000],t;

char emp[32] = {'\0'};

int main()
{
	int i = 0,j = 0,len = 0,flag = 0;
	char voca,m[100]={0};
	FILE* fp;
	fp = fopen("article.txt","r");
	while((voca = fgetc(fp)) != EOF){
		if(voca >= 'A'&&voca <= 'Z'){
			m[i] = voca + 'a' - 'A';
			i++;
		}
		else if(voca >= 'a'&&voca <= 'z'){
			m[i] = voca;
			i++;
		}
		else{
			i = 0;
			if(strcmp(m,emp) != 0){
				for(j = 1;j <= len;j++){
					if(strcmp(m,list[j].word) == 0){
						list[j].cnt++;
						flag = 1;
						break;
					}
					else{
						flag = 0;
					}
				}
				if(flag == 0){
					len++;
					strcpy(list[len].word,m);
					list[len].cnt = 1;
				}
				for(int k = 0;k < 100;k++){
					m[k] = '\0';
				}
			}
		}
	}
	for(i = 1;i <= len;i++){
		for(j = i + 1;j <= len;j++){
			if(strcmp(list[i].word,list[j].word) > 0){
				strcpy(t.word,list[i].word);
				strcpy(list[i].word,list[j].word);
				strcpy(list[j].word,t.word);
				t.cnt = list[i].cnt;
				list[i].cnt = list[j].cnt;
				list[j].cnt = t.cnt;
			}
		}
	}
	for(i = 1;i <= len;i++){
		printf("%s",list[i].word);
		printf(" %d\n",list[i].cnt);
	}
	fclose(fp);
	return 0;
} 

