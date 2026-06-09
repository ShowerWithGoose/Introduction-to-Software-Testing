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
        
    } // @@ [The program fails to handle non-alphabetic characters that are not space or newline (e.g., digits, punctuation like '.', etc.), causing words like "since1972" to be split incorrectly. Also, the last word may not be terminated properly if the file doesn't end with space or newline.]

    for(int i=0;i<=word+1;i++){
        for(int j=i;j<=word+1;j++){
            if(S[i][0] != '\0')
            if(strcmp(S[i],S[j]) == 0){
                time[i] ++; 
                if(i!=j)
                S[j][0] = '\0';
            }
        }
    } // @@ [The counting logic is flawed: it initializes time[i] implicitly to 0, but only increments when a duplicate is found. Thus, each unique word starts with count 0 and gets incremented for each duplicate, leading to undercount by 1. Also, the nested loop goes beyond valid word indices (word+1), accessing uninitialized memory.]

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
    } // @@ [The sorting loop has incorrect bounds and logic: inner loop should start from i+1, and the comparison condition leads to unstable or incorrect ordering. Also, comparing strings that may be empty ('\0' at start) causes undefined behavior in strcmp.]

//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    } // @@ [Because time[] was never initialized to 1 for first occurrence, and due to off-by-one errors in word indexing, many words have count 0 and are skipped, while others are miscounted. Additionally, empty strings may be printed if not properly filtered.]
    return 0;
}