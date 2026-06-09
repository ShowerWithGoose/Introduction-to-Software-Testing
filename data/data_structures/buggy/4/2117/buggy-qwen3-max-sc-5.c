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
        strcpy(w[wor_in].s,tmp); // @@ [This line is inside the loop and executes on first non-matching word, causing premature insertion and increment. It should be outside the loop after checking all existing words.]
        w[wor_in].num++; // @@ [Same issue: this runs inside the loop on first mismatch, leading to duplicate entries and incorrect counts.]
        wor_in++; // @@ [Same issue: increments inside loop, breaking logic of searching through all existing words before adding a new one.]
        return; // @@ [Premature return inside loop prevents checking remaining words in the list.]
    }
}

int main()
{
    
    FILE*in = fopen("article.txt","r");
    char s[1024]={0};
    while(fgets(s,2014,in)) // @@ [Buffer size mismatch: s is only 1024 bytes, but fgets reads up to 2013 characters plus null terminator, which can cause buffer overflow. Should be sizeof(s) or 1024.]
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
            if(strlen(tmp)==0)
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
        memset(s,0,1024*sizeof(char));
      
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