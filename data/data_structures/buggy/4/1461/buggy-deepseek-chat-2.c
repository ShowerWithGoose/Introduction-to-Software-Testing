#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct alphabeta{
    
    char word[50];
    int num;
    
} Word;
Word list[1005];

char w[1005][50]; 

int cmp(const void *p1, const void *p2){
    
    Word *d1 =  (Word *)p1;
    Word *d2 =  (Word *)p2;
    
    if(strcmp(d1->word, d2->word) > 0)  return 1;
    else if(strcmp(d1->word, d2->word) < 0)  return -1;
    else return 0;

}
int find(char str[], int a){
    
    int i;
    for(i = 1; i <= a; i++){
        if(strcmp(list[i].word, str) == 0)  return i;
    }
    
    return -1;
}

int main(){

    FILE *in;
    in = fopen("article.txt","r");
    int all = 0, i = 0, pos = 0, c, flag = 0, ALL = 0;
    
    while((c = fgetc(in)) != EOF){
        if(c >= 'a' && c <= 'z'){
            w[all + 1][i] = c;
            i++;
            flag = 1;
        }else if(c >= 'A' && c <= 'Z'){
            w[all + 1][i] = c - 'A' + 'a';
            i++;
            flag = 1;
        }else{
            if(flag == 1){
                w[all + 1][i] = '\0';
                all++;
                i = 0;
            }
            flag = 0;
        }
    }
    for(i = 1; i <= all; i++){
        pos = find(w[i], ALL);
        if(pos >= 0){
            list[pos].num++;
        }else{
            strcpy(list[ALL++].word, w[i]); // @@ [Error: ALL is incremented twice in this block, causing incorrect indexing and skipping entries. The line `list[ALL++].num = 1;` also increments ALL, and then `ALL++;` increments it again, leading to out-of-bounds access and missing words.]
            list[ALL++].num = 1; // @@ [Error: This line increments ALL again, causing the same issue as above. The correct approach is to use ALL only once, e.g., `strcpy(list[ALL].word, w[i]); list[ALL].num = 1; ALL++;`]
            ALL++; // @@ [Error: This third increment of ALL is redundant and causes the index to skip entries, leading to incorrect word counts and potential buffer overflow.]
        }
    }
    qsort(list, ALL, sizeof(Word), cmp);
    for(i = 1; i <= ALL; i++){ // @@ [Error: The loop starts from i=1, but array indices in C start from 0. This skips the first element (list[0]) and may access uninitialized memory if ALL is the count of elements. Should be `for(i = 0; i < ALL; i++)`.]
        printf("%s %d\n", list[i].word, list[i].num);
    }
    
    return 0;

}