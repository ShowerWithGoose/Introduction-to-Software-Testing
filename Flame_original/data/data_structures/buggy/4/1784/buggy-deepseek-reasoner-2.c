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
    in = fopen("article.txt","r"); // @@ Missing file open error check; if fopen fails, in is NULL leading to crash.
    struct WordList list[300];
    char c;
    int num = 0,i = 0;
    while ((c = fgetc(in)) != EOF){ // @@ fgetc returns int; storing in char may lose EOF detection if char is unsigned.
        c = tolower(c);
        if (c >= 'a' && c <= 'z'){
            list[i].word[num++] = c; // @@ No null terminator appended; word string not terminated. Also no bounds check for word length.
        }
        else{
            num = 0;
            i++; // @@ i is incremented on every non-alpha, creating empty word entries for consecutive separators. Also after loop, i is one less than actual word count because last word has no trailing non-alpha.
        }
    }
    // Missing: null-terminate the last word (list[i].word[num] = '\0') and adjust i (i++ if last char was letter).
    qsort(list,i,sizeof(list[0]),cmp); // @@ i is incorrect word count; includes empty words and misses last word if no trailing non-alpha.
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){ // @@ Inverted logic: empty words should have num=0, non-empty should have num=1.
            list[j].num = 1;
        }
        else{
            list[j].num = 0;
        }
    }
    for (int j = 1;j < i;j++){
        if (list[j].num){ // @@ This condition only triggers for empty words (which were set to 1), opposite of intended.
            if (!strcmp(list[j-1].word,list[j].word)){
                list[j].num += list[j-1].num; // @@ Combining counts, but num values are wrong; also list[j-1].num may be 0.
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