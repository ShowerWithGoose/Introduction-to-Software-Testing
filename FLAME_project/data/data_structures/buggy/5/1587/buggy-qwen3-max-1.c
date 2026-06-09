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
// 1. The array `res` is too small (size 100) for large inputs like exponents up to 1e9; though number of terms may be small, the test case has only one term each, so this isn't the main issue here.
// 2. The main logic error is in the combination of like terms after sorting: it uses an unsafe and incorrect merging strategy that accesses `res[j+1]` without ensuring `j+1 < i`, leading to out-of-bounds access and incorrect accumulation.
// 3. In the test case, both polynomials have one term: (8x^1e9) * (15x^1e9) = 120x^2e9. But the code prints pointers first (`printf("%p %p\n",p1,p2);`) which causes wrong output format.
// 4. The input reading for the second polynomial fails because `Createlist()` reads until EOF, but the input has two lines. The first call to `Createlist()` consumes the first line and then waits for more input until EOF, so the second call gets nothing. Thus, `polynumial2` becomes NULL, leading to zero multiplications.
// 5. The variable name typo `polynumial2` (missing 'o') doesn't affect compilation but reflects poor practice.
// 6. The output includes debug printfs (`%p %p` and `%d\n`) which violate the required output format.
// 7. The combination loop does not correctly merge all same-exponent terms; it skips terms or double-counts due to flawed control flow.]