#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char S[500][100];
int time[500];
char c ;
int sort[500]={};
int compare(const void *a,const void *b);
int main()
{    
    FILE *in = NULL;
    if((in = fopen("article.txt","r")) == NULL){
        printf("YOU ARE LOSER");
    }    
    int word=0,cc=0;    
    while((c = fgetc(in))!=EOF){
        if(isupper(c)){
            c = c + ('a'-'A');
        }
        
        if(isalpha(c)){
            S[word][cc++] = c;
//            printf("%c",c);
        }
        else if(c ==' '|| c =='\n'){ // @@ Only space and newline are considered delimiters; other non‑letter characters (e.g., digits, punctuation) are ignored, causing words to be incorrectly merged.
            word ++ ;
            cc = 0;    
        }
        
    }

    for(int i=0;i<=word+1;i++){ // @@ Loop bound should be i < word, not i <= word+1. This accesses uninitialized array elements and may cause out‑of‑bounds errors.
        for(int j=i;j<=word+1;j++){ // @@ Same issue: bound should be j < word.
            if(S[i][0] != '\0')
            if(strcmp(S[i],S[j]) == 0){
                time[i] ++; 
                if(i!=j)
                S[j][0] = '\0';
            }
        }
    }
//        for(int i=0;i<=word;i++){
//            printf("%s\n",S[i]);
//        }
    for(int i=0;i<=word+1;i++){ // @@ Bound should be i < word.
        sort[i] = i;
    }
    for(int i=0;i<word+1;i++){ // @@ Bound should be i < word.
        for(int j=i;j<word +1;j++) // @@ Bound should be j < word.
        if(strcmp(S[sort[i]],S[sort[j]])>0){
            int t = sort[i];
            sort[i] = sort[j];
            sort[j] = t;
        }
    }
//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){ // @@ Bound should be i < word.
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    }
    return 0;
}