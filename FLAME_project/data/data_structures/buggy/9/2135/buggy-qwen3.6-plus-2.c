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
    r->next = r->next->next; // @@ [Logical error: This attempts to unlink the node after r from the list, but r itself is not unlinked from the list. Furthermore, if r is the last node, r->next is NULL, causing a segmentation fault when accessing r->next->next. The intention was likely to remove r from the list, which requires updating the previous node's next pointer (q1 in main), not modifying r's internal next pointer in this way.]
    //free(t);
}

int main()
{
    int n;
    int x,y,x1,y1;
    scanf("%d",&n);
    while(n--)
    {
        line c = malloc(sizeof(line)); // @@ [Memory allocation error: sizeof(line) allocates memory for a pointer (typically 4 or 8 bytes), not for the struct xd (which is larger). This leads to heap buffer overflow when writing to c->sx, c->sy, etc., causing runtime errors like "Fatal glibc error". It should be malloc(sizeof(struct xd)) or malloc(sizeof(*c)).]
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