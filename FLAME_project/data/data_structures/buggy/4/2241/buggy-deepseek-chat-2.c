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
        else if(c ==' '|| c =='\n'){ // @@ This condition does not handle all non-letter characters (e.g., digits, punctuation like '.'), causing words to be concatenated incorrectly. For example, "since1972" becomes "since" and "1972" is ignored, but "since1972" should be treated as two separate words "since" and "1972" only if digits are non-letters; however, the issue is that when a non-letter like '.' appears, it is not handled, so words like "since1972.C" are not split properly, leading to "sincec" being formed.
            word ++ ;
            cc = 0;    
        }
        
    }

    for(int i=0;i<=word+1;i++){ // @@ The loop bounds are incorrect; they should be i < word (or i <= word-1) to avoid accessing uninitialized or out-of-bounds elements. Using <= word+1 may cause undefined behavior and incorrect counting.
        for(int j=i;j<=word+1;j++){ // @@ Same issue with loop bounds; j should start from i and go to word-1, not word+1.
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
    for(int i=0;i<=word+1;i++){ // @@ Loop bounds should be i < word, not <= word+1.
        sort[i] = i;
    }
    for(int i=0;i<word+1;i++){ // @@ Loop bounds should be i < word, not < word+1.
        for(int j=i;j<word +1;j++) // @@ Loop bounds should be j < word, not < word+1.
        if(strcmp(S[sort[i]],S[sort[j]])>0){
            int t = sort[i];
            sort[i] = sort[j];
            sort[j] = t;
        }
    }
//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){ // @@ Loop bounds should be i < word, not <= word+1.
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    }
    return 0;
}