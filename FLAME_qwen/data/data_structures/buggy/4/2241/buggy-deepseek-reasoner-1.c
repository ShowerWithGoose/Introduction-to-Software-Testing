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
        else if(c ==' '|| c =='\n'){   // @@ Logical error: only space and newline are considered word separators; punctuation (e.g., comma, period) and other non-letter characters should also separate words, causing words to be incorrectly concatenated.
            word ++ ;   // @@ Logical error: consecutive delimiters create empty word entries, which may later be processed incorrectly.
            cc = 0;    
        }
        
    }

    for(int i=0;i<=word+1;i++){   // @@ Potential out-of-bounds access: if word is 499, word+1 equals 500, exceeding array size. Also includes an extra empty row that should not be processed.
        for(int j=i;j<=word+1;j++){   // @@ Same out-of-bounds issue.
            if(S[i][0] != '\0')
            if(strcmp(S[i],S[j]) == 0){
                time[i] ++; 
                if(i!=j)
                S[j][0] = '\0';   // @@ Logical error: modifying the original word array corrupts data for later sorting; sorting will order based on empty strings, destroying correct lexicographic order.
            }
        }
    }
//        for(int i=0;i<=word;i++){
//            printf("%s\n",S[i]);
//        }
    for(int i=0;i<=word+1;i++){   // @@ Potential out-of-bounds access, same as above.
        sort[i] = i;
    }
    for(int i=0;i<word+1;i++){   // @@ Potential out-of-bounds: inner loop uses < word+1, but if word is 499, accessing sort[word+1] is out of bounds.
        for(int j=i;j<word +1;j++)   // @@ Same out-of-bounds issue.
        if(strcmp(S[sort[i]],S[sort[j]])>0){
            int t = sort[i];
            sort[i] = sort[j];
            sort[j] = t;
        }
    }
//    for(int i=0;i<=word+1;i++){
//        printf("%d \n",sort[i]);
//    }
    for(int i=0;i<=word+1;i++){   // @@ Potential out-of-bounds access.
        if(time[sort[i]]){
            printf("%s %d\n",S[sort[i]],time[sort[i]]);
    //        printf(" %d\n",sort[i]);
        }
    }
    return 0;
}