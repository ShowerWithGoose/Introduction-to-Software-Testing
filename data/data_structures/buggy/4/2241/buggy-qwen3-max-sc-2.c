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
        else if(c ==' '|| c =='\n'){
            word ++ ;
            cc = 0;    
        }
        
    } // @@ [The loop does not handle the last word if the file doesn't end with space or newline. Also, `c` is declared as `char`, but `fgetc()` returns `int`; comparing `char` to `EOF` can cause infinite loops on systems where `char` is unsigned.]

    for(int i=0;i<=word+1;i++){
        for(int j=i;j<=word+1;j++){
            if(S[i][0] != '\0')
            if(strcmp(S[i],S[j]) == 0){
                time[i] ++; 
                if(i!=j)
                S[j][0] = '\0';
            }
        }
    } // @@ [The array `time` is uninitialized, so it contains garbage values. Also, the logic incorrectly increments `time[i]` even when `i == j`, leading to off-by-one errors in counts.]

//        for(int i=0;i<=word;i++){
//            printf("%s\n",S[i]);
//        }
    for(int i=0;i<=word+1;i++){
        sort[i] = i;
    }
    for(int i=0;i<word+1;i++){
        for(int j=i;j<word +1;j++)
        if(strcmp(S[sort[i]],S[sort[j]])>0){
            int t = sort[i];
            sort[i] = sort[j];
            sort[j] = t;
        }
    } // @@ [The sorting loop has incorrect bounds (`j` starts at `i` instead of `i+1`), causing unnecessary comparisons and potential instability. Also, comparing strings that may be empty (`S[k][0] == '\0'`) leads to undefined behavior in `strcmp`.]

//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    } // @@ [This only prints words with non-zero `time[sort[i]]`, but due to uninitialized `time[]` and incorrect counting logic, many valid words may have zero or garbage counts and thus be omitted. Also, words that appear once may not be printed because `time[i]` was never initialized to 1.]
    return 0;
}