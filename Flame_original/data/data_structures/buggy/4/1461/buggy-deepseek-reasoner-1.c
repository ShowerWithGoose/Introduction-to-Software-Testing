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
    for(i = 1; i <= a; i++){ // @@ Loop should start from 0 to include the first element (list[0]) because list is filled starting at index 0.
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
    } // @@ Missing finalization: if the last character of the file is a letter, the word is not stored because the loop ends without processing it.
    for(i = 1; i <= all; i++){
        pos = find(w[i], ALL);
        if(pos >= 0){
            list[pos].num++;
        }else{
            strcpy(list[ALL++].word, w[i]); // @@ Using ALL++ here increments ALL prematurely; combined with next line and ALL++ leads to triple increment per word.
            list[ALL++].num = 1; // @@ Another increment, causing ALL to increase twice before the explicit ALL++ below.
            ALL++; // @@ Third increment per new word, making ALL count incorrect.
        }
    }
    qsort(list, ALL, sizeof(Word), cmp);
    for(i = 1; i <= ALL; i++){ // @@ Loop starts from 1, but list[0] is used for the first word and is never printed.
        printf("%s %d\n", list[i].word, list[i].num);
    }
    
    fclose(in);
    return 0;

}