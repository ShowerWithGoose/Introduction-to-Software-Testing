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
        else if(c ==' '|| c =='\n'){ // @@ The condition for separating words is incomplete. It only handles spaces and newlines, but the problem states that a "word" consists only of letters. Any non-letter character (like digits or punctuation such as '.') should also act as a delimiter. The current code treats "since1972.C" incorrectly because '1', '9', etc., are not alpha, but they are not space/newline either, so they are ignored without terminating the current word "since". Then '.' is also ignored. Then 'C' starts a new word? No, 'C' is alpha, so it appends to the current buffer if cc is not reset. Actually, since '1' is not alpha and not space/newline, it falls through. The word "since" is stored. Then '1' is encountered. It is not alpha. It is not space/newline. So nothing happens. The buffer `S[word]` still contains "since". Then '9'... same. Then '.'... same. Then 'C'. It is alpha. It gets appended to `S[word]`. So `S[word]` becomes "sinceC". This merges words incorrectly and fails to count delimiters like digits and punctuation as word boundaries.
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