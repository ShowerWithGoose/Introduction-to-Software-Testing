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
        fgetc(in); // @@ This consumes the character immediately following the word read by fscanf. If it's a letter (part of the next word or same word if delimiters are weird), it is lost. More importantly, fscanf with %s skips leading whitespace and reads until whitespace. The subsequent fgetc consumes the delimiter (space, newline, etc.). However, if the file ends without a newline or has specific formatting, this might skip valid characters or cause issues. But the bigger issue is how words are parsed. fscanf("%s") reads "life." as one token. The code then tries to strip non-alpha chars.
        printf("%s ",tem); // @@ This line prints the raw token including punctuation to stdout, which violates the output format requirement (only word frequency should be printed).
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
    for(i=1;W[i+1].n!=0;i++){ // @@ The loop condition W[i+1].n!=0 is unsafe. It assumes that empty slots have n=0 (which is true initially) but relies on contiguous filled slots. If j exceeds bounds or logic fails, this could access uninitialized memory or miss sorting. Also, bubble sort implementation is inefficient but logically okay if bounds are correct. However, the upper bound isn't checked against array size.
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
        for(j=i+1;strcmp(W[j].w,tem)==0;j++){ // @@ This loop does not check if W[j].n is 0 or if j goes out of bounds. If there are no more matches, strcmp will compare against empty strings or garbage if n=0 entries aren't strictly empty strings (they are initialized to "\0" so strcmp returns 0 only if tem is also empty, which it isn't). Wait, if W[j].w is "\0", strcmp("word", "") is not 0. So it stops. But it doesn't check array bounds.
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