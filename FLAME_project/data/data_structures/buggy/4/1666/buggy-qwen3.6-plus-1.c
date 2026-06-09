#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct str1
{
    char s[50];
    int con;
    struct str1* link;
} WORD;
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char s1[10005];
    char c[50];
    WORD *list,*p=NULL,*q=NULL,*p1=NULL;
    list=NULL;
    int i,k,n,save;
    while(fgets(s1,10005,in)!=NULL)
    {
        n=strlen(s1);
        for(i=0,k=0; i<=n; i++)
        {
            if(s1[i]<'a'||s1[i]>'z')
            {
                if(s1[i]>='A'&&s1[i]<='Z')
                {
                    c[k++]=s1[i]-'A'+'a';
                }
                else
                {
                    c[k]='\0';
                    if(k>0)
                    {
                        if(list==NULL)
                        {
                            list=(WORD*)malloc(sizeof(WORD));
                            list->link=NULL;
                            strcpy(list->s,c);
                            list->con=1;
                        }
                        else
                        {
                            p=list;
                            p1=NULL;
                            while(p!=NULL)
                            {
                                save=strcmp(p->s,c);
                                printf("%d ",save); // @@ [This debug print statement outputs intermediate comparison results to stdout, corrupting the expected output format which should only contain word counts.]
                                if(save<0)
                                {
                                    p1=p;
                                    p=p->link;
                                }
                                else if(save==0)
                                {
                                    p1=p;
                                    p->con++;

                                    break;
                                }
                                else
                                {
                                    q=(WORD*)malloc(sizeof(WORD));
                                    strcpy(q->s,c);
                                    q->con=1;
                                    q->link=p;
                                    if(p!=list)
                                    {
                                        p1->link=q;
                                    }
                                    else
                                    {
                                        list=q;
                                    }
                                    p1=q;
                                    break;
                                }
                            }
                            if(p==NULL)
                            {
                                q=(WORD*)malloc(sizeof(WORD));
                                strcpy(q->s,c);
                                q->con=1;
                                p1->link=q;
                                q->link=NULL;
                            }
                        }
                    }
                    k=0;
                }
            }
            else
            {
                c[k++]=s1[i];
            }
        }
    }
    p=list;
    while(p!=NULL)
    {
        printf("%s %d\n",p->s,p->con);
        p=p->link;
    }
    return 0;
}