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
            list[i].word[num] = '\0'; // @@ [Missing null-termination of the current word when a non-letter is encountered, leading to undefined behavior during string operations like strlen and strcmp]
            num = 0;
            i++;
        }
    }
    list[i].word[num] = '\0'; // @@ [Missing null-termination for the last word if the file doesn't end with a non-letter character]
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){
            list[j].num = 1;
        }
        else{
            list[j].num = 0; // @@ [Logic error: words with non-zero length should be initialized to 1, but here they are set to 0; also, empty strings are set to 1 which is incorrect]
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