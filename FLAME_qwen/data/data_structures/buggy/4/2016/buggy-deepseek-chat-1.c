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
        fgetc(in);
        printf("%s ",tem);
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
    for(i=1;W[i+1].n!=0;i++){
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