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
            strcpy(list[ALL++].word, w[i]);
            list[ALL++].num = 1;
            ALL++; // @@ This line incorrectly increments ALL twice: once in strcpy's index and once here, causing skipped indices and uninitialized entries.
        }
    }
    qsort(list, ALL, sizeof(Word), cmp); // @@ Sorting the entire list up to ALL, but valid entries are only at even indices due to double increment, leading to garbage in output.
    for(i = 1; i <= ALL; i++){ // @@ Loop starts at 1 and goes to ALL inclusive, but valid data may not be contiguous or correctly indexed due to earlier double increment.
        printf("%s %d\n", list[i].word, list[i].num);
    }
    
    return 0;

}