#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char S[500][100];
int time[500];
char c ; // @@ Error: 'c' is declared as 'char', but fgetc() returns 'int'. Using a char variable to store the result of fgetc() can cause incorrect detection of EOF, especially on systems where 'char' is unsigned. This may lead to an infinite loop or failure to detect the end of the file.
int sort[500]={};
int compare(const void *a,const void *b);
int main()
{    
    FILE *in = NULL;
    if((in = fopen("article.txt","r")) == NULL){
        printf("YOU ARE LOSER"); // @@ Error: When fopen fails, the program should handle the error, e.g., by returning or exiting. Here it only prints a message and then continues to use a NULL file pointer, which will cause undefined behavior (likely a crash).
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
        else if(c ==' '|| c =='\n'){ // @@ Error: This delimiter condition only treats spaces and newlines as word separators. It should treat any non‑alphabetic character as a delimiter. As a result, words separated by punctuation (e.g., "hello,world") will be merged, and consecutive delimiters create empty entries. Also, it does not check whether any letters have been accumulated (cc>0) before incrementing 'word', leading to empty words in the array.
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