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
        
    } // @@ [The program does not handle non-alphabetic characters correctly. Words are only separated by space or newline, but the problem states that a word is a sequence of letters, so any non-letter (like '.', digits, etc.) should terminate a word. Also, consecutive non-letters may create empty words.]

    for(int i=0;i<=word+1;i++){
        for(int j=i;j<=word+1;j++){
            if(S[i][0] != '\0')
            if(strcmp(S[i],S[j]) == 0){
                time[i] ++; 
                if(i!=j)
                S[j][0] = '\0';
            }
        }
    } // @@ [The counting logic is flawed: it initializes time[i] implicitly to 0, but never sets time[i] = 1 for the first occurrence. Also, the double loop overcounts because it increments time[i] for every duplicate including itself, leading to incorrect counts.]

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
    } // @@ [The sorting loop has incorrect bounds and logic: inner loop starts at j=i instead of j=i+1, causing unnecessary self-comparison and potential instability. Also, comparing strings that may be empty ('\0') leads to undefined behavior in strcmp.]

//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    } // @@ [Because time[] was never properly initialized to 1 for new words and counting logic is wrong, the output counts are incorrect. Additionally, empty strings (from non-letter separators) may remain and be printed if time[sort[i]] happens to be non-zero due to uninitialized memory.]
    return 0;
}