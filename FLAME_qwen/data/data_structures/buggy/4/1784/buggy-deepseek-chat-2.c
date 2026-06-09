#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 32

struct WordList{
    char word[MAX];
    int num;
};

int cmp(const void *p1,const void *p2);

int main()
{
    FILE *in;
    in = fopen("article.txt","r");
    struct WordList list[300];
    char c;
    int num = 0,i = 0;
    while ((c = fgetc(in)) != EOF){
        c = tolower(c);
        if (c >= 'a' && c <= 'z'){
            list[i].word[num++] = c;
        }
        else{
            num = 0;
            i++;
        }
    }
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){ // @@ The condition is inverted: it should check if the word length is NOT zero to set num to 1, but here it sets num=1 when length is zero (empty word), which is incorrect.
            list[j].num = 1;
        }
        else{
            list[j].num = 0;
        }
    }
    for (int j = 1;j < i;j++){
        if (list[j].num){ // @@ This condition checks if list[j].num is non-zero, but after the previous loop, only empty words have num=1, so this will incorrectly skip non-empty words that should be compared.
            if (!strcmp(list[j-1].word,list[j].word)){
                list[j].num += list[j-1].num;
                list[j-1].num = 0;
            }
        }
    }

    for (int j = 0;j < i;j++){
        if (list[j].num){
            printf("%s %d\n",list[j].word,list[j].num);
        }
    }

    fclose(in);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    struct WordList *a1 = (struct WordList*)p1;
    struct WordList *a2 = (struct WordList*)p2;
    if (strcmp(a1->word,a2->word) > 0)
        return 1;
    else if (strcmp(a1->word,a2->word) < 0)
        return -1;
    return 0;
}