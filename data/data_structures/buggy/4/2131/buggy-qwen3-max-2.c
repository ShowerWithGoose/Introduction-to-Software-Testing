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
    while(fscanf(in,"%s",s)!=EOF)
    {
        for(ou=0;ou<strlen(s);ou++)
        {
            if(isupper(s[ou]))
                s[ou]=tolower(s[ou]);
            else if((!isupper(s[ou]))&&(!islower(s[ou])))
                s[ou]='\0'; // @@ [This truncates the string at the first non-letter character, but leaves the rest of the string intact. Subsequent letters after a non-letter are not processed as separate words, violating the problem's word definition.]
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
            if(t!=NULL) // @@ [This condition is always false because the loop exits when t becomes NULL. Thus, this block is unreachable and logically incorrect.]
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