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
    while ((c = fgetc(in)) != EOF){ // @@ The variable c should be declared as int, not char, to correctly handle EOF. Also, the logic for building words and handling separators is flawed.
        c = tolower(c);
        if (c >= 'a' && c <= 'z'){
            list[i].word[num++] = c; // @@ This appends characters to the current word buffer but does not null-terminate it immediately, and relies on 'i' staying constant.
        }
        else{
            num = 0; // @@ Resets the character index for the next word, but fails to null-terminate the previous word stored in list[i].word.
            i++; // @@ Increments the word index. If the previous sequence was empty (e.g., multiple spaces), this creates an empty entry. Crucially, list[i].word is not null-terminated here.
        }
    }
    qsort(list,i,sizeof(list[0]),cmp); // @@ Sorts the array. However, since words were not null-terminated properly, strcmp inside cmp may read garbage or crash. Also, empty entries are included.
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){ // @@ Checks if the word is empty. Because words weren't null-terminated during input, strlen behavior is undefined/incorrect.
            list[j].num = 1; // @@ Logic error: Empty slots are marked with count 1? This seems inverted or incorrect for initialization.
        }
        else{
            list[j].num = 0; // @@ Non-empty words initialized to 0?
        }
    }
    for (int j = 1;j < i;j++){
        if (list[j].num){ // @@ Only processes if num is non-zero. Based on previous loop, only "empty" words have num=1. This logic is completely backwards.
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