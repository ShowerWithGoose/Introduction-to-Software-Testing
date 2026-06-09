#include<stdio.h>
#include<math.h>
#include<string.h> 
#include<stdlib.h>
#define oso 1e-12
#include<ctype.h>
struct lb
{
    char wd[200];
    int cnt;
    struct lb *link;    
}; 
typedef struct lb lb1;
typedef struct lb *lbp;
char s[2000],s0[2000];
int main()
{
    int a,b,d,e,g,h,e0,flag=0,flag1,flag2,i,m,n,j,ou;
    FILE *in;
    in=fopen("article.txt","r");
    char c;
    lbp p=NULL,q=NULL,list=NULL,t=NULL,k=NULL,list2=NULL,list3=NULL,x=NULL,y=NULL;
    i=0;
    while(fscanf(in,"%s",s)!=EOF) // @@ [Error: fscanf reads tokens separated by whitespace only, but words may be separated by punctuation (e.g., "hello,world"). Should read line by line with fgets() and parse characters to correctly extract all words.]
    {
        for(ou=0;ou<strlen(s);ou++) // @@ [Error: The loop condition uses strlen(s) which changes as s is modified, causing early exit and missing characters after the first non-letter. Also, replacing non‑letters with '\0' truncates the string, losing all subsequent letters in the token. Proper word extraction requires iterating over characters and building words individually.]
        {
            if(isupper(s[ou]))
                s[ou]=tolower(s[ou]);
            else if((!isupper(s[ou]))&&(!islower(s[ou])))
                s[ou]='\0'; // @@ [Error: Setting a non‑letter to '\0' truncates the string at this position. For example, "hello123world" becomes "\0" after the first non‑letter? Actually, it becomes "hello\0", and "world" is lost. Moreover, the loop may exit prematurely because strlen decreases. Should instead split the token into separate words.]
        }
        if(i==0)
        {
            q=(lbp)malloc(sizeof(lb1));
            q->link=NULL;
            q->cnt=1;
            strcpy(q->wd,s);
            list=q;
            p=q;
        }
        else
        {
            for(t=list;t!=NULL;t=t->link)
            {
                if(strcmp(t->wd,s)==0)
                {
                    t->cnt+=1;
                    goto A;
                }
            }
            if(t!=NULL)
            {
                continue;
            }
            else
            {
                if(strcmp(s,list->wd)<0)
                {
                    q=(lbp)malloc(sizeof(lb1));
                    q->cnt=1;
                    q->link=NULL;
                    strcpy(q->wd,s);    
                    q->link=list;    
                    list=q;    
                    goto A;        
                }
                else
                {
                    flag=0;
                    for(t=list;t->link!=NULL;t=t->link)
                    {
                        if(strcmp(s,t->link->wd)<0)
                        {
                            q=(lbp)malloc(sizeof(lb1));
                            q->cnt=1;
                            q->link=NULL;
                            strcpy(q->wd,s);    
                            q->link=t->link;
                            t->link=q;            
                            flag=1;
                            break;                
                        }
                    }
                    if(flag==0)
                    {
                        q=(lbp)malloc(sizeof(lb1));
                        q->cnt=1;
                        q->link=NULL;
                        strcpy(q->wd,s);        
                        p->link=q;
                        p=p->link;                    
                    }
                }
            }
        }
        A:i++;        
    }
    for(p=list;p!=NULL;p=p->link)
    {
        printf("%s %d\n",p->wd,p->cnt);
    }
    fclose(in);
    return 0;
 }