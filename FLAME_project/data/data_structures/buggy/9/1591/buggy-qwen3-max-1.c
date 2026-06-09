#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
typedef struct segz                
{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;                    
}seg[105];
int cmpfuc(const void *a, const void *b)            
{                                                
    struct segz *c=(segz *)a; // @@ [Type name 'segz' is not defined as a type; the typedef defines 'seg' as an array type of struct segz, but 'segz' itself is not a typedef'ed type. Should cast to 'struct segz *' without using 'segz' as a type.]
    struct segz *d=(segz *)b; // @@ [Same error: 'segz' is not a valid type name for casting. The correct cast is '(struct segz *)'.]
    if(c->x1!=d->x1) return d->x1-c->x1;
    else return d->y1-c->y1;
}
int main()
{
    struct segz seg[105];
    int n;
    scanf("%d",&n);                                    
    int i,j;
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d",&seg[i].x1,&seg[i].y1,&seg[i].x2,&seg[i].y2),seg[i].num = 1;

    qsort(seg,n,sizeof(seg[0]),cmpfuc);                

    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n-1; j++)                
        {                                        
            if(seg[i].x1==seg[j+1].x2&&seg[i].y1==seg[j+1].y2)
            {
                seg[j+1].num += seg[i].num;
            }
        }
    }
    int max=-1,flag=0;
    for(i=0;i<n;i++)
    {
        if(seg[i].num>max)
            max=seg[i].num,flag = i;                
    }
    printf("%d %d %d",max,seg[flag].x1,seg[flag].y1);        
    return 0;
}