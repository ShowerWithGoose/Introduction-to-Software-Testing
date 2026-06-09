#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct node{
int coe;
int pow;
int flag;
};//用链表需要最后一个大排序，太麻烦了，所以放弃链表
typedef struct node Node;
int cmp(const void*pd1,const void*pd2);
Node fir[1000],sec[1000],ret1[2000];
int main()
{
int i=0,j=0;
char op;
do{
    scanf("%d%d%c",&fir[i].coe,&fir[i].pow,&op);
    i++;
}while(op!='\n');//第一个多项式

do{
    scanf("%d%d%c",&sec[j].coe,&sec[j].pow,&op);
    j++;
}while(op!='\n');//第二个多项式
int n=0;
for(int k=0;k<i;k++){
    for(int ii=0;ii<j;ii++){
        ret1[n].coe=fir[k].coe*sec[ii].coe;
        ret1[n].pow=fir[k].pow+sec[ii].pow;
        ret1[n].flag=1;
        n++;
        }
}


//开始去重
for(int x=0;x<n;x++){
    for(int y=x+1;y<n;y++){
    if(ret1[y].pow==ret1[x].pow){
    ret1[x].coe=ret1[x].coe+ret1[y].coe;
    ret1[y].coe=0;
    ret1[y].flag=0;
    }
}
}

qsort(ret1,n,sizeof(Node),cmp);

for(int m=0;m<n;m++){
    if(ret1[m].flag==0)
        continue;
    else
        printf("%d %d ",ret1[m].coe,ret1[m].pow);}




return 0;
}
int cmp(const void *pd1,const void *pd2){
struct node *a=(struct node*)pd1;
struct node *b=(struct node*)pd2;
return b->pow-a->pow;
}

