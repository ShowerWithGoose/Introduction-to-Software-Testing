#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int *a, int *b);
void fullPermutation(int source[], int begin, int end);
int cmp(const void* a, const void* b);

int n, cnt = 0;
int str[30] ,ans[200][30];

int main(){
    int i ,j;
    
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
    }else{
        for (i = 0; i < n; i++){
            str[i] = i + 1;
        }
        fullPermutation(str, 0, n);
    }
    qsort(ans, cnt, sizeof(ans[0]), cmp);
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < n; j++) {
            printf("%d%c", ans[i][j], (j==n-1) ? '\n' : ' ');
        }
    }
    return 0;
}
void fullPermutation(int str[], int start, int end){
    int i;
    if (start >= end){//排列完成
        for (i = 0; i < end; i++){
            ans[cnt][i] = str[i];
        }
        cnt++;
    }
    else{//排列未完，则继续往下找下一个元素
        for (i = start; i < end; i++){
            swap(&str[start], &str[i]); // 交换
            fullPermutation(str, start+1, end);// 递归
            swap(&str[start], &str[i]); // 回溯时恢复原顺序
        }
        
    }
}
void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int cmp(const void* a, const void* b){
    int *x = (int*)a;
    int *y = (int*)b;
    int i;
    for (i = 0; i < n; i++) {
        if (x[i] == y[i]) continue;
        else return (x[i]<y[i]) ? -1 : 1;
    }
    return 0;
}



