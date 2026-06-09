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
int cmp(struct Word *e1,struct Word *e2) // @@ [Compilation Error: qsort expects a callback with signature int (*)(const void *, const void *), but this function uses struct Word pointers, causing type mismatch.]
{
    if(strcmp(e1->s,e2->s)>0)
    return -1;
    else return 1;
}
int main()
{
    FILE *fp;
    char c;
    int i=-1,flag=0,j=0,out=0;
    fp=fopen("article.txt","r");
    while((c=fgetc(fp))!=EOF)
    {
        if(isalpha(c)>0)
        {
            if(isupper(c)>0)
                c=c+'a'-'A';
            if(flag==0)
            {

                word[++i].s[j++]=c; // @@ [Logical Error: Strings are not null-terminated with '\0', causing undefined behavior in strcmp and printf.]

            }
            else
            {
                word[i].s[++j]=c; // @@ [Logical Error: Strings are not null-terminated with '\0', causing undefined behavior in strcmp and printf.]
            }

            flag=1;
        }
        else
        {
            flag=0;j=0;
            continue;
        }

    }
    for(int k=0;k<=i;k++) // @@ [Compilation Error: Variable declaration inside for-loop initializer is not allowed in C89/C90 standard; declare k outside the loop.]
    word[k].count=1;
    for(int k=0;k<=i;k++) // @@ [Compilation Error: Variable declaration inside for-loop initializer is not allowed in C89/C90 standard; declare k outside the loop.]
    {
        for(int p=k+1;p<=i;p++) // @@ [Compilation Error: Variable declaration inside for-loop initializer is not allowed in C89/C90 standard; declare p outside the loop.]
        {
            if(strcmp(word[k].s,word[p].s)==0)
            {
                word[k].count++;
                memset(word[p].s,'z',3*sizeof(char));
                out++;
            }

        }


    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [Compilation Error: Incompatible function pointer type passed to qsort due to mismatched cmp signature.]
    for(int k=0;k<i-out+1;k++) // @@ [Compilation Error: Variable declaration inside for-loop initializer is not allowed in C89/C90 standard; declare k outside the loop.]
    {
        printf("%s %d\n",word[k].s,word[k].count);

    }
}