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
Node fir[1000],sec[1000],mul[2000];
int main()
{
int n=0,m=0;
char op;
do{
    scanf("%d%d%c",&fir[n].coe,&fir[n].pow,&op);
    n++;
}while(op!='\n');//第一个多项式

do{
    scanf("%d%d%c",&sec[m].coe,&sec[m].pow,&op);
    m++;
}while(op!='\n');//第二个多项式
int k=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        mul[k].coe=fir[i].coe*sec[j].coe;
        mul[k].pow=fir[i].pow+sec[j].pow;
        mul[k].flag=1;
        k++;
        }
}


//开始去重
for(int x=0;x<k;x++){
    for(int y=x+1;y<k;y++){
    if(mul[y].pow==mul[x].pow){
    mul[x].coe=mul[x].coe+mul[y].coe;
    mul[y].coe=0;
    mul[y].flag=0;
    }
}
}

qsort(mul,k,sizeof(Node),cmp);

for(int z=0;z<k;z++){
    if(mul[z].flag==0)
        continue;
    else
        printf("%d %d ",mul[z].coe,mul[z].pow);}




return 0;
}
int cmp(const void *pd1,const void *pd2){
struct node *a=(struct node*)pd1;
struct node *b=(struct node*)pd2;
return b->pow-a->pow;
}

