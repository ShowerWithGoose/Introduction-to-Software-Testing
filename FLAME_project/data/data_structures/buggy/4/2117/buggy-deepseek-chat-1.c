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
        strcpy(w[wor_in].s,tmp); // @@ The strcpy and increment are placed inside the for loop, causing them to execute after every comparison, not just when the word is not found. This should be outside the for loop.
        w[wor_in].num++; // @@ Same issue: this should be outside the for loop, executed only if the word is not found in the entire array.
        wor_in++; // @@ Same issue: this should be outside the for loop.
        return; // @@ This return is inside the loop, causing the function to exit after the first iteration regardless of whether the word was found or not.
    }
}

int main()
{
    
    FILE*in = fopen("article.txt","r");
    char s[1024]={0};
    while(fgets(s,2014,in)) // @@ The buffer size is 1024, but fgets uses 2014, which is larger than the buffer and may cause buffer overflow.
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