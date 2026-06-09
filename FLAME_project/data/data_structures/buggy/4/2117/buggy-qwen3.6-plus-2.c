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
        strcpy(w[wor_in].s,tmp); // @@ The logic for adding a new word is inside the loop that searches for existing words. It should only execute if the loop finishes without finding a match (i.e., after the loop). Currently, it adds a duplicate entry every time a non-matching word is checked in the loop, and increments wor_in prematurely, causing logical errors in counting and storage.
        w[wor_in].num++; // @@ Same as above: this line executes incorrectly inside the search loop.
        wor_in++; // @@ Same as above: this line executes incorrectly inside the search loop.
        return; // @@ Same as above: this return statement causes the function to exit after checking only the first existing word (or adding a new one incorrectly), preventing proper search through all existing words.
    }
}

int main()
{
    
    FILE*in = fopen("article.txt","r");
    char s[1024]={0};
    while(fgets(s,2014,in))
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