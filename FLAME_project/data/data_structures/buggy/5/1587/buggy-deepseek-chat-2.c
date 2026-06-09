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
itemptr p1=polynomial1;
itemptr p2=polynumial2;
item res[100];
int i=0,j=0;
printf("%p %p\n",p1,p2); // @@ This line prints debug information that is not part of the expected output, causing Wrong Answer.
while(p1!=NULL){
    while(p2!=NULL){
       res[i].coefficient=p1->coefficient*p2->coefficient;
       res[i].PowerExponent=p1->PowerExponent+p2->PowerExponent;
       p2=p2->next;
       i++;
    }
    p1=p1->next;
    p2=polynumial2;
}
printf("%d\n",i); // @@ This line prints debug information that is not part of the expected output, causing Wrong Answer.
qsort(res,i,sizeof(item),cmp);


while (j<i)
{
  if(res[j].coefficient!=0){
    if(res[j].PowerExponent==res[j+1].PowerExponent&&j+1<i){ // @@ Potential out-of-bounds access when j = i-1, as res[j+1] accesses beyond array.
        res[j+1].coefficient+=res[j].coefficient;

        j++;

         while(res[j].PowerExponent==res[j+1].PowerExponent&&j+1<i){ // @@ Same out-of-bounds issue; also logic for combining like terms is flawed, may skip or incorrectly combine terms.
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