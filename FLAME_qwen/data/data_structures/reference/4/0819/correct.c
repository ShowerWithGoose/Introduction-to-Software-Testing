#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dic{
	char word[20];
	int t;
};
int main(){
	struct dic dics[300];
	FILE *in;
	int i, j, k = 0, p, t = 0, cnt = 0, ctl = 0, f;
	for(i = 1; i < 20; i++) dics[0].word[i] = '\0';
	dics[0].t = 1;
	char line[1024], words[20];
	in = fopen("article.txt","r");
	while(fgets(line , 1024 , in) != NULL){
		for(i = 0; line[i] != '\0'; i++){
			if((line[i]>='A'&& line[i]<='Z')||(line[i] >='a' && line[i] <='z')){
				memset(words , 0 , sizeof(words));
				for(j = i; (line[j]>='A'&& line[j]<='Z')||(line[j] >='a' && line[j] <='z'); j++){
					words[k++] = (line[j]>='a')?line[j]:line[j]+('a'-'A');
				}
				words[k] = '\0';
				i = j;k = 0;
				for(p = 0; p <= cnt; p++){
					if(strcmp(dics[p].word,words)==0){
						dics[p].t++;
						ctl = 1;
					}
				}
				if(ctl == 0){
						cnt++;
						strcpy(dics[t++].word,words);
						dics[t].t = 1;
					}
				ctl = 0;
			}
		}
	}
	for(i = 0; i < cnt; i++){
        for(j = cnt - 1 ; j > i; j--){
        	if(strcmp(dics[j - 1].word,dics[j].word)>0){
                strcpy(words,dics[j - 1].word);
                strcpy(dics[j - 1].word,dics[j].word);
                strcpy(dics[j].word,words);
                f = dics[j].t;
                dics[j].t = dics[j - 1].t;
                dics[j - 1].t = f;
            }
        }
    }
    for(i = 0; i < cnt; i++){
		printf("%s %d\n",dics[i].word,dics[i].t);
	}
return 0;
}

