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
        strcpy(w[wor_in].s,tmp);
        w[wor_in].num++;
        wor_in++;
        return;
    }
    strcpy(w[wor_in].s,tmp); // @@ [The logic inside the loop is flawed: the new word insertion code runs inside the loop and returns immediately, so it never checks beyond the first word. Also, if the loop ends without finding a match, the new word is never added. This line should be outside the loop.]
}

int main()
{
    
    FILE*in = fopen("article.txt","r");
    if (in == NULL) return 1; // @@ [Missing check for file open failure, which may cause segmentation fault or undefined behavior on some systems, though not necessarily a compilation error. However, the primary issue is elsewhere.]
    char s[1024]={0};
    while(fgets(s,2014,in)) // @@ [Buffer overflow risk: fgets reads up to 2013 characters into s[1024], which can cause memory corruption. Should be fgets(s, sizeof(s), in). But this is runtime, not compilation.]
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
        if(strlen(tmp)>0) sch(tmp); // @@ [Missing handling of last word in line if line doesn't end with non-alpha character (e.g., ends with newline or EOF). But again, this is logical, not compilation.]
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