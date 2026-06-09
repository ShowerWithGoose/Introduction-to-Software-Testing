#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct maths{
int coe;
int pow;
};
typedef struct maths alpha;
alpha a[1000],b[1000],c[1000];
int cmp(const void*p1,const void*p2);
int main(){
int i,j,k=0;
int n=0,m=0;
char ch;
do{
scanf("%d%d%c",&a[n].coe,&a[n].pow,&ch);
n++;
}while(ch!='\n');
do
{
scanf("%d%d%c",&b[m].coe,&b[m].pow,&ch);
m++;
}while(ch!='\n');
qsort(a,n,sizeof(alpha),cmp);
qsort(b,m,sizeof(alpha),cmp);
for(i=0;i<n;i++){
for(j=0;j<m;j++){
c[k].coe=a[i].coe*b[j].coe;
c[k].pow=a[i].pow+b[j].pow;
k++;
}
}
qsort(c,k,sizeof(alpha),cmp);
for(i=0;i<k;i++){
if(c[i].pow==c[i+1].pow&&c[i+1].pow!=0){
c[i+1].coe+=c[i].coe;
c[i].coe=0;
}
}
qsort(c,k,sizeof(alpha),cmp);
for(i=0;i<k;i++){
if(c[i].coe==0)
continue;
else
printf("%d %d ",c[i].coe,c[i].pow);
}
return 0;
}
int cmp(const void*p1,const void*p2){
struct maths *a=(struct maths*)p1;
struct maths *b=(struct maths*)p2;
return b->pow-a->pow;
}

