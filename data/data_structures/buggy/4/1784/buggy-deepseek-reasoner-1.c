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
    in = fopen("article.txt","r"); // @@ Missing NULL check for fopen. If file not found, in is NULL, but code proceeds to use it causing undefined behavior.
    struct WordList list[300];
    char c; // @@ Using char for fgetc can cause EOF to be treated as a character if char is unsigned, leading to infinite loop or missed EOF. Should be int.
    int num = 0,i = 0;
    while ((c = fgetc(in)) != EOF){
        c = tolower(c);
        if (c >= 'a' && c <= 'z'){
            list[i].word[num++] = c; // @@ No null terminator added after word ends. strlen and strcmp will operate on uninitialized memory, causing undefined behavior.
        }
        else{
            num = 0;
            i++; // @@ Incrementing i on every non‑letter character creates extra empty entries. Also, i is used as the count of words, but this counts separators, not words, so qsort operates on wrong number of elements.
        }
    }
    qsort(list,i,sizeof(list[0]),cmp); // @@ i may be incorrect (overcounts separators) and list entries may lack null terminators, making sort results unreliable.
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){ // @@ Logic inverted: empty words should get num=0, non‑empty words should get num=1. This sets num=1 for empty words, which later causes incorrect counting.
            list[j].num = 1;
        }
        else{
            list[j].num = 0;
        }
    }
    for (int j = 1;j < i;j++){
        if (list[j].num){ // @@ Because real words have num=0, this condition never triggers for them. Only empty words (num=1) are processed, leading to no frequency aggregation for actual words.
            if (!strcmp(list[j-1].word,list[j].word)){
                list[j].num += list[j-1].num;
                list[j-1].num = 0;
            }
        }
    }

    for (int j = 0;j < i;j++){
        if (list[j].num){
            printf("%s %d\n",list[j].word,list[j].num); // @@ Prints empty words (if any) due to incorrect counting logic, and fails to print actual word frequencies.
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