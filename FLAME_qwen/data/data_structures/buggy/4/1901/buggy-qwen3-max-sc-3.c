#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    char word[30];
    int count;
};
struct node wordlist[1000];
int cmp(const void*a,const void*b){
    struct node *pa=(struct node *)a;
    struct node *pb=(struct node *)b;
    if(strcmp(pa->word,pb->word)>0){
        return 1;
    }else{
        return -1;
    }
}
int i;
int main()
{
    FILE *in;
    in=fopen("article.txt","r"); @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc on a NULL pointer causes undefined behavior. The program should check if in is NULL and handle the error.]
    char t;
    int q;
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){ @@ [The variable 't' is of type char, but fgetc returns an int. Comparing a char to EOF can lead to infinite loops or incorrect behavior because EOF is typically -1, which may be indistinguishable from a valid char value when stored in a signed char. This causes incorrect loop termination or misinterpretation of bytes as EOF.]
        if(isdigit(t)){ @@ [The problem defines a word as consisting only of letters, but this condition checks for digits using isdigit(). It should use isalpha() instead. This causes digits to be treated as part of words, violating the problem's word definition.]
            t=tolower(t); @@ [tolower() is meant for letters; applying it to digits is unnecessary and misleading. Moreover, since the condition above incorrectly uses isdigit(), this line processes digits as if they were letters.]
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){ @@ [The logic for detecting word boundaries is flawed. The flag 'q' is used inconsistently: it's set to 0 inside the digit branch (which shouldn't exist), and then this else-if triggers only after leaving a digit sequence. Since words should consist of letters, not digits, and there's no handling for letter sequences, valid words are never processed. Also, the first character of a word (if it were a letter) would not be captured because the loop only acts on digits.]
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){
                if(strcmp(wordlist[x].word,w)==0){
                    wordlist[x].count++;
                    y=1;
                    break;
                }
            }
            if(y==0){
                strcpy(wordlist[i].word,w);
                wordlist[i].count=1;
                i++;
            }
            strcpy(w,"");
        }    
    }
    qsort(wordlist,i,sizeof(struct node),cmp);
    for(int p=0;p!=i;p++){
        printf("%s %d\n",wordlist[p].word,wordlist[p].count);
    }
    return 0;
 }