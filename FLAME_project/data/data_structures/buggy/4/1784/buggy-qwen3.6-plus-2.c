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
    while ((c = fgetc(in)) != EOF){ // @@ The variable c is declared as int in standard practice for EOF check, but here it is char. If char is signed, EOF (-1) might match a valid character (255 cast to -1). More importantly, the logic below fails to null-terminate words and handle the last word if file doesn't end with non-alpha.
        c = tolower(c);
        if (c >= 'a' && c <= 'z'){
            list[i].word[num++] = c;
        }
        else{
            if (num > 0) { // @@ Missing check: if num is 0 (consecutive delimiters), we shouldn't increment i or treat it as a word boundary for a new empty word slot unnecessarily, though the main issue is null termination.
                list[i].word[num] = '\0'; // @@ Missing null-termination of the current word before moving to the next index. Without this, strcmp and printf will read garbage memory.
                i++;
            }
            num = 0;
            // i++ should only happen if a word was actually formed. The original code increments i for every non-alpha character, creating many empty/invalid entries.
        }
    }
    // @@ After the loop, if the file ends with a letter, the last word is not processed (not null-terminated, i not incremented).
    if (num > 0) {
        list[i].word[num] = '\0';
        i++;
    }

    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){ // @@ This logic is flawed. It sets num=1 for empty strings and 0 for valid words initially. This contradicts the later accumulation logic.
            list[j].num = 1;
        }
        else{
            list[j].num = 0; // @@ Valid words are set to 0 count initially.
        }
    }
    for (int j = 1;j < i;j++){
        if (list[j].num){ // @@ Since valid words have num=0, this block is never entered for valid words. Only empty strings (num=1) might enter, but they don't match each other logically for counting real words.
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