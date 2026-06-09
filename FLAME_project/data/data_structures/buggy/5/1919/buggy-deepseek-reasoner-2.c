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
        p1->next= malloc(sizeof(expression)); // @@ 多余分配一个空节点，导致链表末尾多一个未初始化的节点，可能引起后续遍历逻辑错误，但此处不致命
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
        p2->next= malloc(sizeof(expression)); // @@ 同第一个多项式，多余分配空节点
        p2=p2->next;
        len2++;
        if(getchar()=='\n')
            break;
    }
    p2->next=NULL;
    p1=start1;
    p2=start2;
    expression *result= malloc(sizeof(expression)*(len1*len2));
    expression *start3=result;
    int temp_a,temp_n;
    int i=0;
    while (p1->next!=NULL){ // @@ 遍历条件应为 p1!=NULL，因为链表无哑头节点，p1本身是有效节点；当前写法在最后一个有效节点后还有一个空节点，虽能正常工作但逻辑不清晰
        while(p2->next!=NULL){ // @@ 同外层循环，遍历条件应为 p2!=NULL
            temp_a=p1->a*p2->a;
            temp_n=p1->n+p2->n;
            p2=p2->next;
            result[i].a=temp_a;
            result[i].n=temp_n;
            result[i].next=&result[i+1]; // @@ 当i为len1*len2-1时，&result[i+1]越界访问数组末尾后的地址，导致未定义行为
            i++;
        }
        p2=start2;
        p1=p1->next;
    }
    qsort(result,len1*len2, sizeof(expression),cmp);
//    for(int j=0;j<len1*len2;j++){
//        printf("%d %d\n",result[j].a,result[j].n);
//    }
    
    for(int j=0;j<len1*len2;j++){ // @@ 在C89标准中，不允许在for循环内声明变量；许多编译器默认使用C89，会报编译错误
        if(result[j].n!=result[j+1].n){ // @@ 当j=len1*len2-1时，result[j+1]越界访问，导致未定义行为
            printf("%d %d ",result[j].a,result[j].n);
        }
        else{
            while (result[j].n==result[j+1].n){ // @@ 同上，越界访问；且合并逻辑不正确，可能导致死循环或错误输出
                result[j+1].a+=result[j].a; // @@ 越界访问
                j++;
            }
            printf("%d %d ",result[j].a,result[j].n);
        }
    }
    return 0;
}