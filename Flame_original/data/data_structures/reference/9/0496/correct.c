#include<stdio.h>
#include<stdlib.h>
typedef struct line{
int startx;
int starty;
int endx;
int endy;
int num;
}line[100];
int cmp(const void *a,const void *b)
{
struct line *c=(line *)a;
struct line *d=(line *)b;
if(c->startx!=d->startx)
return d->startx-c->startx;
else
return d->starty-c->starty;
}
int main(){
int n;
struct line line[100];
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%d%d%d%d",&line[i].startx,&line[i].starty,&line[i].endx,&line[i].endy),line[i].num=1;
qsort(line,n,sizeof(line[0]),cmp);
for(int i=0;i<n;i++)
{
 for(int j=i+1;j<n;j++)
 {
 if(line[i].startx==line[j].endx&&line[i].starty==line[j].endy)
 line[j].num+=line[i].num;
 }
}
int max=-1;
int flag=0;
for(int i=0;i<n;i++)
{
if(line[i].num>max)
 {
 max=line[i].num;
 flag=i;
 }
}
printf("%d %d %d",max,line[flag].startx,line[flag].starty);
return 0;
}

