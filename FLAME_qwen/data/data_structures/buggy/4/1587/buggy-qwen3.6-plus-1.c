#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct words
{
    char str[50];
    int cnt;
}word;

int cmp(const void*a,const void*b){
    word*a1=(word*)a;
    word*b1=(word*)b;
    return strcmp(a1->str,b1->str);
}
int main(){
word*list=NULL;
 FILE*fp=fopen("article.txt","r");
 char ch; // @@ Error: fgetc returns int, and EOF is typically -1. Using char may cause EOF to be misinterpreted as a valid character, leading to incorrect loop termination or infinite loops. Should be int ch;
 int i=0;
 int j=0;
 while((ch=fgetc(fp))!=EOF){
    if(isalpha(ch)){
       list=(word*)realloc(list,sizeof(word)*(i+1));
       if(isupper(ch)){
        list[i].str[j]=ch+32;
       }
       else{
        list[i].str[j]=ch;
        }
       list[i].cnt=0;
       j++;
    while(isalpha(ch=fgetc(fp))){ // @@ Error: ch should be declared as int to correctly handle EOF. Assigning fgetc result to char can cause EOF to be cast to a valid character value, breaking the word parsing logic.
        if(isupper(ch)){
        list[i].str[j]=ch+32;
       }
       else{
        list[i].str[j]=ch;
       }
       j++;
      }
    list[i].str[j]='\0';
    list[i].cnt++;
    i++;
    j=0;
    }
 }

qsort(list,i,sizeof(word),cmp);
int k=0;
while (k<i)
{
    if(strcmp(list[k].str,list[k+1].str)==1&&k+1<i){ // @@ Error: strcmp returns 0 for equal strings, not 1. Also, k+1<i must be evaluated first to prevent out-of-bounds array access when k is the last index.
        list[k+1].cnt+=list[k].cnt;
        k++;
        while (strcmp(list[k].str,list[k+1].str)==1&&k+1<i) // @@ Error: strcmp should be compared to 0 for equality. The boundary check k+1<i must come first to avoid undefined behavior from accessing list[k+1] out of bounds.
        {
            list[k+1].cnt+=list[k].cnt;
            k++;
        }
        printf("%s %d\n",list[k].str,list[k].cnt);
        k++;
    }
    else{
       printf("%s %d\n",list[k].str,list[k].cnt);
       k++;
    }
}
fclose(fp);
free(list);
    return 0;
}

/*#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct words {
    char str[50];
    int cnt;
} word;

int cmp(const void* a, const void* b) {
    word* a1 = (word*)a;
    word* b1 = (word*)b;
    return strcmp(a1->str, b1->str);
}

int main() {
    word* list = NULL;
    FILE* fp = fopen("article.txt", "r");
    char ch;
    int i = 0;
    int j = 0;
    int word_length = 0; // 用于记录单词的长度

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            word_length = 0;
            list = (word*)realloc(list, sizeof(word) * (i + 1));
            list[i].str[word_length++] = ch;
            while (isalpha(ch = fgetc(fp))) {
                list[i].str[word_length++] = ch;
            }
            list[i].str[word_length] = '\0';
            list[i].cnt = 1;
            i++;
        }
    }

    qsort(list, i, sizeof(word), cmp);

    int k = 0;
    while (k < i) {
        if (strcmp(list[k].str, list[k + 1].str) == 0 && k + 1 < i) {
            list[k].cnt += list[k + 1].cnt;
            for (int m = k + 2; m <= i; m++) {
                if (strcmp(list[k].str, list[m].str) == 0) {
                    list[k].cnt += list[m].cnt;
                } else {
                    break;
                }
            }
            // 合并后的单词只输出一次
            printf("%s %d\n", list[k].str, list[k].cnt);
            k += 2; // 跳过已经合并的单词
        } else {
            printf("%s %d\n", list[k].str, list[k].cnt);
            k++;
        }
    }

    fclose(fp);
    free(list);
    return 0;
}*/