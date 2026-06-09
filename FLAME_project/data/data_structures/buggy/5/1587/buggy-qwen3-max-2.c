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
// @@ [The program has multiple critical errors: 
// 1. The array `res` is too small (size 100) for large-degree polynomials (e.g., degree 1e9 leads to product degree 2e9, but even number of terms can exceed 100).
// 2. The merging of like terms in the output loop is flawed—it only merges consecutive duplicates after sorting, but the logic skips terms and mishandles boundaries (e.g., accessing res[j+1] when j+1 >= i).
// 3. The input reading for the second polynomial fails because the first polynomial's input ends with newline, but `scanf` in `Createlist` uses `!=EOF`, which doesn't stop at newline—so both polynomials are read as one continuous stream.
// 4. The test case has two single-term polynomials, so multiplication yields one term, but due to input reading error, the second polynomial may not be read correctly.
// 5. The debug print statements (`printf("%p %p\n",p1,p2);` and `printf("%d\n",i);`) produce extra output not in expected format, causing WA.]