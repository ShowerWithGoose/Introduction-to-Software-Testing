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
}seg[105]; // @@ [The typedef defines 'seg' as an array type of 105 'struct segz', which is unconventional and causes confusion later when declaring 'struct segz seg[105];'. This leads to a redefinition error because 'seg' is already defined as a type alias for an array of 105 structs.]
int cmpfuc(const void *a, const void *b)            
{                                                
    struct segz *c=(segz *)a; // @@ [Missing 'struct' keyword before 'segz' in cast; should be '(struct segz *)a'. This causes a compilation error because 'segz' alone is not a recognized type without 'struct' unless properly typedef'd, which it isn't as a simple struct tag here.]
    struct segz *d=(segz *)b; // @@ [Same issue: missing 'struct' keyword before 'segz' in cast.]
    if(c->x1!=d->x1) return d->x1-c->x1;
    else return d->y1-c->y1;
}
int main()
{
    struct segz seg[105]; // @@ [This declaration conflicts with the earlier typedef 'seg[105]' which already defines 'seg' as a type. This line attempts to declare a variable named 'seg' of type 'struct segz[105]', but since 'seg' is already a typedef name, this may cause a redeclaration or type conflict error depending on compiler interpretation.]
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