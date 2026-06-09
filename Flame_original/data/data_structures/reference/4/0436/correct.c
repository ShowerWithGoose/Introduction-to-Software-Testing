#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

struct node{
    char wrd[2000];
    int ct;
};
struct node p[10000];

int sortit(const void* a, const void* b){
    struct node* c = (struct node*)a;
    struct node* d = (struct node*)b;
    return strcmp(c->wrd, d->wrd);
}


int main(){

    char s[10000],c;
    int cnt=0, t=0;
    FILE* op = fopen("article.txt", "r");
    while((c = fgetc(op))!=EOF){
        s[cnt++] = c;
    }
    cnt = 0;
    for(int i=0;i<strlen(s);i++){
        if(!isalpha(s[i])){
            cnt++;
            t = 0;
        }
        else if(isalpha(s[i])){
            p[cnt].wrd[t++] = tolower(s[i]);
        }
    }

    qsort(p, cnt, sizeof(p[0]), sortit);

    for(int i=0; i<cnt;i++){
        if(strlen(p[i].wrd))
            p[i].ct = 1;
    }
    for(int i=0;i<cnt;i++){
        if(!strcmp(p[i].wrd, p[i+1].wrd)){
            p[i+1].ct += p[i].ct;
            p[i].ct = 0;
        }
    }
    for(int i=0;i<cnt;i++){
        if(p[i].ct !=0)
            printf("%s %d\n", p[i].wrd, p[i].ct);
    }

    fclose(op);
	return 0;
}


