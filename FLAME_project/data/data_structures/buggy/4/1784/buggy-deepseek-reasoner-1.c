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
            num = 0; // @@ Missing null terminator for the word; previous word remains unterminated in list[i].word, causing strlen/strcmp to read beyond intended characters.
            i++; // @@ Increments i for every non-alphabetic character, creating many empty entries even when multiple separators appear consecutively. Should only increment when a word ends.
        }
    }
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){ // @@ Condition intended to detect empty strings, but due to missing null termination, strlen behavior is undefined. Additionally, empty strings should be ignored.
            list[j].num = 1; // @@ Sets initial count to 1 for empty words (wrong). Should be 0 or skip such entries.
        }
        else{
            list[j].num = 0; // @@ Sets initial count to 0 for real words (wrong). Should be 1 per occurrence to later accumulate.
        }
    }
    for (int j = 1;j < i;j++){
        if (list[j].num){ // @@ Condition relies on the previously set num values. Since empty words have num=1 and real words have num=0, this only attempts to merge empty words, which is incorrect.
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