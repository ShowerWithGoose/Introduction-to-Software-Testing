#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct lnode {
    char  word[100000];  // @@ Error: The word buffer size is excessively large (100000 bytes). This will cause memory overflow and undefined behavior. Should be a reasonable size like 70.
    int count;
};
struct lnode wordl[100000];  // @@ Error: Array of structs with huge word buffers results in enormous memory allocation (100000 * 100000 bytes), likely leading to stack overflow or out-of-memory. Should be a smaller structure or use dynamic allocation.
int cmp(void *p1,void *p2)
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
                    ji=0;  // @@ Error: Missing reset of `begin = 0;` after processing a word. This causes subsequent non‑letter characters to incorrectly treat an empty string as a new word, inserting empty entries into the array. Add `begin = 0;` after this line to prevent false word creation.
                }
            }
        }
    }
    qsort(wordl,numci,sizeof(struct lnode),cmp);
    int u;
    for(u=1;u<numci;u++)  // @@ Error: Loop starts at u=1, skipping the first element (index 0). Should start at u=0 to print all words. This results in missing the first word in the sorted output.
    {
        printf("%s %d\n",wordl[u].word,wordl[u].count);
    }
    
    fclose(in);
    
    
    return 0;
}