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
    expression *result= malloc(sizeof(expression)*(len1*len2)); // @@ The variable 'result' is declared as a pointer to a single expression struct, but allocated memory for an array. However, the subsequent usage treats it as an array of structs. While this allocation is technically valid for accessing elements via index if cast correctly or if treated as a block, the declaration `expression *result` implies a linked list node in the context of the struct definition, but here it's used as a dynamic array. The real issue is likely logical or boundary related later, but let's look closer. Actually, `malloc(sizeof(expression)*(len1*len2))` returns a void* which is assigned to `expression*`. This is fine for array access `result[i]`.
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
            result[i].next=&result[i+1]; // @@ Accessing &result[i+1] when i is the last index (len1*len2 - 1) will go out of bounds. Also, linking them as a linked list inside an array allocated by malloc is unnecessary and potentially dangerous if not handled carefully, though qsort works on the memory block. The main logical error here is that `p2` is advanced before using its current values? No, `temp_a` and `temp_n` are calculated using current `p1` and `p2`, then `p2` advances. This is correct order.
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
        if(result[j].n!=result[j+1].n){ // @@ Accessing result[j+1] when j is len1*len2 - 1 causes out-of-bounds read.
            printf("%d %d ",result[j].a,result[j].n);
        }
        else{
            while (result[j].n==result[j+1].n){ // @@ Accessing result[j+1] can cause out-of-bounds read if the last elements have the same exponent.
                result[j+1].a+=result[j].a;
                j++;
            }
            printf("%d %d ",result[j].a,result[j].n);
        }
    }
    return 0;
}