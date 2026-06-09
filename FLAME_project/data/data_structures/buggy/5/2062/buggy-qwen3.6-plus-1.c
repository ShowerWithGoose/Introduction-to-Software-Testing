#include <stdio.h>
#include <stdlib.h>

// 定义结构体multi
struct multi {
    int a;
    int x;
};

// 比较函数，用于qsort排序
int compare(const void *a, const void *b) {
    return (*(struct multi*)b).x - (*(struct multi*)a).x;
}

// 进行操作的函数
void operate(struct multi *arr1, struct multi *arr2, struct multi *result, int p,int q) {
    int size=0;
    for (int i = 0; i <p; i++) {
        for(int k=0;k<q ; k++){
        result[size].a = arr1[i].a * arr2[k].a;
        result[size].x = arr1[i].x + arr2[k].x;
        size++;}
    }
}


void merge(struct multi *result, int size) {
    for (int i = 0; i < size; ) {
        int cnt=1;
        while(i+cnt < size && result[i+cnt].x==result[i].x){ // @@ The original code lacked a boundary check for i+cnt, which could cause out-of-bounds access. Also, the logic for merging multiple terms with the same exponent was flawed as it didn't properly advance or handle all duplicates.
            result[i].a+=result[i+cnt].a;
            result[i+cnt].x=-1;
            cnt++; // @@ The original code did not increment cnt, causing an infinite loop if more than two terms had the same exponent.
            
        }
        i+=cnt;
        cnt=1;
    }
}
int main() {
    
    int size=100;
    // 创建两个multi类型的数组
    struct multi *arr1 = (struct multi*)malloc(size * sizeof(struct multi));
    struct multi *arr2 = (struct multi*)malloc(size * sizeof(struct multi));
    struct multi *result = (struct multi*)malloc(size * sizeof(struct multi)); // @@ The allocated size for result is too small (100). It should be at least i*k, which can be much larger. However, since size is reassigned later, this might just be a warning, but strictly speaking, it's a potential buffer overflow if operate writes beyond initial allocation before realloc (which isn't done). A better fix would be to allocate after reading sizes, but keeping structure:
char ch;
    int i=0;
    int k=0;
   do   //读入第一个多项式 
    {
        scanf("%d%d%c",&arr1[i].a,&arr1[i].x,&ch);
        i++;
    }while(ch!='\n');
    do    //读入第二个多项式
    {
        scanf("%d%d%c",&arr2[k].a,&arr2[k].x,&ch);
        k++;
    }while(ch!='\n');

    size=i*k;
    // 进行操作
    operate(arr1, arr2, result, i,k);

    // 对result数组按x从大到小排序
    qsort(result, size, sizeof(struct multi), compare);

    // 输出结果
    merge(result ,size);
    for (int i = 0; i < size; i++) {
        if(result[i].x!=-1){
            if(result[i].x==26){ // @@ This hardcoded check masks the actual bug in merge/logic. The term 157 26 appears twice in the buggy output because the merge failed to combine them correctly into 468 24? No, wait. 157+157=314? No. Let's look at expected: 157 26 and 468 24. The buggy output has 157 26 twice. This implies the merge didn't combine terms with exponent 26 correctly, or there are two different terms. 
                // Actually, looking at the expected output: `157 26` appears once. `468 24` appears once.
                // Buggy output: `157 26` appears twice.
                // The hardcode `if(result[i].x==26)` prints `157 26` and skips next. This is a patch for a specific test case, not a general solution. It hides the real error.
                // The real error is in `merge`.
                printf("157 26 ");
                i++;
            }else{
        printf("%d %d ", result[i].a, result[i].x);}
        }
        
    }

    // 释放内存
    free(arr1);
    free(arr2);
    free(result);

    return 0;
}