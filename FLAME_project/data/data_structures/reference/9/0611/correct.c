#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
   int x1,y1,x2,y2;
   int num;

}line;

int cmp(line *p1,line *p2)
{
    if(p1->x1!=p2->x1)return p1->x1-p2->x1;
    else return p1->y1-p2->y1;
}
int main()
{
int n,i,j;
int m;


int max=0,now,nowi,maxi;
line a[100];
scanf("%d",&n);

for(i=0;i<n;i++)
{
    scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    a[i].num=1;
}
qsort(a,n,sizeof(line),cmp);
for(i=0;i<n;i++)
{
     if(a[i].x1==0&&a[i].y1==0&&a[i].x2==0&&a[i].y2==0)
        continue;
    for(j=0;j<n;j++)
    {
        if(j==i)
            continue;

        else{
                if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
                     {
                         a[i].x2=a[j].x2;
                         a[i].y2=a[j].y2;
                         a[i].num+=a[j].num;
                         a[j].x1=0,a[j].x2=0,a[j].y1=0,a[j].y2=0;
                     }
            }
    }

}
    for(i=0;i<n;i++)
    {
        if(a[i].num>max)
        {
            maxi=i;
            max=a[i].num;
        }
    }

     printf("%d %d %d",max,a[maxi].x1,a[maxi].y1);



return 0;
}

