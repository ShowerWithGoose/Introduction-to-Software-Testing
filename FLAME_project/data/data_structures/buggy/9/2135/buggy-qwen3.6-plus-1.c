#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct xd
{
    int sx;
    int sy;
    int ex;
    int ey;
    int co;
    struct xd *next;
}*line;
line head = NULL,p,q;

int insert(line c,line q)
{
    c->co = 1;
    if(head == NULL)
        head = p = c;
    else if(q == NULL)
    {
        c->next = head;
        head = c;
    }
    else
    {
        c->next = q->next;
        q->next = c;
    }
    return 0;
}

int search(line c)
{
    line p,q = NULL;
    for(p = head;p!=NULL;q=p,p=p->next) //q暂存进行下一步之前的p；若比较成功，则q为最后一次strcmp>0的位置
    {
        if(c->sx == p->ex && c->sy == p->ey) //待插入之首等于已有之末
        {
            p->ex = c->ex;
            p->ey = c->ey;
            p->co++;
            return 0;
        }
        else if(c->ex == p->sx && c->ey == p->sy)//待插入之末等于已有之首
        {
            p->sx = c->sx;
            p->sy = c->sy;
            p->co++;
            return 0;
        }
    }
    return insert(c,q);
}

void merge(line p,line r,int sx,int sy,int ex,int ey)
{
    p->co += r->co;
    p->sx = sx;
    p->sy = sy;
    p->ex = ex;
    p->ey = ey;
    line t = r->next;
    r->next = r->next->next; // @@ [Logical error: This attempts to skip the node after r in the list, but r is being merged into p and should be removed from the list entirely. Furthermore, if r->next is NULL, accessing r->next->next causes a segmentation fault (Runtime Error). The correct logic should remove r from the linked list, e.g., by updating the previous node's next pointer.]
    //free(t);
}

int main()
{
    int n;
    int x,y,x1,y1;
    scanf("%d",&n);
    while(n--)
    {
        line c = malloc(sizeof(line)); // @@ [Semantic error: malloc(sizeof(line)) allocates memory for a pointer (4 or 8 bytes), not for the struct xd. This leads to heap buffer overflow when writing to struct members, causing undefined behavior or runtime errors. It should be malloc(sizeof(struct xd)) or malloc(sizeof(*c)).]
        c->next = NULL;
        scanf("%d %d %d %d",&c->sx,&c->sy,&c->ex,&c->ey);
        //printf("%d %d %d %d\n",c->sx,c->sy,c->ex,c->ey);
        search(c);
    }
    
    while(1)
    {
        line p =head,q1=p;
        int flag=0;
        for(line r = p->next;r!=NULL;q1=r,r=r->next)
        {
            if(r->sx == p->ex && r->sy == p->ey) //待插入之首等于已有之末
            {
                merge(p,q1,p->sx,p->sy,r->ex,r->ey);
                flag = 1;
            }
            else if(r->ex == p->sx && r->ey == p->sy)//待插入之末等于已有之首
            {
                merge(p,q1,r->sx,r->sy,p->ex,p->ey);
                flag=1;
            }
        }
        if(!flag)
                break;
    }
    q = NULL;
    int max = 0;
    for(line p = head;p!=NULL;q=p,p=p->next)
    {
        if(p->co >= max)
        max = p->co;
    }
    for(line p = head;p!=NULL;q=p,p=p->next)
    {
        if(p->co == max)
        {
            printf("%d %d %d\n",p->co,p->sx,p->sy);
            break;
        }
    }
    return 0;


}