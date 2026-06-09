#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct listnumber{
int x;
int y;
struct listnumber *link;
} *plist,LIST;
int main()
{
    plist listc=NULL,listb=NULL,lista=NULL,pa,ra,pb,rb,pc,rc,p;
    int x,y;
    char a;
while(1)
    {
        scanf("%d%d",&x,&y);
    pa=(plist)malloc(sizeof(LIST));
    pa->x=x;
    pa->y=y;
    if(lista==NULL)
        lista=pa;
        else
        ra->link=pa;
        ra=pa;
         scanf("%c",&a);
          if(a=='\n')
            break;
}
pa->link=NULL;
pa=lista;
while(1)
    {
        scanf("%d%d",&x,&y);
    pb=(plist)malloc(sizeof(LIST));
    pb->x=x;
    pb->y=y;
    if(listb==NULL)
        listb=pb;
        else
        rb->link=pb;
        rb=pb;
        scanf("%c",&a);
        if(a=='\n')
        break;
}
pb->link=NULL;
pb=listb;
while(pb!=NULL)
{
    pa=lista;
    if(listc==NULL)
    {
        while(pa!=NULL)
        {
         pc=(plist)malloc(sizeof(LIST));
         pc->x=(pa->x)*(pb->x);
         pc->y=(pa->y)+(pb->y);
         if(listc==NULL)
        listc=pc;
         else
        rc->link=pc;
        rc=pc;
        pa=pa->link;
        }
    pc->link=NULL;
    pc=listc;
    }
    else
    {
        pc=listc;
        rc=pc;
        while(pa!=NULL&&pc!=NULL)
        {
            if((pa->y+pb->y)==(pc->y))
            {
                if( pc->x+((pa->x)*(pb->x))==0)
                {
                    rc->link=pc->link;
                    pc=rc->link;
                    pa=pa->link;
                }
                else
                {
                    pc->x=pc->x+((pa->x)*(pb->x));
                    rc=pc;
                    pc=pc->link;
                    pa=pa->link;
                }
            }
            else if((pa->y+pb->y)<pc->y)
            {
                rc=pc;
                pc=pc->link;
            }
            else
            {
                p=(plist)malloc(sizeof(LIST));
                p->y=(pa->y)+(pb->y);
                p->x=(pa->x)*(pb->x);
                rc->link=p;
                p->link=pc;
                rc=p;
                pa=pa->link;
            }
        }
        while(pa!=NULL)
        {
         p=(plist)malloc(sizeof(LIST));
         p->x=(pa->x)*(pb->x);
         p->y=(pa->y)+(pb->y);
        rc->link=p;
        rc=p;
        pa=pa->link;
        }
        rc->link=NULL;
    }
    rb=pb;
    pb=pb->link;
    free(rb);
}
pa=lista;
while(pa!=NULL)
{
    ra=pa;
    pa=pa->link;
    free(ra);
}
pc=listc;
while(pc!=NULL)
{
    printf("%d %d ",pc->x,pc->y);
    rc=pc;
    pc=pc->link;
    free(rc);
}
  return 0;
}

