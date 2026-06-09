#include <stdio.h>  
#include <stdbool.h>  
  
void printPermutation(int arr[], int n) {  
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]); // @@ Trailing space after the last number violates the output format requirement. Should conditionally print space only between numbers.
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
    int arr[n]; // @@ Variable Length Array (VLA) may cause compilation errors in strict C89/C90 environments or compilers that do not support C99 features. Use a fixed size array (e.g., int arr[10]) instead.
    bool used[n + 1]; // @@ VLA with non-constant size may cause compilation errors in some strict C environments. Use a fixed size array (e.g., bool used[11]) instead.
    // 初始化所有数字为未使用状态  
    for (int i = 0; i <= n; i++) {  
        used[i] = false;  
    }  
    // 开始生成全排列，从第一个位置开始填充数字  
    permute(arr, n, 0, used);  
}  
  
int main() {  
    int N;  
    printf("Enter the number of elements (1 <= N <= 10): "); // @@ Unnecessary prompt output violates the exact output format required by the problem and will cause Wrong Answer in automated judges.
    scanf("%d", &N);  
    if (N >= 1 && N <= 10) {  
        generatePermutations(N);  
    } else {  
        printf("Invalid input. N must be between 1 and 10.\n");  
    }  
    return 0;  
}