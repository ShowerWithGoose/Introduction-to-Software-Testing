#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char word[32];
    int num;
    struct node *next;
}node,*ptr;


char s[256]="";
int main(){
    freopen("article.txt","r",stdin);
    ptr head,p,pp,temp;
    head=pp=p=NULL;
out:
    while ((gets(s)!=NULL))
    {
        for (size_t i = 0; i < strlen(s); i++)
        {
            s[i]=tolower(s[i]);
        }
        
        int i=0,j;
        while (s[i]!='\0')
        {
            for (; !isalpha(s[i]); i++){
                if (s[i]=='\0')
                {
                    goto out;
                }
            };   
            temp=(ptr)malloc(sizeof(node));
            memset(temp,0,sizeof(node));
            for (j=0; isalpha(s[i]); i++)
            {
                temp->word[j++]=s[i];
            }
            if (head==NULL)
            {
                p=head=temp;
                p->num++;
                p->next=NULL;
            }else{
                for ( pp=p=head; p!=NULL; pp=p,p=p->next)
                {
                    if (strcmp(temp->word,p->word)==0)
                    {
                        p->num++;
                        break;
                    }else if (strcmp(temp->word,p->word)<0)
                    {
                        if (p==head)
                        {
                            temp->next=p;
                            head=p=temp;
                            p->num++;
                            break;
                        }else{
                            pp->next=temp;
                            temp->next=p;
                            p=temp;
                            p->num++;
                            break;
                        }
                    }
                }
                if (p==NULL)
                {
                    p=temp;
                    pp->next=p;
                    p->num++;
                    p->next=NULL;
                }
                
            }        
        }
    }
    for ( p = head; p!=NULL; p=p->next)
    {
        printf("%s %d\n",p->word,p->num);
    }
    return 0;
}
