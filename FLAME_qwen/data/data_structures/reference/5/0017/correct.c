#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int di;
    int jie;
    struct node *link;
} *shi,Node;


int main()
{
    shi list1,x1,y1,list2,x2,y2,list3,x3,y3;
    int r;
    list1=NULL;
    char c;
    while(1)
    {
        y1=(shi)malloc(sizeof(Node));
        scanf("%d %d%c",&y1->di,&y1->jie,&c);
        y1->link=NULL;
        if(list1==NULL)
            list1=x1=y1;
        else
            x1->link=y1;
        x1=y1;
        if (c == '\n')
        	break;
    }
    list2=NULL;
    c='0';
    while(1)
    {
        y2=(shi)malloc(sizeof(Node));
        scanf("%d %d%c",&y2->di,&y2->jie,&c);
        y2->link=NULL;
        if(list2==NULL)
            list2=x2=y2;
        else
            x2->link=y2;
        x2=y2;
        if(c == '\n')
        	break;
    }
    list3=NULL;
    for(x1=list1;x1!=NULL;x1=x1->link)
    {
        for(x2=list2;x2!=NULL;x2=x2->link)
        {
            y3=(shi)malloc(sizeof(Node));
            y3->di=x1->di * x2->di;
            y3->jie=x1->jie + x2->jie;
            y3->link=NULL;
            if(list3==NULL)
                list3=x3=y3;
            else
                x3->link=y3;
            x3=y3;
        }
    }

    for(x3=list3;x3!=NULL;x3=x3->link)
    {
        for(y3=x3->link;y3!=NULL;y3=y3->link)
        {
            if(y3->jie==x3->jie&&y3->di!=0)
            {
                x3->di=x3->di+y3->di;
                y3->di=0;
            }
        }
    }

    for(x3=list3;x3!=NULL;x3=x3->link)
    {
        for(y3=x3->link;y3!=NULL;y3=y3->link)
        {
            if(y3->jie>x3->jie&&y3->di!=0)
            {
                r=y3->di;
                y3->di=x3->di;
                x3->di=r;

                r=y3->jie;
                y3->jie=x3->jie;
                x3->jie=r;

            }
        }
    }


    for(x3=list3;x3!=NULL;x3=x3->link)
	{
        if(x3->di!=0)
            printf("%d %d ",x3->di,x3->jie);
    }
    return 0;
}

