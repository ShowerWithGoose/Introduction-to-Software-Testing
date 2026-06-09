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
 char ch;
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
       list[i].cnt=0; // @@ The count is initialized to 0 here, but it should be initialized to 1 later or incremented correctly. However, the main logic error is in the comparison and accumulation loop.
       j++;
    while(isalpha(ch=fgetc(fp))){
        if(isupper(ch)){
        list[i].str[j]=ch+32;
       }
       else{
        list[i].str[j]=ch;
       }
       j++;
      }
    list[i].str[j]='\0';
    list[i].cnt++; // @@ This sets cnt to 1 for each new word instance, which is correct for individual entries before merging.
    i++;
    j=0;
    }
 }

qsort(list,i,sizeof(word),cmp);
int k=0;
while (k<i)
{
    if(strcmp(list[k].str,list[k+1].str)==1&&k+1<i){ // @@ Error 1: strcmp returns 0 if strings are equal, not 1. It returns <0 or >0 if they differ. Checking for ==1 is incorrect for identifying duplicates. It should be ==0.
        list[k+1].cnt+=list[k].cnt; // @@ Error 2: Logic for accumulating counts is flawed. If we find a duplicate, we should accumulate into the current slot (or a kept slot) and skip the duplicate. Here it adds current to next, which is backwards for a forward scan where we want to keep the first occurrence or merge into one.
        k++;
        while (strcmp(list[k].str,list[k+1].str)==1&&k+1<i) // @@ Error 3: Same strcmp error as above. Should be ==0.
        {
            list[k+1].cnt+=list[k].cnt; // @@ Error 4: Accumulation logic is still problematic. It modifies the next element's count based on the current, then moves forward. This doesn't correctly consolidate all duplicates into a single entry for output.
            k++;
        }
        printf("%s %d\n",list[k].str,list[k].cnt); // @@ Error 5: Prints the last element of the duplicate chain, but the counts might be wrong due to previous logic errors.
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