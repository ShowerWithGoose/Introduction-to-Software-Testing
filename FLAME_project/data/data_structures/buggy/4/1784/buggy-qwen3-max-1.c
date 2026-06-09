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
            if (num > 0) { // @@ [Words are only finalized when a non-letter is encountered, but the current code increments i even for consecutive non-letters, creating empty entries. Also, the null terminator is missing.]
                list[i].word[num] = '\0'; // @@ [Missing null terminator for the word string, leading to undefined behavior during string operations.]
                i++;
            }
            num = 0; // @@ [Resetting num after incrementing i causes the next word to start at index 0, but without proper handling of empty tokens, many empty strings are added to the list.]
        }
    }
    if (num > 0) { // @@ [If the file ends with a letter, the last word is never null-terminated or added to the list.]
        list[i].word[num] = '\0';
        i++;
    }
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){
            list[j].num = 1; // @@ [Empty strings (from consecutive delimiters) are assigned count 1, which is wrong. They should be ignored entirely.]
        }
        else{
            list[j].num = 0; // @@ [Valid words are initialized to 0, but later logic tries to accumulate counts incorrectly.]
        }
    }
    for (int j = 1;j < i;j++){
        if (list[j].num){ // @@ [This condition skips words with num=0, but valid words were set to 0 above, so they are never counted.]
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