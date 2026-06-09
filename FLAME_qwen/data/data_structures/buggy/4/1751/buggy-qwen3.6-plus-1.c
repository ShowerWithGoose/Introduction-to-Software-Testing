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
    in=fopen("article.txt","r");
    wordlist=(struct wordlist *)malloc(sizeof(struct wordlist));
    wordlist_cal=wordlist;
    wordlist_cal->link=NULL;
    for(int i=0;fgets(b,1024,in)!=NULL;i++) // @@ Declaring loop variable 'i' inside the for-loop initializer is a C99 feature and may cause a compilation error in strict C89/C90 environments; additionally, 'i' is unused.
    {
        puts(b); // @@ Outputs the raw line read from the file, which violates the problem's output format requirement of only printing word frequencies.
        int len_b=strlen(b);
        for(int j=0;j<len_b;j++) // @@ Declaring loop variable 'j' inside the for-loop initializer may cause a compilation error in strict C89/C90 environments.
        {
            if(b[j]<='Z'&&b[j]>='A')
            {
                b[j]=(b[j]-'A'+'a');
            }
        }
        for(int j=0,k=0;j<len_b;j++) // @@ Declaring loop variables 'j' and 'k' inside the for-loop initializer may cause a compilation error in strict C89/C90 environments.
        {
            if(b[j]<='z'&&b[j]>='a')
            {
                a[k++]=b[j];
            }
            if(!(b[j]>='a'&&b[j]<='z')&&a[1]!='\0') // @@ Checks a[1] instead of a[0] or k>0, which incorrectly ignores single-letter words and may lead to logical errors when processing words.
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
                    if(wordlist->b==0) // @@ wordlist->b is uninitialized after malloc, leading to undefined behavior; it should be explicitly initialized to 0 before use.
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
    for(int i=0;i<len_wordlist-1;i++) // @@ Declaring loop variable 'i' inside the for-loop initializer may cause a compilation error in strict C89/C90 environments.
    {
        wordlist_cal=wordlist;
        int flag=0;
        for(int j=0;wordlist_cal->link!=NULL;j++) // @@ Declaring loop variable 'j' inside the for-loop initializer may cause a compilation error in strict C89/C90 environments.
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
    for(int i=0;i<len_wordlist;i++) // @@ Declaring loop variable 'i' inside the for-loop initializer may cause a compilation error in strict C89/C90 environments.
    {
        printf("%s %d\n",wordlist_cal->a,wordlist_cal->b);
        wordlist_cal=wordlist_cal->link;
    }
    return 0;
}