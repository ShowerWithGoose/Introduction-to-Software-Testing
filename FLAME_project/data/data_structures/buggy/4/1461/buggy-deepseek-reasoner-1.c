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
    for(i = 1; i <= a; i++){ // @@ Loop starts at 1, but list is 0‑indexed; should start at 0 to include list[0].
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
        pos = find(w[i], ALL); // @@ Uses ALL (inflated count) and find returns 1‑based index; list[0] is never found.
        if(pos >= 0){
            list[pos].num++; // @@ pos is 1‑based, so list[0] is skipped; list[1], list[2], ... are used inconsistently.
        }else{
            strcpy(list[ALL++].word, w[i]); // @@ Triple increment: ALL is increased three times per new word instead of once.
            list[ALL++].num = 1; // @@ Second increment; writes num at wrong index.
            ALL++; // @@ Third increment; further misaligns indices.
        }
    }
    qsort(list, ALL, sizeof(Word), cmp); // @@ ALL is three times the actual number of unique words; sorts garbage and wrong range.
    for(i = 1; i <= ALL; i++){ // @@ Starts from 1, skipping list[0]; ALL is inflated, so many empty entries are printed.
        printf("%s %d\n", list[i].word, list[i].num); // @@ Prints with wrong starting index and count.
    }
    
    return 0;

}