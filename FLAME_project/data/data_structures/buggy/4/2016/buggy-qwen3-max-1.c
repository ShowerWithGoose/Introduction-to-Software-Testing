#include <stdio.h>
#include <string.h>
int main()
{
    FILE* in=fopen("article.txt","r");
    struct Word{
        char w[100];
        int n;
    };
    typedef struct Word word;
    char tem[100],p;
    int i,j=1,k,flag;
    word W[300];
    for(i=0;i<=299;i++){
        W[i].n=0;
        W[i].w[0]='\0';
    }
    while(1){
        k=0;
        if(fscanf(in,"%s",tem)==-1){
            break;
        }
        fgetc(in); // @@ [This consumes an extra character after each word read by fscanf, which may skip part of the next word or cause misalignment in reading. Also, fscanf with %s stops at whitespace but doesn't handle punctuation attached to words correctly per problem definition (e.g., "life." should become "life").]
        printf("%s ",tem); // @@ [The problem requires only the final word frequency output; this debug print outputs raw tokens and violates the output format.]
            for(i=0;tem[i]!='\0';i++){
                if((tem[i]>='A')&&(tem[i]<='Z')){
                    W[j].w[k]=tem[i]-'A'+'a';
                    k=k+1;
                }else if((tem[i]>='a')&&(tem[i]<='z')){
                    W[j].w[k]=tem[i];
                    k=k+1;
                }else{
                    if(W[j].w[0]!='\0'){
                    W[j].n=1;
                    j=j+1;
                    k=0;
                }
                }
            }
            if(W[j].w[0]!='\0'){
                W[j].n=1;
        j=j+1;
    }
    }
begin:    flag=0;
    for(i=1;W[i+1].n!=0;i++){ // @@ [Loop condition assumes W[i+1].n != 0 as termination, but array may have uninitialized or zeroed entries beyond actual data, leading to premature exit or out-of-bound access. Also, bubble sort starts from index 1, skipping W[0], but data is stored starting from W[1], so this might be okay if intentional—but logic is fragile.]
        if(strcmp(W[i].w,W[i+1].w)>0){
            strcpy(tem,W[i].w);
            strcpy(W[i].w,W[i+1].w);
            strcpy(W[i+1].w,tem);
            flag++;
        }
    }
    if(flag>0){
        goto begin;
    }
    for(i=1;W[i].n!=0;i++){
        strcpy(tem,W[i].w);
        for(j=i+1;strcmp(W[j].w,tem)==0;j++){
            W[i].n++;
            W[j].n=0;
        }
        i=j-1;
    }
    for(i=1;i<=299;i++){
        if(W[i].n!=0){
            printf("%s %d\n",W[i].w,W[i].n);
        }
    }
    return 0;
}