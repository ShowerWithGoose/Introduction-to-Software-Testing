#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct dic{
    char c[BUFSIZ];
    int num;
};
struct dic result[BUFSIZ];
char now[BUFSIZ];
char a;
int N;
int flag;
int i,j,k,o;
FILE *art,*out;

int cmp(const void *a, const void *b);

int main(){
    art = fopen("article.txt","r");
    while((a = fgetc(art)) != EOF){
        if ((a>=65&&a<=90)||(a>=97&&a<=122)){
            now[i++] = a;
        }
        else if (strlen(now)!=0){
            for (int o = 0; o < strlen(now); o++)now[o] = tolower(now[o]);
            
            for (k = 0; k < j; k++) {
                if (strcmp(now,result[k].c)==0){
                    result[k].num++;
                    break;
                }
            }
            if (k==j) {
                result[j].num++;
                strcpy(result[j++].c,now);
            }
            i = 0;
            memset(now,'\0',BUFSIZ);
        }
    }

    qsort(result, j+1, sizeof(struct dic),cmp);
    //printf("begin \n\n");
    for (i=1; i<=j; i++){
        printf("%s %d\n",result[i].c,result[i].num);
    }
    //printf("\n end \n");
}

int cmp(const void* a, const void* b){
   return strcmp((*(struct dic*)a).c, (*(struct dic*)b).c);
} 


