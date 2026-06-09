#include<stdio.h>
#include<stdlib.h>
typedef struct item{
int coefficient;
int PowerExponent;
struct item*next;
}item,*itemptr;

int cmp(const void*a,const void*b){
    itemptr a1=(itemptr)a; // @@ Casting away const qualifier from 'a' may cause compilation warnings/errors in strict environments; should use 'const item *a1 = a;'
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
while(scanf("%d%d",&coefficient,&PowerExponent)!=EOF){ // @@ scanf skips whitespace including newlines, so it will consume both polynomials into the first list instead of stopping at the newline separator between inputs.
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
item res[100]; // @@ Fixed size array may cause buffer overflow if the number of product terms exceeds 100; dynamic allocation or a larger size is safer.
int i=0,j=0;
printf("%p %p\n",p1,p2);
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
printf("%d\n",i);
qsort(res,i,sizeof(item),cmp);


while (j<i)
{
  if(res[j].coefficient!=0){
    if(res[j].PowerExponent==res[j+1].PowerExponent&&j+1<i){ // @@ Merging logic is flawed: it accumulates coefficients into res[j+1] but prints res[j] after incrementing j, which can skip terms or print incorrect merged values. Zero coefficients after merging are also not filtered out.
        res[j+1].coefficient+=res[j].coefficient;

        j++;

         while(res[j].PowerExponent==res[j+1].PowerExponent&&j+1<i){
            res[j+1].coefficient+=res[j].coefficient;
            j++;
         
            continue; // @@ Redundant: 'continue' inside this while loop only jumps to the loop's condition check, which happens naturally. It does not skip to the next iteration of the outer loop.
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