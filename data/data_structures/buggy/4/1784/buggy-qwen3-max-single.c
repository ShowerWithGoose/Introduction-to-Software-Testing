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
    if (in == NULL) { // @@ [Missing error check for fopen failure; if file doesn't exist, fgetc on NULL pointer causes undefined behavior]
        return 1;
    }
    struct WordList list[300];
    char c;
    int num = 0,i = 0;
    while ((c = fgetc(in)) != EOF){
        c = tolower(c);
        if (c >= 'a' && c <= 'z'){
            list[i].word[num++] = c;
        }
        else{
            if (num > 0) { // @@ [Words are not null-terminated; when non-letter is encountered, current word must be null-terminated and index advanced only if a word was being built]
                list[i].word[num] = '\0';
                i++;
            }
            num = 0;
        }
    }
    if (num > 0) { // @@ [Final word at end of file may not be terminated or counted if file doesn't end with non-letter]
        list[i].word[num] = '\0';
        i++;
    }
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (strlen(list[j].word)){ // @@ [Logic inverted: should initialize num=1 for valid words, but condition checks !strlen in reference; here it's opposite and also words may be uninitialized]
            list[j].num = 1;
        }
        else{
            list[j].num = 0;
        }
    }
    for (int j = 1;j < i;j++){ // @@ [Frequency counting logic is flawed: only checks forward from j=1, misses merging first duplicate; also relies on previous num values which may be wrong]
        if (list[j].num){
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