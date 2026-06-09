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
    wordlist->b = 0; // @@ Initialize the count of the dummy/head node to 0 to distinguish it from valid words
    for(int i=0;fgets(b,1024,in)!=NULL;i++)
    {
        // puts(b); // @@ Remove debug output that prints the raw line, as it violates the output format
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
            // The condition a[1]!='\0' is incorrect for checking if a word has been formed. 
            // It fails for single-letter words (where k=1, so a[0] is set, but a[1] is '\0') 
            // and might behave unpredictably if a[0] is not null. 
            // It should check if k > 0, meaning at least one character has been accumulated in 'a'.
            if(!(b[j]>='a'&&b[j]<='z') && k > 0) // @@ Correct the condition to check if a word buffer 'a' is non-empty (k>0) instead of checking a[1]
            {
                wordlist_cal=wordlist;
                int flag=0;
                while(wordlist_cal!=NULL)
                {
                    // If we are using a head node that might be uninitialized or a dummy, 
                    // we must ensure we don't compare against garbage if b==0 and it's the initial state.
                    // However, since we initialized wordlist->b=0 above, and valid words have b>=1,
                    // strcmp on an empty string "" vs a real word will just fail to match, which is fine.
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
                    // The original logic checks if wordlist->b==0 to decide whether to overwrite the head node.
                    // This implies the head node is used as the first storage slot if it's "empty".
                    if(wordlist->b==0)
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
        // If the head node was used as a valid word slot, it will be printed.
        // If the list was empty, len_wordlist is 1 (the dummy head with b=0).
        // We should probably skip printing if b==0 and it's the only node or if it's a dummy.
        // However, given the structure, if no words were found, it prints "" 0. 
        // The problem guarantees input, so this edge case might not be tested, 
        // but strictly speaking, we should ensure we don't print the dummy if it wasn't overwritten.
        // But looking at the logic: if words exist, head is either overwritten (b>=1) or new nodes added.
        // If head was overwritten, it's a valid word. If not, head has b=0.
        // The sorting and printing loop includes the head.
        // If the head has b=0, it means no words were inserted into the head slot.
        // This happens if at least one word was inserted via the `else` branch (appending).
        // In that case, the head node still contains garbage or empty string with count 0.
        // We should skip printing nodes with count 0 if they are essentially dummies.
        // However, a simpler fix for the specific "Wrong Answer" regarding "iwill" vs "i" and "will"
        // was the parsing logic. The printing of a potential dummy node with 0 count 
        // would result in an extra line like " 0" or similar if a[0] is null.
        // Let's assume the parsing fix resolves the main issue. 
        // To be safe, we can check if b > 0 before printing.
        if (wordlist_cal->b > 0) { // @@ Only print words that have a positive count to avoid printing uninitialized/dummy nodes
            printf("%s %d\n",wordlist_cal->a,wordlist_cal->b);
        }
        wordlist_cal=wordlist_cal->link;
    }
    return 0;
}