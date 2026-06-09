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
    while((t=fgetc(in))!=EOF){ @@ [The variable 't' is declared as char, but fgetc returns an int to properly distinguish EOF from valid characters. Using char may cause premature loop termination or infinite loops on systems where char is signed and a byte with value 0xFF is read.]
        if(isdigit(t)){ @@ [The problem defines a word as consisting only of letters, but this condition checks for digits using isdigit(). It should use isalpha() instead. This causes digits to be treated as word characters and letters to be ignored.]
            t=tolower(t); @@ [tolower() is meant for letters; applying it to digits has no effect but is logically incorrect here since digits shouldn't be part of words per the problem statement.]
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){ @@ [The logic for detecting word boundaries is flawed. 'q' is used as a flag but is only set to 0 inside the digit branch, which is wrong. Also, when a non-digit (e.g., space or punctuation) is encountered after a word, this block tries to process the word, but if the first character read is not a digit, 'q' remains uninitialized (garbage), leading to undefined behavior.]
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){ @@ [Variable 'i' is global and uninitialized (default 0), but if no words are added, this loop doesn't run. However, the bigger issue is that 'w' may contain garbage if no valid word was built, and strcmp with uninitialized content leads to undefined behavior.]
                if(strcmp(wordlist[x].word,w)==0){
                    wordlist[x].count++;
                    y=1;
                    break;
                }
            }
            if(y==0){
                strcpy(wordlist[i].word,w); @@ [If 'w' was never properly null-terminated (e.g., if j==0 or buffer overflow), strcpy may copy garbage or crash. Also, 'w' is not guaranteed to be a valid C string because it's only reset via strcpy(w,"") after processing, but initial reads may leave it uninitialized.]
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