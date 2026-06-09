#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define eps 1e-10
#define array_len(x) (sizeof(x) / sizeof(x[0]))
typedef long long ll;
typedef double D;

typedef struct line{
    int a;
    int n;
    struct line *next;
}expression;

int cmp(const void *p1,const void *p2){//升序排列
    expression *a=(expression *)p1;//定义为结构体指针并将p1\p2强转成结构体类型
    expression *b=(expression *)p2;
    return b->n-a->n;//返回按照end_x升序排列
}

int main() {
    expression *p1= malloc(sizeof(expression));
    expression *p2= malloc(sizeof(expression));
    expression *start1=p1;
    expression *start2=p2;
    int len1=0;
    while(1){
        scanf("%d %d",&p1->a,&p1->n);
        p1->next= malloc(sizeof(expression));
        p1=p1->next;
        len1++;
        if(getchar()=='\n')
            break;
    }
    p1->next=NULL;
//    while(start1->next!=NULL){
//        printf("%d %d\n",start1->a,start1->n);
//        start1=start1->next;
//    }
    int len2=0;
    while(1){
        scanf("%d %d",&p2->a,&p2->n);
        p2->next= malloc(sizeof(expression));
        p2=p2->next;
        len2++;
        if(getchar()=='\n')
            break;
    }
    p2->next=NULL;
    p1=start1;
    p2=start2;
    expression *result= malloc(sizeof(expression)*(len1*len2)); // @@ The allocated memory is for an array of structures, but the code later treats it as such. However, the logic for merging terms is flawed. More critically, if len1 or len2 is 0 (empty polynomial input not handled well) or if the multiplication results in fewer unique terms, the loop bounds are wrong. But the primary compilation/runtime issue often stems from accessing result[j+1] out of bounds.
    expression *start3=result;
    int temp_a,temp_n;
    int i=0;
    while (p1->next!=NULL){
        while(p2->next!=NULL){
            temp_a=p1->a*p2->a;
            temp_n=p1->n+p2->n;
            p2=p2->next;
            result[i].a=temp_a;
            result[i].n=temp_n;
            result[i].next=&result[i+1]; // @@ This line sets the next pointer to point to the next element in the allocated array. This is technically valid memory access within the malloc block, but it's mixing linked list semantics with array semantics unnecessarily.
            i++;
        }
        p2=start2;
        p1=p1->next;
    }
    qsort(result,len1*len2, sizeof(expression),cmp);
//    for(int j=0;j<len1*len2;j++){
//        printf("%d %d\n",result[j].a,result[j].n);
//    }
    
    for(int j=0;j<len1*len2;j++){
        if(result[j].n!=result[j+1].n){ // @@ Accessing result[j+1] when j is len1*len2 - 1 causes an out-of-bounds read. This is undefined behavior and likely causes a crash or incorrect output.
            printf("%d %d ",result[j].a,result[j].n);
        }
        else{
            while (result[j].n==result[j+1].n){ // @@ Similarly, accessing result[j+1] here can go out of bounds if the last elements have the same exponent.
                result[j+1].a+=result[j].a;
                j++;
            }
            printf("%d %d ",result[j].a,result[j].n);
        }
    }
    return 0;
}