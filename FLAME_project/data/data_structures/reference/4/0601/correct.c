#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char temp[10000];
char cmp[10000];

struct Word{

    char A[10000];
    int count;
}word[10000];

int compare(const void *_a,const void *_b){
    struct Word *a = (struct Word*)_a;
    struct Word *b = (struct Word*)_b;
    return(strcmp(a->A,b->A));
}

int main(){

    FILE *fp1;
    int tab = 0,c = 0,count = 0,flag = 0,m;//不是字母
    fp1 = fopen("article.txt","r");
    while(fgets(temp,1000,fp1) != NULL){
        for(int i = 0;i < strlen(temp);i ++){
            if(tab == 0){
                if(isalpha(temp[i])){
                    tab = 1;//是字母
                    cmp[c ++] = tolower(temp[i]);
                }
            }else if(tab == 1){
                if(isalpha(temp[i])){
                    cmp[c ++] = tolower(temp[i]);
                }else{
                    c = 0;
                    tab = 0;
                    for(int j = 0;j < count;j ++){
                        if(strcmp(word[j].A,cmp) == 0){
                            flag = 1;
                            m = j;
                            break;
                        }
                    }
                    if(flag == 0){
                        strcpy(word[count].A,cmp);
                        word[count ++].count = 1;
                    }else{
                        word[m].count ++;
                    }
                    flag = 0;
                    memset(cmp,0,sizeof(cmp));
                }
            }
        }
    }
    qsort(word,count,sizeof(word[0]),compare);
    for(int i = 0;i < count;i ++){
        printf("%s %d\n",word[i].A,word[i].count);
    }
}
