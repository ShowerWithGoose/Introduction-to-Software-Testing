#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct a{
    char word[1028];
    //int cnt;
}W;     //WORD

W dic[90000];
W temp;

int cmp(const void *a, const void *b);

        /*  main    */
int main(){

    FILE *fp1 = fopen("article.txt", "r");

    char c;
    int i = 0, j = 0;
    //把所有都录入
    while((c = fgetc(fp1))!=EOF){
        if(!isalpha(c) && temp.word[0] != '\0'){    //不是字母 && temp内非空 就打上\0存入dic[i]中
            temp.word[j] = '\0';
            dic[i++] = temp;
            temp.word[0] = '\0';
            j = 0;
            continue;
        }else if(!isalpha(c) && temp.word[0] == '\0')
            continue;
        
        c = tolower(c);
        temp.word[j++] = c;
    }
    if(isalpha(temp.word[0]))
        dic[i++] = temp;
    
    //qsort排序，重复的会在排在一起，之后逐一跳过
    int n = i;
    qsort(dic, n, sizeof(dic[0]), cmp);

    W temp2;
    int cnt2 = 0;
    for(int k = 0; k < n; ++k){
        if(cnt2 == 0){
            temp2 = dic[k];
            cnt2 = 1;
            continue;
        }
        if(strcmp(temp2.word, dic[k].word) == 0){    //strcmp相等返回0，相等的时候cnt2++
            cnt2++;
        }
        else if(strcmp(temp2.word, dic[k].word)){
            //printf(" %d\n", strcmp(temp.word, dic[k].word));
            printf("%s %d\n", temp2.word, cnt2);
            temp2 = dic[k];
            cnt2 = 1;
        }
    }

    printf("%s %d", temp2.word, cnt2);





    return 0;
}

int cmp(const void *a, const void *b){
    W *c = (W*)a;
    W *d = (W*)b;
    return strcmp(c->word, d->word);
}
