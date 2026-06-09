//
// Created by  on 2022/3/25.
//
#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int cmp(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}
char ch[200000][200],c;
int main(){
    setbuf(stdout,NULL);
    FILE *in;
    in=fopen("article.txt","r");
    int n=1;
    while((c=fgetc(in))!=EOF){
        if(!isalpha(c)) continue;
        int j=0;
        while(isalpha(c)){
            if(isupper(c)) ch[n][j++]=c+'a'-'A';
            else ch[n][j++]=c;
            c=fgetc(in);
        }
        n++;
    }
    n--;
    qsort(ch+1,n,sizeof(ch[0]),cmp);

    for(int i=1;i<=n;i++) {
        int count=1;
        while(strcmp(ch[i],ch[i+1])==0){
            count++;
            i++;
        }
        printf("%s %d\n",ch[i],count);
    }
    fclose(in);
    return 0;
}


