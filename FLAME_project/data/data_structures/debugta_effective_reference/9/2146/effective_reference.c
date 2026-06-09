#include<stdio.h>
#include<stdlib.h>
typedef struct gather{
int startx;
int starty;
int endx;
int endy;
int counter;
}gather[100];
int cmp(const void *a,const void *b)
{
struct gather *c=(gather *)a;
struct gather *d=(gather *)b;
if(c->startx!=d->startx)
return d->startx-c->startx;
else
return d->starty-c->starty;
}
int main(){
int n;
struct gather gather[100];
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%d%d%d%d",&gather[i].startx,&gather[i].starty,&gather[i].endx,&gather[i].endy),gather[i].counter=1;
qsort(gather,n,sizeof(gather[0]),cmp);
for(int i=0;i<n;i++)
{
 for(int j=i+1;j<n;j++)
 {
 if(gather[i].startx==gather[j].endx&&gather[i].starty==gather[j].endy)
 gather[j].counter+=gather[i].counter;
 }
}
int max=-1;
int target=0;
for(int i=0;i<n;i++)
{
if(gather[i].counter>max)
 {
 max=gather[i].counter;
 target=i;
 }
}
printf("%d %d %d",max,gather[target].startx,gather[target].starty);
return 0;
}

