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
        else if(c ==' '|| c =='\n'){ // @@ The condition for separating words is incomplete. It only treats spaces and newlines as delimiters, but the problem states that a "word" consists only of letters. Therefore, any non-letter character (like digits or punctuation such as '.') should also act as a delimiter. In the test case "since1972.C", the '.' and digits are not handled correctly as delimiters, causing "since" and "c" to potentially merge or be processed incorrectly depending on previous state, or creating invalid words like "sincec" if logic fails to reset properly across non-alpha chars that aren't space/newline. Specifically, "since1972.C" -> 's','i','n','c','e' are added to S[word]. Then '1' is not alpha, not space/newline, so it's ignored but cc is not reset. Then '9'... ignored. Then '.' ignored. Then 'C' (converted to 'c') is alpha, so it appends to current S[word] resulting in "sincec". This explains the "sincec" output.
            word ++ ;
            cc = 0;    
        }
        
    }

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
    }
    return 0;
}