#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char ans[50];
    int num;
    struct node *next;
} phrase;
struct node *first=NULL,*p,*q,*ptr;
int i,j,k,flag;
char s[500],mid[50];
void low();
void make();
void sort();
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    while(fgets(s,500,in)!=NULL)
    {
        low();
        make();
    }
    sort();//ÅÅÐò
    for(p=first; p!=NULL; p=p->next)
        printf("%s %d\n",p->ans,p->num);
    fclose(in);
    return 0;
}
void low()
{
    for(j=0; s[j]!='\0'; j++)
    {
        if(s[j]>='A'&&s[j]<='Z')
            s[j]+='a'-'A';
    }
}

void make()
{
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            flag=0;
            for(j=0; s[i]>='a'&&s[i]<='z'; j++,i++)
                mid[j]=s[i];
            mid[j]='\0';
            for(ptr=first; ptr!=NULL; ptr=ptr->next)
            {
                if(strcmp(mid,ptr->ans)==0)
                {
                    ptr->num++;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                q=(struct node*)malloc(sizeof(phrase));
                strcpy(q->ans,mid);
                q->num=1;
                q->next=NULL;
                if(first==NULL)
                    first=p=q;
                else
                {
                    p->next=q;
                    p=p->next;
                }
            }
        }
    }
}

void sort()
{
    char a[50];
    int b;
    for(p=first; p!=NULL; p=p->next)
    {
        for(q=p; q!=NULL; q=q->next)
        {
            if(strcmp(p->ans,q->ans)>0)
            {
                strcpy(a,p->ans);
                strcpy(p->ans,q->ans);
                strcpy(q->ans,a);
                b=p->num;
                p->num=q->num;
                q->num=b;
            }
        }
    }
}



