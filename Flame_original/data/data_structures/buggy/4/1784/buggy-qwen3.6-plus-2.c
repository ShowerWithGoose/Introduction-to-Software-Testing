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
    in = fopen("article.txt","r"); // @@ [Error: Missing NULL check for fopen return value, may cause segmentation fault if file does not exist]
    struct WordList list[300]; // @@ [Error: Array is not initialized, contains garbage values causing undefined behavior in strlen() and strcmp()]
    char c; // @@ [Error: fgetc() returns int, using char may cause incorrect EOF comparison if char is unsigned]
    int num = 0,i = 0;
    while ((c = fgetc(in)) != EOF){
        c = tolower(c);
        if (c >= 'a' && c <= 'z'){
            list[i].word[num++] = c; // @@ [Error: Missing null terminator '\0' after storing characters, leading to undefined behavior in string functions]
        }
        else{
            num = 0;
            i++;
        }
    }
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){ // @@ [Error: Logic is inverted; should check if strlen > 0 to initialize valid words, not empty ones]
            list[j].num = 1; // @@ [Error: Incorrectly assigns count 1 to empty strings instead of valid words]
        }
        else{
            list[j].num = 0; // @@ [Error: Incorrectly assigns count 0 to valid words instead of empty strings]
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