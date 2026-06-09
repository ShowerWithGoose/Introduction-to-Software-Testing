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
    while((t=fgetc(in))!=EOF){ @@ [The variable 't' is of type char, but fgetc returns an int to properly distinguish EOF from valid characters. Using char may cause premature loop termination or infinite loops on systems where char is signed and a byte with value 0xFF is read.]
        if(isdigit(t)){ @@ [The problem defines a word as consisting only of letters, but this condition checks for digits using isdigit(). It should use isalpha() instead. Also, tolower() is applied to a digit, which is unnecessary and incorrect per problem requirements.]
            t=tolower(t);
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){ @@ [The logic for detecting word boundaries is flawed. The variable 'q' is used inconsistently: it's set to 0 inside the isdigit block (which should be isalpha), but the else-if(q==0) triggers only after leaving a digit sequence, not a letter sequence. This misses words entirely because letters are never processed.]
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){ @@ [At program start, global variable 'i' is zero-initialized, so this loop doesn't run initially, which is okay. However, the word 'w' may contain garbage if no valid word was built, leading to undefined behavior in strcmp. Also, the word buffer 'w' is not null-terminated before being used in strcmp.]
                if(strcmp(wordlist[x].word,w)==0){
                    wordlist[x].count++;
                    y=1;
                    break;
                }
            }
            if(y==0){
                strcpy(wordlist[i].word,w); @@ [The string 'w' is not guaranteed to be null-terminated here, causing strcpy to read beyond intended bounds.]
                wordlist[i].count=1;
                i++;
            }
            strcpy(w,"");
        }    
    }
    qsort(wordlist,i,sizeof(struct node),cmp); @@ [The comparison function 'cmp' does not return 0 when strings are equal, violating the requirement of qsort's comparison function (it must define a strict weak ordering). This can lead to undefined behavior during sorting.]
    for(int p=0;p!=i;p++){
        printf("%s %d\n",wordlist[p].word,wordlist[p].count);
    }
    return 0;
 }