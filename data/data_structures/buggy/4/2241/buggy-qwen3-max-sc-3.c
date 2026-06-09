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
        
    } // @@ [The program does not handle the last word if the file doesn't end with space or newline. Also, `c` is declared as `char`, but `fgetc()` returns `int`; using `char` can cause EOF comparison issues.]

    for(int i=0;i<=word+1;i++){
        for(int j=i;j<=word+1;j++){
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
    }
//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    } // @@ [The output logic is flawed: `time[i]` is never initialized to 1 for each word's first occurrence, so counts are off by one. Also, words that appear only once may not be printed because `time[sort[i]]` could be zero.]
    return 0;
}