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
}seg[105]; // @@ [The typedef defines 'seg' as an array type of 105 'struct segz', but later in main(), 'seg' is redeclared as a variable name, causing a naming conflict and compilation error.]
int cmpfuc(const void *a, const void *b)            
{                                                
    struct segz *c=(segz *)a; // @@ [Missing 'struct' keyword before 'segz' in cast; should be '(struct segz *)a'.]
    struct segz *d=(segz *)b; // @@ [Missing 'struct' keyword before 'segz' in cast; should be '(struct segz *)b'.]
    if(c->x1!=d->x1) return d->x1-c->x1;
    else return d->y1-c->y1;
}
int main()
{
    struct segz seg[105]; // @@ [Variable name 'seg' conflicts with the typedef name 'seg' defined earlier, leading to a compilation error.]
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