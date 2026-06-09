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
    expression *result= malloc(sizeof(expression)*(len1*len2)); // @@ [Using malloc for array of structs with pointer members is unsafe; 'next' pointers are uninitialized and later assigned to point within the same block, but this leads to undefined behavior when accessing result[j+1] beyond allocated size]
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
            result[i].next=&result[i+1]; // @@ [Writing to result[i].next is unnecessary and dangerous; the 'next' field is never used in output logic, and &result[i+1] may be out-of-bounds when i == len1*len2 - 1]
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
        if(result[j].n!=result[j+1].n){ // @@ [Accessing result[j+1] when j == len1*len2 - 1 causes out-of-bounds read, leading to undefined behavior]
            printf("%d %d ",result[j].a,result[j].n);
        }
        else{
            while (result[j].n==result[j+1].n){ // @@ [Same out-of-bounds access: when j reaches last index, result[j+1] is invalid]
                result[j+1].a+=result[j].a;
                j++;
            }
            printf("%d %d ",result[j].a,result[j].n);
        }
    }
    return 0;
}