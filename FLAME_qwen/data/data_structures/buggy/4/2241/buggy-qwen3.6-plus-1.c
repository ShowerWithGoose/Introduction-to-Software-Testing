#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char S[500][100];
int time[500];
char c ;
int sort[500]={}; // @@ Compilation error: empty braces {} are invalid for array initialization in standard C; should be {0}
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
        else if(c ==' '|| c =='\n'){ // @@ Logical error: only checks space and newline, ignoring punctuation; should use !isalpha(c) to properly delimit words, and missing null-termination S[word][cc] = '\0' before resetting cc
            word ++ ;
            cc = 0;    
        }
        
    }

    for(int i=0;i<=word+1;i++){ // @@ Logical error: loop bound exceeds valid word indices (0 to word-1), causing out-of-bounds access and incorrect counting
        for(int j=i;j<=word+1;j++){ // @@ Logical error: same off-by-one bound issue as the outer loop
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
    for(int i=0;i<=word+1;i++){ // @@ Logical error: incorrect loop bound for sorting index initialization
        sort[i] = i;
    }
    for(int i=0;i<word+1;i++){ // @@ Logical error: incorrect loop bound for sorting algorithm
        for(int j=i;j<word +1;j++) // @@ Logical error: incorrect loop bound for sorting algorithm
        if(strcmp(S[sort[i]],S[sort[j]])>0){
            int t = sort[i];
            sort[i] = sort[j];
            sort[j] = t;
        }
    }
//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){ // @@ Logical error: incorrect loop bound for output iteration
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    }
    return 0;
}