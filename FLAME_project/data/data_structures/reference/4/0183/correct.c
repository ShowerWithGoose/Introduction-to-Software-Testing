#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char s[10000];

struct words
{
    char a[20];
    int num;
}word[1000];

int cmp(const void *e, const void *f) 
{
    struct words  *g = (struct words *)e;
    struct words  *h = (struct words *)f;
    return strcmp(g->a,h->a);
    
}

int main()
{
    int j=0;
    //int n=0;
    int i=0;
    int num_k=0;
    char c;
    int cnt=0;
    struct words word[1000];
    FILE*fp;
    fp=fopen("article.txt","r");
    while ((c=fgetc(fp))!=EOF)
    {
        s[j]=c;j++;
    }

    for ( i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            cnt++;num_k=0;
        }
        else if (isalpha(s[i]))
        {
            word[cnt].a[num_k++]=tolower(s[i]);
        }
        
        
    }
    
    /*for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < strlen(s); j++)
        {
            for ( num_k = 0; num_k < strlen(word[i].a[num_k]); i++)
            {
                if (s[j]==word[i].a[num_k])
                {
                    cnt++;
                    continue;
                }
                
            }
            if (cnt==num_k)
            {
                word[i].num++;
                
            }
            cnt=0;
            
        }
        
    }*/

    qsort(word,cnt,sizeof(word[0]),cmp);

    for ( i = 0; i < cnt; i++)
    {
        if(strlen(word[i].a)) 
        {
            word[i].num = 1;
        }
            
    }
    for ( i = 0; i < cnt; i++)
        if (!strcmp(word[i].a, word[i + 1].a))
        {
            word[i + 1].num += word[i].num; 
           word[i].num = 0;
        }

    for ( i = 0; i < cnt; i++)
    {
        if (word[i].num != 0)
        {
            printf("%s %d\n", word[i].a, word[i].num);
        }
    }

    fclose(fp);

    return 0;
    
}


