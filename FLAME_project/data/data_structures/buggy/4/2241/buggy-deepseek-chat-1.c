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
        else if(c ==' '|| c =='\n'){ // @@ The condition does not handle all non-letter characters (e.g., digits, punctuation like '.'), causing words to be concatenated incorrectly. For example, "since1972" becomes "since1972" but digits are not letters, so the word "since" and "c" from "since1972" are not separated properly, leading to wrong word counts.
            word ++ ;
            cc = 0;    
        }
        
    }

    for(int i=0;i<=word+1;i++){ // @@ Loop goes up to word+1, which may access uninitialized or out-of-bounds elements in S and time arrays, causing undefined behavior and incorrect counts.
        for(int j=i;j<=word+1;j++){ // @@ Same issue: loop bound should be word (not word+1) to avoid accessing invalid indices.
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
    for(int i=0;i<=word+1;i++){ // @@ Same off-by-one error: should be i < word, not i <= word+1.
        sort[i] = i;
    }
    for(int i=0;i<word+1;i++){ // @@ Same off-by-one error: should be i < word.
        for(int j=i;j<word +1;j++) // @@ Same off-by-one error: should be j < word.
        if(strcmp(S[sort[i]],S[sort[j]])>0){
            int t = sort[i];
            sort[i] = sort[j];
            sort[j] = t;
        }
    }
//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){ // @@ Same off-by-one error: should be i < word.
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    }
    fclose(in); // @@ Missing fclose(in) in the original code; added here to match the reference program's behavior.
    return 0;
}