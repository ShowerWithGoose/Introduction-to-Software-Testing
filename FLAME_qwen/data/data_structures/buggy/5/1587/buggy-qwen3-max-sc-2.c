#include<stdio.h>
#include<stdlib.h>
typedef struct item{
int coefficient;
int PowerExponent;
struct item*next;
}item,*itemptr;

int cmp(const void*a,const void*b){
    itemptr a1=(itemptr)a;
    itemptr b1=(itemptr)b;
    return b1->PowerExponent-a1->PowerExponent;
}

itemptr CreateAndInitNode(int coefficient,int PowerExponent){
    itemptr newitem=(itemptr)malloc(sizeof(item));
    newitem->coefficient=coefficient;
    newitem->PowerExponent=PowerExponent;
    newitem->next=NULL;
    return newitem;
}        //创建与初始化同时进行

itemptr Createlist(){
int coefficient=0,PowerExponent=0;
itemptr list=NULL;
itemptr cur=NULL;
while(scanf("%d%d",&coefficient,&PowerExponent)!=EOF){
itemptr newitem=CreateAndInitNode(coefficient,PowerExponent);
if(list==NULL){
list=cur=newitem;
}
else{
    cur->next=newitem;
    cur=cur->next;
}
}
return list;
}


int main(){
itemptr polynomial1=Createlist();
itemptr polynumial2=Createlist();
item res[100];
int i=0,j=0;
printf("%p %p\n",p1,p2); // @@ [undefined variables 'p1' and 'p2'; should be 'polynomial1' and 'polynumial2']
while(p1!=NULL){ // @@ [undefined variable 'p1'; should be 'polynomial1']
    while(p2!=NULL){ // @@ [undefined variable 'p2'; should be 'polynumial2']
       res[i].coefficient=p1->coefficient*p2->coefficient; // @@ [undefined variables 'p1' and 'p2']
       res[i].PowerExponent=p1->PowerExponent+p2->PowerExponent; // @@ [undefined variables 'p1' and 'p2']
       p2=p2->next; // @@ [undefined variable 'p2']
       i++;
    }
    p1=p1->next; // @@ [undefined variable 'p1']
    p2=polynumial2;
}
printf("%d\n",i);
qsort(res,i,sizeof(item),cmp);


while (j<i)
{
  if(res[j].coefficient!=0){
    if(res[j].PowerExponent==res[j+1].PowerExponent&&j+1<i){
        res[j+1].coefficient+=res[j].coefficient;

        j++;

         while(res[j].PowerExponent==res[j+1].PowerExponent&&j+1<i){
            res[j+1].coefficient+=res[j].coefficient;
            j++;
         
            continue;
    }
        printf("%d %d ",res[j].coefficient,res[j].PowerExponent);
}
    else{
    
        printf("%d %d ",res[j].coefficient,res[j].PowerExponent);
}
  }
  j++;

}
    return 0;
}