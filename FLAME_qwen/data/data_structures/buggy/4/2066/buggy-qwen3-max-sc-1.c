#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct lnode {
    char  word[100000];
    int count;
};
struct lnode wordl[100000]; 
int cmp(void *p1,void *p2) // @@ [The comparison function for qsort must have signature 'int (*)(const void *, const void *)'; missing 'const' qualifiers causes undefined behavior and may lead to compilation warnings or errors on strict compilers.]
{
    struct lnode* a=(struct lnode*)p1;
    struct lnode* b=(struct lnode*)p2;
    return (strcmp(a->word,b->word));
}
int main()
{
    FILE *in;
    int numci=0;
    char ci[1000000];
    in=fopen("article.txt","r");
    while(fgets(ci,1024,in) !=NULL)
    {  
        
        char zanci[10000];
        int len=strlen(ci);
        
        int i=0,poi=0;
        int ji=0;
        for(i=0;i<len;i++)
        {
            if(ci[i]>='A'&&ci[i]<='Z')
            {
                ci[i]=ci[i]+32;
                
            }
        }
        int begin=0;
        for(i=0;i<len;i++)
        {
            if(ci[i]>='a'&&ci[i]<='z')
            {
                zanci[ji]=ci[i];
                ji++;
                begin=1;
            }
            else
            {   
                if(begin==1)
                {   zanci[ji]='\0';
                    int hao=0;
                    int k=0;
                    
                    for(k=0;k<numci;k++)
                    {
                        if(strcmp(wordl[k].word,zanci)==0)
                        {
                            wordl[k].count++;
                            hao=1;
                            memset(zanci, 0, sizeof zanci); 
                            break;
                        }
                    }
                    if(hao==0)
                    {   
                        zanci[ji]='\0';
                        strcpy(wordl[numci].word,zanci);
                        wordl[numci].word[ji]='\0';
                        memset(zanci, 0, sizeof zanci);
                        wordl[numci].count=1;
                        numci++;
                    }
                    ji=0;
                    begin=0; // @@ [Missing reset of 'begin' flag after processing a word; this causes incorrect handling of consecutive non-letter characters and may skip words at the end of line if not followed by non-letter.]
                }
            }
        }
        // @@ [Missing handling of a word at the very end of the line if the line ends without a non-letter character (e.g., newline is stripped and last char is a letter).]
    }
    qsort(wordl,numci,sizeof(struct lnode),cmp);
    int u;
    for(u=1;u<numci;u++) // @@ [Loop starts at index 1 instead of 0, skipping the first word entirely in output.]
    {
        printf("%s %d\n",wordl[u].word,wordl[u].count);
    }
    
    fclose(in);
    
    
    return 0;
}