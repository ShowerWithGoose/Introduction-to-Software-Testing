#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
     char danci[30];
     int cs;
     struct node *next;
};
int main()
{
    FILE *pp1;
    int i=0,n=0,j,tempcs;
    struct node *first=NULL,*p1=NULL,*p2=NULL,*p3=NULL;
    char dcb[50]={0},zm,temp[50];
    pp1=fopen("article.txt","r");
    zm=fgetc(pp1);
    while(zm!=EOF)
    {
        if(zm>='A'&&zm<='Z')
        {
            zm='a'+zm-'A';
            dcb[i]=zm;
            i++;
            zm=fgetc(pp1);
        }
        else if(zm>='a'&&zm<='z')
        {
            dcb[i]=zm;
            i++;
            zm=fgetc(pp1);
        }
        else if(dcb[0]!='\0')
        {
            p1=(struct node *)malloc(sizeof(struct node));
            strcpy(p1->danci,dcb);
            p1->cs=1;
            if(first==NULL)
            first=p2=p1;
             else
            {
            p2->next=p1;
            p2=p2->next;
            }
                p2->next=NULL;
                for(i=0;i<50;i++)
                    dcb[i]='\0';
                i=0;
                zm=fgetc(pp1);
        }
        else
            zm=fgetc(pp1);

    }
    for(p1=first;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next,p3=p1;p2!=NULL;)
        {
             if(strcmp(p1->danci,p2->danci)==0)
           {
               p1->cs++;
               p3->next=p2->next;
               p2=p3->next;

           }
           else
           {
               p2=p2->next;
               p3=p3->next;
           }
        }
    }


     for(n=1,p1=first;p1!=NULL;p1=p1->next,n++)
    {

    }
    n--;
    for(i=0;i<n-1;i++)
        for(j=0,p1=first;j<n-i-1;j++,p1=p1->next)
    {
        p2=p1->next;
        if(strcmp(p1->danci,p2->danci)>0)
        {
                strcpy(temp,p1->danci);
                strcpy(p1->danci,p2->danci);
                strcpy(p2->danci,temp);
                tempcs=p1->cs;
                p1->cs=p2->cs;
                p2->cs=tempcs;
        }
    }


    for(p1=first;p1!=NULL;p1=p1->next)
    {
        printf("%s %d\n",p1->danci,p1->cs);
    }
 return 0;
}

