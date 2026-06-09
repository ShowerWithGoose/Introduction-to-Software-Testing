#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct LLine
{
    int x1_max,y1_max;
    int p2x,p2y;
    int num;
    struct LLine *next;
    int sw;
}lLine;

struct SLine
{
    int a,b,c,d;
    int record;
}p[150];

void apply(struct SLine *ssl,lLine *pp)
{
    lLine *p;
    p =(lLine *)malloc(sizeof(lLine));
    pp->next = p;
    p->x1_max = ssl->a;
    p->y1_max = ssl->b;
    p->p2x = ssl->c;
    p->p2y = ssl->d;
    p->num = 1;
    p->sw = 0;
    p->next = NULL;
}

void delNext(lLine *p)
{
    lLine *pp;
    pp = p->next;
    p->next = p->next->next;
    free(pp);
}

int cmpsecond(lLine *LinelistHead,lLine *pp)
{
    lLine *p,*tempp;
    p = LinelistHead;
    while(p->next!=NULL)
    {
        tempp =p;
        p = p->next;
        if(p->x1_max==pp->x1_max&&p->y1_max==pp->y1_max&&p != pp&&pp->sw != 1&&p->sw!=1)
        {
            pp->num =pp->num  +p->num;
            pp->x1_max = p->p2x;
            pp->y1_max = p->p2y;
            //delNext(tempp);
            //printf("1111\n");
            p->sw = 1;
            return 1;
        }
        else if(p->x1_max==pp->p2x&&p->y1_max==pp->p2y&&p != pp&&pp->sw != 1&&p->sw!=1)
        {
            pp->num =pp->num  +p->num;
            pp->p2x=p->p2x;
            pp->p2y=p->p2y;
            p->sw = 1;
            //printf("2111\n");
            //delNext(tempp);
            return 1;
        }
        else if(p->p2x==pp->x1_max&&p->p2y==pp->y1_max&&p != pp&&pp->sw != 1&&p->sw!=1)
        {
            pp->num =pp->num + p->num;
            pp->x1_max = p->x1_max;
            pp->y1_max = p->y1_max;
            p->sw = 1;
            //delNext(tempp);
                        //printf("3111\n");
            return 1;
        }
        else if(p->p2x==pp->p2x&&p->p2y==pp->p2y&&p != pp&&pp->sw != 1&&p->sw!=1)
        {
            pp->num =pp->num +p->num;
            pp->p2x = p->x1_max;
            pp->p2y = p->y1_max;
            p->sw = 1;
                        //printf("4111\n");
            //delNext(tempp);
            return 1;
        }
    }
        if(p->next==NULL)
    {
        return 0;
    }

}

int cmpfirst(lLine *LinelistHead,int a,int b,int c,int d)
{
    lLine *p,*pp;
    p = LinelistHead;
    while(p->next!=NULL)
    {
        p = p->next;
        if(p->x1_max==a&&p->y1_max==b)
        {
            p->num++;
            p->x1_max = c;
            p->y1_max = d;
            return 1;
        }
        else if(p->x1_max==c&&p->y1_max==d)
        {
            p->num++;
            p->x1_max = a;
            p->y1_max = b;
            return 1;
        }
        else if(p->p2x==a&&p->p2y==b)
        {
            p->num++;
            p->p2x = c;
            p->p2y = d;
            return 1;
        }
        else if(p->p2x==c&&p->p2y==d)
        {
            p->num++;
            p->p2x = a;
            p->p2y = b;
            return 1;
        }
    }
    if(p->next==NULL)
    {
        return 0;
    }
}

int main()
{
    int n,count,temp,swi,maxLineNum = 0,tempa,tempb;
    lLine *LinelistHead,*p1,*p2,*rem;
    struct SLine *PPP;
    int i = 0,j,k = 1;
    scanf("%d",&n);
    LinelistHead = (lLine *)malloc(sizeof(lLine));
    for(i = 1;i <= n;i++)
    {
        scanf("%d%d%d%d",&p[i].a,&p[i].b,&p[i].c,&p[i].d);
        p[i].record = 0;
    }
    LinelistHead->next = NULL;
    PPP = &p[1];
   // printf("PPP->a:%d\n",PPP->a);
    apply(PPP,LinelistHead);
    //
    //p2 = head->next;
    //printf("??\n");
    //printf("test0:%d %d %d %d num:%d\n",p2->p1x,p2->p1y,p2->p2x,p2->p2y,p2->num);
    //printf("!!\n");
    //
    temp = -1;
    for(i = 2;i <= n;i++)
    {
        temp = cmpfirst(LinelistHead,p[i].a,p[i].b,p[i].c,p[i].d);
        if(temp == 1)
        {
            //printf("i:%d  temp:%d\n",i,temp);
            temp = -1;
            continue;
        }
        else if(temp == 0)
        {
            //printf("i:%d  temp:%d\n",i,temp);
            p1 = LinelistHead;
            temp = -1;
            while(p1->next!=NULL)
            {
                p1=p1->next;
            }
            PPP = &p[i];
            apply(PPP,p1);
        }
        else if(temp == -1)
        {
            //printf("error!\n");
            //printf("i:%d  temp:%d",i,temp);
        }
    }
    /*

    p2 = head;
    while(p2->next!=NULL)
    {
        p2 = p2->next;
        //printf("test1:%d %d %d %d num:%d\n",p2->p1x,p2->p1y,p2->p2x,p2->p2y,p2->num);
    }





    */
    p2 = LinelistHead;
    temp =0;
    while(p2->next!=NULL)
    {
        p2 = p2->next;
        temp = 0;
        //printf("??\n");
        if(p2->sw == 1)
        {
            continue;
        }
        while(cmpsecond(LinelistHead,p2) == 1)
        {
            //printf("success!\n");
        }
    }
    /*
    p2 = head;
    while(p2->next!=NULL)
    {
        p2 = p2->next;
        if(p2->sw != 1)
        printf("test2:%d %d %d %d num:%d\n",p2->p1x,p2->p1y,p2->p2x,p2->p2y,p2->num);
    }
    */
    p2 = LinelistHead;
    while(p2->next != NULL)
    {
        p2 = p2->next;
        if(p2->num > maxLineNum)
        {
            maxLineNum = p2->num;
        }
    }
    p2 = LinelistHead;
    while(p2->next != NULL)
    {
        p2 = p2->next;
        if(p2->num == maxLineNum)
        {
            if(p2->x1_max<=p2->p2x)
            {
                printf("%d %d %d",p2->num,p2->x1_max,p2->y1_max);
            }
            else
            {
                printf("%d %d %d",p2->num,p1->x1_max,p1->y1_max);
            }

            break;
        }
    }
    p2 = LinelistHead;
    while(p2->next!=NULL)
    {
        p1 = p2;
        p2 = p2->next;
        free(p1);
    }
    free(p2);
    return 0;
}

