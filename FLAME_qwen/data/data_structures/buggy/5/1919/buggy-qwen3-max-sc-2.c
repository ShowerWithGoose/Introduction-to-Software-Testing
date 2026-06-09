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
    expression *result= malloc(sizeof(expression)*(len1*len2)); // @@ [Using malloc without casting in C is acceptable, but the real issue is that 'result' is treated as an array of structs, yet each element's 'next' pointer is set to point within the same block. However, the major error is in the loop condition and out-of-bounds access below.]
    expression *start3=result;
    int temp_a,temp_n;
    int i=0;
    while (p1->next!=NULL){ // @@ [This skips the last valid node because the list ends with a node whose next is NULL, but the last valid data node is the one before that. The loop should run while(p1 != NULL), not p1->next != NULL. Same for p2 loop.]
        while(p2->next!=NULL){ // @@ [Same issue: skips last term of second polynomial. Should be while(p2 != NULL).]
            temp_a=p1->a*p2->a;
            temp_n=p1->n+p2->n;
            p2=p2->next;
            result[i].a=temp_a;
            result[i].n=temp_n;
            result[i].next=&result[i+1]; // @@ [This sets next to next array element, but after sorting, this pointer becomes meaningless and unused. More critically, when i = len1*len2 - 1, &result[i+1] is out-of-bounds.]
            i++;
        }
        p2=start2;
        p1=p1->next;
    }
    qsort(result,len1*len2, sizeof(expression),cmp);
//    for(int j=0;j<len1*len2;j++){
//        printf("%d %d\n",result[j].a,result[j].n);
//    }
    
    for(int j=0;j<len1*len2;j++){ // @@ [Loop goes up to j = len1*len2 - 1, but result[j+1] is accessed, causing out-of-bounds read on last iteration.]
        if(result[j].n!=result[j+1].n){ // @@ [Accesses result[len1*len2], which is beyond allocated memory.]
            printf("%d %d ",result[j].a,result[j].n);
        }
        else{
            while (result[j].n==result[j+1].n){ // @@ [Same out-of-bounds access; also, if all terms have same exponent, j may exceed bounds.]
                result[j+1].a+=result[j].a;
                j++;
            }
            printf("%d %d ",result[j].a,result[j].n);
        }
    }
    return 0;
}