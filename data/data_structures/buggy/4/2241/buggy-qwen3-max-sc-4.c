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
        
    } @@ [The loop does not handle the last word if the file doesn't end with space or newline. Also, `c` is declared as `char`, but `fgetc()` returns `int`; comparing `char c` to `EOF` can cause infinite loops on systems where `char` is unsigned.]

    for(int i=0;i<=word+1;i++){
        for(int j=i;j<=word+1;j++){
            if(S[i][0] != '\0')
            if(strcmp(S[i],S[j]) == 0){
                time[i] ++; 
                if(i!=j)
                S[j][0] = '\0';
            }
        }
    } @@ [`time` array is uninitialized, leading to undefined behavior when incrementing `time[i]`. Also, the double loop logic incorrectly counts frequencies and may access out-of-bounds indices due to `word+1` usage.]

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
    } @@ [Sorting logic uses incorrect bounds (`word+1`) which may include uninitialized or empty strings, and the inner loop starts at `j=i` instead of `j=i+1`, causing unnecessary self-comparisons and potential incorrect ordering.]

//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    } @@ [Only prints words with non-zero `time[sort[i]]`, but since `time` was never initialized to 1 for each unique word (only incremented on duplicates), original single-occurrence words may have `time[i] == 0` and thus be omitted. Also, the loop again uses `word+1` which may go out of valid range.]
    return 0;
}