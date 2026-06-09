#include<stdio.h>
struct nod
{
int co;
int en;
}q[1000],p[1000];
char e=' ';
int cmp(const void *a,const void *b)
{
struct nod *c=(struct nod *)a;
struct nod *d=(struct nod *)b;
return d->en-c->en;
}
int main()
{
int a[1000],b[1000],c[1000],d[1000];
int i=0;
while(e!='\n'){
scanf("%d%d%c",&a[i],&b[i],&e);
i++;
}
int j=0;
e=' ';
while(e!='\n'){
scanf("%d%d%c",&c[j],&d[j],&e);
j++;
}
int cut=0;
for(int s=0;s<i;s++)
{
 for(int t=0;t<j;t++)
 {
 p[cut].co=a[s]*c[t];
 p[cut].en=b[s]+d[t];
 cut++;
 }
}
qsort(p,cut,sizeof(p[0]),cmp);
for(i=0;i<cut;i++)
{
if(p[i].en==p[i+1].en&&p[i].en!=0)
 {
 p[i+1].co+=p[i].co;
 p[i].co=0;
 }
}
for(i=0;i<cut;i++)
{
if(p[i].co!=0)
printf("%d %d ",p[i].co,p[i].en);
}
return 0;
}

