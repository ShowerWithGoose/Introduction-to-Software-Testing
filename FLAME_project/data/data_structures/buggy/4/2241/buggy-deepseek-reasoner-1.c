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
        }
        else if(c ==' '|| c =='\n'){ // @@ Only space/newline considered delimiters; digits/punctuation should also end words.
            word ++ ; // @@ Word index incremented without null-terminating previous word (S[word-1] needs '\0').
            cc = 0;    
        }
        
    } // @@ No finalization for the last word (if characters remain without trailing delimiter).

    for(int i=0;i<=word+1;i++){ // @@ Loop bound i<=word+1 is too large; should be i<word after proper word count.
        for(int j=i;j<=word+1;j++){ // @@ Loop bound j<=word+1 is too large.
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
    for(int i=0;i<=word+1;i++){ // @@ Loop bound i<=word+1 is too large.
        sort[i] = i;
    }
    for(int i=0;i<word+1;i++){ // @@ Loop bound i<word+1 is too large.
        for(int j=i;j<word +1;j++) // @@ Loop bound j<word+1 is too large.
        if(strcmp(S[sort[i]],S[sort[j]])>0){
            int t = sort[i];
            sort[i] = sort[j];
            sort[j] = t;
        }
    }
//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){ // @@ Loop bound i<=word+1 is too large.
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    }
    return 0;
}