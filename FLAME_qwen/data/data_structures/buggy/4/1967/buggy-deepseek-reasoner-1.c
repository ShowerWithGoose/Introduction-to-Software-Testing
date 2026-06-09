#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct danci
{
    char s[30];
    int num;
    struct danci *next;
} danci;

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char c1,c2;
    int i=0,n=1;
    danci *head=(danci *)malloc(sizeof(danci));
    head->next =NULL;
    danci *run1=head;
    
    while((c1=fgetc(in))!=EOF)
    {
        if(n==1)  // @@ Error: This condition only applies to the first character of the file, causing incorrect handling of words that do not start at the first character. Also, n is never reset, so line breaks and multiple paragraphs are not handled correctly.
        {
            c2=c1;
            if(((c2>=65)&&(c2<=90))||((c2>=97)&&(c2<=122)))
            {
                if((c2>=65)&&(c2<=90))
                {
                    c2=c2+('a'-'A');
                }
                danci *newd=(danci *)malloc(sizeof(danci));
                newd->s[i]=c2;
                i++; 
                newd->num=1;
                run1->next =newd;
                run1=newd;
            }
            n++;
            continue;
        }
        
         if(((c1>=65)&&(c1<=90))||((c1>=97)&&(c1<=122)))
         //本位字母 
        {
            if((c1>=65)&&(c1<=90))//变小写 
            {
                c1=c1+('a'-'A');
            }
            if(((c2>=65)&&(c2<=90))||((c2>=97)&&(c2<=122)))
        //本位字母且上一位字母 
            {
                run1->s [i]=c1;  // @@ Error: Appends character but does not null-terminate the string. The s array will lack a '\0', causing later strcmp to read beyond the intended characters (undefined behavior).
                i++;
            }
            else
            {
                i=0;
                danci *newd=(danci *)malloc(sizeof(danci));
                newd->s [i]=c1;  // @@ Error: Same as above – missing null terminator for the new word's string.
                newd->num =1; 
                run1->next =newd;
                run1=newd;
                i++;
            }
        }
        c2=c1;
        n++;
        
    }//所有单词整理完毕 
    
    danci *run2= head;//前一位 
    danci *run3= (head->next );
    run1=(head->next );
    n=0;
    while(run1!=NULL) //定点 
    {
        while(run3!=NULL)//跑点 
        {
            n= strcmp(run1->s , run3->s );  // @@ Error: Strings s are not null-terminated, so strcmp has undefined behavior (compares garbage after the actual word characters).
            if(n==0 ) 
            {
                (run1->num )+=1;
                run2->next =(run3->next);  // @@ Error: The duplicate node is removed from the linked list but is not freed, causing a memory leak.
                run3=run3->next ;
                continue;
            }
            run2=run3;
            run3=(run3->next );
            
        }
        run2=head;
        run3=head->next ;
        run1=(run1->next );
    }//计算完毕
    run1=(head->next ) ;
    while(run1!=NULL)
    {
        printf("%s %d\n",run1->s ,run1->num );  // @@ Error: Output order is not lexicographic (it follows first occurrence). Also, missing null terminator may cause garbage characters to be printed.
        run1=run1->next ;
    }
    
    return 0;
    
}