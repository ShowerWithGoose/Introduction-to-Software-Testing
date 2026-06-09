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
    strcpy(w[wor_in].s,tmp); // @@ [The new word is not added when the loop ends without finding a match. The code inside the loop only handles the case when a match is found; if no match is found, the loop exits and the new word is never added. This causes missing words in the output.]
    w[wor_in].num++;
    wor_in++;
}

int main()
{
    
    FILE*in = fopen("article.txt","r");
    char s[1024]={0};
    while(fgets(s,2014,in)) // @@ [The second argument to fgets should be the size of the buffer (1024), not 2014. Using 2014 may cause buffer overflow since s is only 1024 bytes long. However, this might not directly cause the wrong answer but is unsafe. The main logic error is elsewhere.]
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
        if(strlen(tmp)>0) // @@ [After processing each line, if there's a word left in tmp (i.e., the line didn't end with a non-alpha character), it won't be processed. For example, if the line ends with a word, that word is never passed to sch(). This leads to missing words.]
        {
            sch(tmp);
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