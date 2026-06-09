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
        if(n==1)
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
                run1->s [i]=c1;
                i++;
            }
            else
            {
                i=0;
                danci *newd=(danci *)malloc(sizeof(danci));
                newd->s [i]=c1;
                newd->num =1; 
                run1->next =newd;
                run1=newd;
                i++;
            }
        }
        c2=c1;
        n++;
        
    }//所有单词整理完毕 @@ [The loop does not null-terminate the string `s` after reading a word, leading to undefined behavior when using `strcmp`. Also, the logic for word separation is flawed because it doesn't reset `i` properly when starting a new word after non-alphabetic characters.]

    danci *run2= head;//前一位 
    danci *run3= (head->next );
    run1=(head->next );
    n=0;
    while(run1!=NULL) //定点 
    {
        while(run3!=NULL)//跑点 
        {
            n= strcmp(run1->s , run3->s );
            if(n==0 ) 
            {
                (run1->num )+=1;
                run2->next =(run3->next);
                run3=run3->next ;
                continue;
            }
            run2=run3;
            run3=(run3->next );
            
        }
        run2=head;
        run3=head->next ;
        run1=(run1->next );
    }//计算完毕 @@ [This deduplication logic is incorrect: it modifies the list structure while iterating and double-counts words. It also fails to handle lexicographical ordering as required.]

    run1=(head->next ) ;
    while(run1!=NULL)
    {
        printf("%s %d\n",run1->s ,run1->num );
        run1=run1->next ;
    }
    
    return 0;
    
}