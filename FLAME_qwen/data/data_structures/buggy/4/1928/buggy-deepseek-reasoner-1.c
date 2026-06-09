#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Word
{
    char s[500];
    int count;
}word[500];
int cmp(struct Word *e1,struct Word *e2) // @@ The function signature should be 'int cmp(const void *a, const void *b)' to match qsort's expected comparator; passing a different pointer type causes a type mismatch (at least a warning, possibly a compilation error with strict flags).
{
    if(strcmp(e1->s,e2->s)>0)
    return -1; // @@ The comparator must return 0 when strings are equal; failing to return 0 results in undefined behavior for qsort and may cause incorrect sorting.
    else return 1; // @@ Same issue: should return 0 if equal, otherwise the comparator is not a proper ordering function.
}
int main()
{
    FILE *fp;
    char c; // @@ The variable 'c' should be 'int' because fgetc returns an int (to correctly handle EOF, which is -1). Using 'char' may cause sign extension issues and a potential infinite loop.
    int i=-1,flag=0,j=0,out=0;
    fp=fopen("article.txt","r");
    while((c=fgetc(fp))!=EOF) // @@ The condition uses 'c' (a char) compared to EOF; if char is unsigned by default, EOF (-1) becomes 255, so the loop never terminates. Should use an int variable.
    {
        if(isalpha(c)>0)
        {
            if(isupper(c)>0)
                c=c+'a'-'A';
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ Incorrect index: using pre-increment '++j' skips index j=1, causing a gap in the word string. Should use 'j++' to continue from the current position.
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0;
            continue;
        }
        
    }
    for(int k=0;k<=i;k++)
    word[k].count=1;
    for(int k=0;k<=i;k++)
    {
        for(int p=k+1;p<=i;p++)
        {
            if(strcmp(word[k].s,word[p].s)==0)
            {
                word[k].count++;
                memset(word[p].s,'z',3*sizeof(char)); // @@ This does not properly remove the duplicate word; memset fills with 'z' but leaves no null terminator, corrupting the string. Should set word[p].s[0]='\0' to mark it as empty.
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ The number of elements passed to qsort is incorrect: it assumes the first i-out+1 entries are the unique words, but duplicates are not contiguous in the array. Also, the comparator 'cmp' has an incompatible type and does not return 0 for equal strings, causing undefined behavior.
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}