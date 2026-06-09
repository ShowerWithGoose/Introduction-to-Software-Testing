#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 1000

typedef struct Group{
    char word[50];
    int freq;
}group;

group ans[M];
int size = 0;

void lower(char* name){
    for(int i = 0; name[i]!='\0'; i++){
        if(name[i]>='A' && name[i]<='Z'){
            name[i] = name[i] + 'a' -'A';
        }
    }
}

int cmp(const void* a, const void* b){
    group* A = (group*) a;
    group* B = (group*) b;

    return strcmp(A->word, B->word);
}


int search(char* ch){
    int mid, left = 0,right = size-1;
    while(left<=right){
        mid = (left + right) / 2;
        if(strcmp(ch, ans[mid].word)<0){
            right = mid - 1;
        }
        else if(strcmp(ch, ans[mid].word) == 0){
            return mid;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;
}

void insert(char* elem){
    int loc = search(elem);
    if(loc == -1){
        strcpy(ans[size].word, elem);
        ans[size].freq = 1;
        size++;
    }
    else{
        ans[loc].freq ++;
    }
    qsort(ans, size, sizeof(group), cmp);
}

char read[M];
int main(){
    FILE* in = fopen("article.txt", "r");
    while(fgets(read, M, in) != NULL){
        lower(read);
        for(int i = 0; read[i]!='\0'; i++){
            char tmp[100] = {'\0'};
            int wordlen = 0; 
            if(read[i]>='a' && read[i]<='z'){
                while(read[i+wordlen]>='a' && read[i+wordlen]<='z'){
                    tmp[wordlen] = read[i+wordlen];
                    wordlen++;
                }
                insert(tmp);
                i+=wordlen;
            }
        }
    }

    for(int i = 0; i<size; i++){
        printf("%s %d\n", ans[i].word, ans[i].freq);
    }

    return 0;
}
