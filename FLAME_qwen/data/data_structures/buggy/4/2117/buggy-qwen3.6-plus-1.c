#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
int cmp(const void*p,const void*q);
typedef struct word
{
    int num;
    char s[35];
}word;
word w[600];
int wor_in=0;
void sch(char* tmp)
{
    int i=0;
    for(i=0;i<wor_in;i++)
    {
        if(!strcmp(w[i].s,tmp))
        {
            w[i].num++;
            return;
        }
        strcpy(w[wor_in].s,tmp); // @@ Error: Incorrectly placed inside the for loop. It should be executed only after the loop finishes without finding a match.
        w[wor_in].num++; // @@ Error: Incorrectly placed inside the for loop. Should be outside to initialize the count for a new word.
        wor_in++; // @@ Error: Incorrectly placed inside the for loop. Should be outside to increment the word count after adding a new word.
        return; // @@ Error: Incorrectly placed inside the for loop. Causes premature return after checking only the first existing word.
    }
}

int main()
{
    
    FILE*in = fopen("article.txt","r");
    char s[1024]={0};
    while(fgets(s,2014,in)) // @@ Error: The size argument 2014 exceeds the buffer size of s (1024), which may cause buffer overflow. Should be sizeof(s) or 1024.
    {
        int m=0;
        for(m=0;m<strlen(s);m++)
        {
            s[m]=tolower(s[m]);
        }
        int tt=0;
        char tmp[100]={0};
        int j=0;
        for(j=0;j<strlen(s);j++)
        {
            if(!isalpha(s[j]))
        {
            if(strlen(tmp)==0) // @@ Error: tmp is not null-terminated after adding characters, so strlen may read out of bounds. Should check tt==0 instead.
            {
                continue;
            }
            else
            {
                sch(tmp);
                memset(tmp,0,100*sizeof(char));
                tt=0;
            }
        }
        else
        {
            tmp[tt++]=s[j];
        }
        }
        memset(s,0,1024*sizeof(char)); // @@ Error: Missing handling for the last word in the line. If the line ends with a letter, tmp still contains a word that needs to be processed (e.g., if(tt>0) sch(tmp);) before clearing s.
      
    }
      qsort(w,wor_in,sizeof(word),cmp);
      int k=0;
      for(k=0;k<wor_in;k++)
      {
        printf("%s %d\n",w[k].s,w[k].num);
      }


 return 0;
}
int cmp(const void*p,const void*q)
{
    return strcmp(((word*)p)->s,((word*)q)->s);
}