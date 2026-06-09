#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct wordlist{
    char a[32];
    int b;
    struct wordlist *link;
};
int main()
{
    char a[32]={'\0'};
    char b[1024]={'\0'};
    struct wordlist *wordlist,*wordlist_cal;
    FILE *in;
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent operations on 'in' will cause undefined behavior. The program should check if 'in' is NULL and handle the error appropriately.]
    wordlist=(struct wordlist *)malloc(sizeof(struct wordlist)); // @@ [If malloc fails (returns NULL), dereferencing 'wordlist' later leads to undefined behavior. Also, this initial node is created even before reading any word, and its fields are uninitialized except for link=NULL below. This may lead to incorrect counting if the first word is never processed correctly.]
    wordlist_cal=wordlist;
    wordlist_cal->link=NULL;
    for(int i=0;fgets(b,1024,in)!=NULL;i++) // @@ [If 'in' is NULL (file open failed), fgets causes undefined behavior. Also, the loop variable 'i' is unused.]
    {
        puts(b); // @@ [The problem does not require echoing input lines; this extra output violates the specified output format.]
        int len_b=strlen(b);
        for(int j=0;j<len_b;j++)
        {
            if(b[j]<='Z'&&b[j]>='A')
            {
                b[j]=(b[j]-'A'+'a');
            }
        }
        for(int j=0,k=0;j<len_b;j++)
        {
            if(b[j]<='z'&&b[j]>='a')
            {
                a[k++]=b[j];
            }
            if(!(b[j]>='a'&&b[j]<='z')&&a[1]!='\0') // @@ [Condition 'a[1]!='\0'' incorrectly assumes that a word must have at least 2 characters. Single-letter words (e.g., "a", "I") will be skipped because a[1] is '\0'. Should check if k>0 instead.]
            {
                wordlist_cal=wordlist;
                int flag=0;
                while(wordlist_cal!=NULL)
                {
                    if(strcmp(a,wordlist_cal->a)==0)
                    {
                        wordlist_cal->b++;
                        flag=1;
                        break;
                    }
                    wordlist_cal=wordlist_cal->link;
                }
                wordlist_cal=wordlist;
                if(flag==0)
                {
                    if(wordlist->b==0) // @@ [Relies on uninitialized 'b' field of the first node. Since 'wordlist->b' was never initialized (only malloc'd), its value is indeterminate. This leads to undefined behavior.]
                    {
                        wordlist_cal->b=1;
                        strcpy(wordlist_cal->a,a);
                    }
                    else
                    {
                        while(wordlist_cal->link!=NULL)
                        {
                            wordlist_cal=wordlist_cal->link;
                        }
                        wordlist_cal->link=(struct wordlist *)malloc(sizeof(struct wordlist));
                        wordlist_cal=wordlist_cal->link;
                        wordlist_cal->link=NULL;
                        wordlist_cal->b=1;
                        strcpy(wordlist_cal->a,a);
                    }
                }
                k=0;
                memset(a,'\0',32);
            } 
        }
    }
    
    wordlist_cal=wordlist;
    int len_wordlist=0;
    while(wordlist_cal!=NULL)
    {
        len_wordlist++;
        wordlist_cal=wordlist_cal->link;
    }
    wordlist_cal=wordlist;
    for(int i=0;i<len_wordlist-1;i++)
    {
        wordlist_cal=wordlist;
        int flag=0;
        for(int j=0;wordlist_cal->link!=NULL;j++)
        {
            if(strcmp(wordlist_cal->a,wordlist_cal->link->a)>0)
            {
                int p=wordlist_cal->b;
                char q[32];
                strcpy(q,wordlist_cal->a);
                strcpy(wordlist_cal->a,wordlist_cal->link->a);
                wordlist_cal->b=wordlist_cal->link->b;
                wordlist_cal->link->b=p;
                strcpy(wordlist_cal->link->a,q);
                flag=1;
            }
            wordlist_cal=wordlist_cal->link;
        }
        if(0==flag)
        break;
    }
    wordlist_cal=wordlist;
    for(int i=0;i<len_wordlist;i++)
    {
        printf("%s %d\n",wordlist_cal->a,wordlist_cal->b);
        wordlist_cal=wordlist_cal->link;
    }
    return 0;
}