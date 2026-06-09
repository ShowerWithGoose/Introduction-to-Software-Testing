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
        strcpy(w[wor_in].s,tmp); // @@ Error: This line and the following three lines are incorrectly placed inside the for loop. They should be moved outside the loop to correctly add a new word only after checking all existing entries. Currently, it adds a new word on the first mismatch and fails to add the first word when wor_in is 0.
        w[wor_in].num++; // @@ Error: Part of the misplaced block that should be outside the for loop.
        wor_in++; // @@ Error: Part of the misplaced block that should be outside the for loop.
        return; // @@ Error: Part of the misplaced block that should be outside the for loop.
    }
}

int main()
{
    
    FILE*in = fopen("article.txt","r");
    char s[1024]={0};
    while(fgets(s,2014,in)) // @@ Error: Buffer overflow risk. The size argument 2014 exceeds the array size of s (1024). It should be sizeof(s) or 1024.
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