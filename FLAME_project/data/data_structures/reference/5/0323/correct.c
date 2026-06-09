#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct duoxiangshi
{
    int a;
    int b;
};
int cmp(const void*a,const void*b)
{
	struct duoxiangshi *aa=(struct duoxiangshi*)a;
	struct duoxiangshi *bb=(struct duoxiangshi*)b;
	if( (*aa).b < (*bb).b )
     return 1;
    else
        return -1;
}
struct node
{
    int xs;
    int zs;
    struct node *link;
};
struct node* creatlist()
{
    int n1,n2,cnt=1;
    char s[100];
    gets(s);
    int len=strlen(s);
    int num[100]={};
    for (int i=0;i<len;i++)
    {
        while(isdigit(s[i]))
        {
            num[cnt]=num[cnt]*10+s[i]-'0';
            i++;
        }
        cnt++;
    }
    struct node *head=NULL,*p,*q;
    for(int i=1;i<cnt;i+=2)
    {
        q=(struct node*)malloc(sizeof(struct node));
        q->xs=num[i];
        q->zs=num[i+1];
        q->link=NULL;
        if(head==NULL)
            head=p=q;
        else
        {
            p->link=q;
            p=p->link;
        } 
    }
    q=(struct node*)malloc(sizeof(struct node));
    q->xs=n1;
    q->zs=n2;
    q->link=NULL;
    p->link=q;
    p=p->link;
    return head;
}
int main()
{
    int i=0;
    struct duoxiangshi d[1000];
    struct node *head1,*head2;
    head1=creatlist();
    head2=creatlist();
    struct node *p,*q;
    for(p=head1;p!=NULL;p=p->link,i++)
    {   for (q=head2;q!=NULL;q=q->link,i++)
        {
            d[i].a=p->xs*q->xs;
            d[i].b=p->zs+q->zs;
        }
    }
    int cnt=i;
    for (int i=0;i<cnt;i++)
    {
        for (int j=i+1;j<=cnt;j++)
        {
            if(d[i].b==d[j].b)
            {
                d[j].a+=d[i].a;
                for (int k=i;k<=cnt;k++)
                {
                    d[k].a=d[k+1].a;
                    d[k].b=d[k+1].b;
                }
                cnt--;
                i--;
            }
        }
    }
    qsort(d,cnt,sizeof(d[0]),cmp);
    for (int i=0;i<=cnt;i++)
    {   if(d[i].a!=0)        
            printf("%d %d ",d[i].a,d[i].b);}
    return 0;
}


