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
            if (num > 0) { // @@ [Words are not null-terminated; when non-letter is encountered, current word must be null-terminated before incrementing i]
                list[i].word[num] = '\0';
                num = 0;
                i++;
            } else {
                num = 0;
                // @@ [Consecutive non-letter characters cause empty entries to be counted as words because i is incremented even when no letters were read]
                i++;
            }
        }
    }
    if (num > 0) { // @@ [Last word in file may not be followed by non-letter, so it's never null-terminated or added to list]
        list[i].word[num] = '\0';
        i++;
    }
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){
            list[j].num = 1;
        }
        else{
            list[j].num = 0; // @@ [Logic inverted: words with content should be initialized to 1, empty strings to 0]
        }
    }
    for (int j = 1;j < i;j++){
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