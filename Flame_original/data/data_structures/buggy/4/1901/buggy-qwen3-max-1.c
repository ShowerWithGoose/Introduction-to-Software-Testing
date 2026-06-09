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
    in=fopen("article.txt","r"); @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc on a NULL pointer leads to undefined behavior. The program should check if 'in' is NULL and handle the error.]
    char t;
    int q;
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){ @@ [The variable 't' is of type char, but fgetc returns an int. This causes incorrect EOF comparison because EOF (typically -1) may be truncated when stored in a char, especially if char is unsigned. This can lead to infinite loops or missed EOF detection.]
        if(isdigit(t)){ @@ [The problem requires processing only alphabetic characters as words, but this condition checks for digits using isdigit(). It should use isalpha() instead. Additionally, tolower() is applied to digits, which is unnecessary and incorrect per problem definition.]
            t=tolower(t);
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){
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