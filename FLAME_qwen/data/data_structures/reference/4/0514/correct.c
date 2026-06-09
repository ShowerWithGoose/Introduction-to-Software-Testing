#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct elem
{
    char word[25];
    int hash;
    struct elem *link;
}elem, *LinkList;

int tolower(char a)
{
    if((a>='A')&&(a<='Z'))
    {
        return (a-('A'-'a'));
    }
    else
        return a;
}

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");

    char word[505][25], c;

    int i=0, j=0;

    LinkList p, q=NULL, r=NULL, list=NULL, temp, t=NULL;


    while((c=fgetc(in))!=EOF)
    {
        c = tolower(c);
        if((c>='a')&&(c<='z'))
        {
            word[i][j]=c;
            j++;
        }
        else
        {
            word[i][j]='\0';
            i++;
            j=0;
        }
    }

    /*for (j=0; j<=i; j++)
    {
        if((word[j][0]==' ')||(word[j][0]=='\n')||(word[j][0]=='\0'))
            j++;
        puts(word[j]);
    }*/

    for (j=0; j<i; j++)
    {
        p = (LinkList)malloc(sizeof(elem));
        if(word[j][0]=='\0')
            continue;
        strcpy(p->word, word[j]);
        p->hash = 1;
        p->link = NULL;
        //printf("insert:%s\n", p->word);
        while(q!=NULL)
        {
            //puts(q->word);
            //printf("%d\n", strcmp(p->word, q->word));
            if(strcmp(p->word, q->word)<0)
            {
                if (q==list)
                {
                    list = p;
                    p->link = q;
                }
                else
                {
                    p->link = t->link ;
                    t->link = p;
                }
                temp = q;
                q = p;
                p->link = temp;
                break;
            }
            else if(strcmp(p->word, q->word)==0)
            {
                q->hash++;
                q = list;
                break;
            }
            t = q;
            q = q->link;
        }
        if(q==NULL)
        {
            if(list==NULL)
            {
                list = p;
            }
            else
            {
                r->link = p;
            }
            r = p;
        }
        q = list;

        /*t = list;
        while (t!=NULL)
        {
            printf("%s %d\n", t->word, t->hash);
            t = t->link;
            printf("\n");
        }*/
    }

    while(q!=NULL)
    {
        printf("%s %d\n", q->word, q->hash);
        q = q->link;
    }

    fclose(in);
    return 0;
}





