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
        while(result[i+cnt].x==result[i].x){ // @@ 这里缺少对 i+cnt 是否越界的检查，当 i+cnt >= size 时会导致数组越界访问
            result[i].a+=result[i+cnt].a;
            result[i+cnt].x=-1;
            
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
    struct multi *result = (struct multi*)malloc(size * sizeof(struct multi));
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
            if(result[i].x==26){ // @@ 这里硬编码判断指数为26的情况，不符合通用性要求，且会导致输出错误
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