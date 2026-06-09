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
            if (num > 0) { // @@ [When a non-letter is encountered, only finalize the current word if at least one letter was read. The original code resets num and increments i even for consecutive non-letters, creating empty words.]
                list[i].word[num] = '\0'; // @@ [Missing null-terminator for the current word before moving to next entry. Without this, strcmp may read garbage.]
                i++;
            }
            num = 0; // @@ [This line should stay, but only after handling the completed word above.]
        }
    }
    if (num > 0) { // @@ [After EOF, if there's a pending word (file doesn't end with non-letter), it must be finalized. Original code misses this.]
        list[i].word[num] = '\0';
        i++;
    }
    qsort(list,i,sizeof(list[0]),cmp);
    for (int j = 0;j < i;j++){
        if (!strlen(list[j].word)){
            list[j].num = 1; // @@ [Empty strings should not be counted as words. This incorrectly assigns count 1 to empty entries created by consecutive delimiters.]
        }
        else{
            list[j].num = 0; // @@ [Valid words are initialized to 0, but they should start at 1 since each entry represents one occurrence.]
        }
    }
    for (int j = 1;j < i;j++){
        if (list[j].num){ // @@ [Because valid words were set to 0 and empty ones to 1, this condition skips all real words and processes only empty strings.]
            if (!strcmp(list[j-1].word,list[j].word)){
                list[j].num += list[j-1].num;
                list[j-1].num = 0;
            }
        }
    }

    for (int j = 0;j < i;j++){
        if (list[j].num){ // @@ [Only empty strings have num=1; real words have num=0 or aggregated counts that never get set correctly due to prior logic errors.]
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