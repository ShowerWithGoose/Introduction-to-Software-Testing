#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct countword{
    char word[200];
    int times;
}C,*CW;

char line[300];
C s[2000];
char c;
char fword[200];

int cmp(const void *p1,const void *p2){
	struct countword *a=(struct countword*)p1;
	struct countword *b=(struct countword*)p2;
	return strcmp(a->word,b->word);
}

int main(){
    FILE *fp;
    int flag = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    if((fp = fopen("article.txt", "r")) == NULL){
		printf("Can't open file in.txt !\n");
		return 1;
	}
    while(fgets(line,300,fp) != NULL){
        for(i = 0; i <= strlen(line); i++){
            if(line[i] >= 'a' && line[i] <= 'z' ){
                if(0 == flag){
                    flag = 1;
                    fword[0] = line[i];
                    j = 1;
                }
                else if (1 == flag){
                    fword[j] = line[i];
                    j++;
                }
            }
            else if(line[i] >= 'A' && line[i] <= 'Z'){
                line[i] += 32;
                if(0 == flag){
                    flag = 1;
                    fword[0] = line[i];
                    j = 1;
                }
                else if (1 == flag){
                    fword[j] = line[i];
                    j++;
                }
            }
            else if (1 == flag){
                fword[j] = '\0';
                strcpy(s[k].word,fword);
                s[k].times = 1;
                k++;
                flag = 0;
                j = 0;
            }
        }
    }

    qsort(s,k,sizeof(C),cmp);
    for(i = 0; i < k; i++){
        if(strcmp(s[i].word,s[i+1].word) == 0){
            s[i+1].times += s[i].times;
        }
        else{
            printf("%s %d\n",s[i].word,s[i].times);
        }
    }

    return 0;
}
