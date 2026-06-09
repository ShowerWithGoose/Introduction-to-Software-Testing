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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent operations (like fgets) will cause undefined behavior. The program should check if 'in' is NULL and handle the error appropriately.]
    wordlist=(struct wordlist *)malloc(sizeof(struct wordlist)); // @@ [If malloc fails (returns NULL), dereferencing wordlist leads to undefined behavior. Also, the initial node is allocated but never initialized properly (e.g., b is uninitialized).]
    wordlist_cal=wordlist;
    wordlist_cal->link=NULL;
    for(int i=0;fgets(b,1024,in)!=NULL;i++) // @@ [If 'in' is NULL (file open failed), fgets causes undefined behavior. Additionally, the loop condition does not guard against read errors or EOF correctly in all edge cases.]
    {
        puts(b); // @@ [This prints the raw input line to stdout, which violates the output format specification (only word counts in lex order should be printed).]
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
            if(!(b[j]>='a'&&b[j]<='z')&&a[1]!='\0') // @@ [The condition 'a[1]!='\0'' is incorrect for detecting non-empty words. A single-letter word like "a" would have a[0]='a', a[1]='\0', so this condition fails to process it. Should check k>0 or a[0]!='\0'.]
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
                    if(wordlist->b==0) // @@ [Relies on uninitialized value: wordlist->b was never set to 0 after malloc. This leads to undefined behavior.]
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