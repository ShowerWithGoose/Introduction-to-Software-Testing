#include <stdio.h>  
#include <stdbool.h>  
  
void printPermutation(int arr[], int n) {  
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
}  
  
void permute(int arr[], int n, int start, bool used[]) {  
    if (start == n) {  
        printPermutation(arr, n);  
        return;  
    }  
    for (int i = 1; i <= n; i++) {  
        if (!used[i]) { // 如果数字i还没有被使用过  
            used[i] = true; // 标记为已使用  
            arr[start] = i; // 将数字放到当前位置  
            permute(arr, n, start + 1, used); // 递归排列剩下的数字  
            used[i] = false; // 回溯，标记为未使用，以便在后续的迭代中可以使用它  
        }  
    }  
}  
  
void generatePermutations(int n) {  
    int arr[n]; // 用于存储当前排列的数组  
    bool used[n + 1]; // 用于跟踪哪些数字已经被使用过的数组  
    // 初始化所有数字为未使用状态  
    for (int i = 0; i <= n; i++) {  
        used[i] = false;  
    }  
    // 开始生成全排列，从第一个位置开始填充数字  
    permute(arr, n, 0, used);  
}  
  
int main() {  
    int N;  
    printf("Enter the number of elements (1 <= N <= 10): "); // @@ The problem description does not require any prompt output, and the test case expects only the permutation numbers. This extra output causes a Wrong Answer.
    scanf("%d", &N);  
    if (N >= 1 && N <= 10) {  
        generatePermutations(N);  
    } else {  
        printf("Invalid input. N must be between 1 and 10.\n");  
    }  
    return 0;  
}