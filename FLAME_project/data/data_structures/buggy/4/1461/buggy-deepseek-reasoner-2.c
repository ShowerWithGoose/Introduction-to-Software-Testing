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
    for(i = 1; i <= a; i++){ // @@ The loop should start from i=0 because list indices begin at 0. Starting from 1 misses list[0], causing words stored there never to be found and leading to duplicate entries.
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
            strcpy(list[ALL++].word, w[i]); // @@ This line increments ALL via post‑increment but does not correctly store the new word. It uses the current ALL value (say 0) to access list[0], then increments ALL to 1. Combined with the next lines, ALL increases by 3 instead of 1. Correct: strcpy(list[ALL].word, w[i]); then separate ALL++.
            list[ALL++].num = 1; // @@ This line again increments ALL, now storing into list[1] (after the previous increment). Additionally, it sets num for the wrong index. Should be: list[ALL].num = 1; with ALL incremented only once after both assignments.
            ALL++; // @@ This third increment makes ALL increase by 3 per new word, causing overall count to be triple the actual number of words. This line should be removed.
        }
    }
    qsort(list, ALL, sizeof(Word), cmp);
    for(i = 1; i <= ALL; i++){ // @@ The loop should start from i=0 (the first valid element) and go while i < ALL. Starting from 1 skips list[0] and accesses list[ALL] which is out of bounds, leading to output of uninitialized data.
        printf("%s %d\n", list[i].word, list[i].num);
    }
    
    return 0;
    
}