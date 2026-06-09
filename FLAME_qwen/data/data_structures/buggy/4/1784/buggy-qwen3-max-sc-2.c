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
    if (in == NULL) { // @@ [The program does not check if the file was successfully opened, which may lead to undefined behavior when reading from a NULL pointer.]
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
            if (num > 0) { // @@ [When encountering a non-letter, the current word should be null-terminated and only then increment i. The current code increments i even for consecutive non-letters, creating empty entries. Also, the word is not null-terminated.]
                list[i].word[num] = '\0';
                num = 0;
                i++;
            }
        }
    }
    if (num > 0) { // @@ [After the loop ends, if there's a word being built (i.e., file doesn't end with non-letter), it won't be null-terminated or counted.]
        list[i].word[num] = '\0';
        i++;
    }
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (strlen(list[j].word)){ // @@ [The condition is inverted: it sets num=1 for non-empty words, but the logic below assumes num=1 means valid word. However, the initialization is flawed because empty words may exist and should be skipped, not assigned 0 or 1 arbitrarily. Also, multiple empty strings may be present due to consecutive delimiters.]
            list[j].num = 1;
        }
        else{
            list[j].num = 0;
        }
    }
    for (int j = 1;j < i;j++){ // @@ [The merging logic is incorrect: it only checks forward from j=1 and merges backward, but doesn't handle runs of more than two identical words correctly. Also, it skips comparing the first element properly. Moreover, it only merges if list[j].num is non-zero, but initially all valid words have num=1, so this might work partially, but the direction and boundary are flawed.]
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