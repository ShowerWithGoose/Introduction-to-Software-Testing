#include <stdio.h>  
#include <stdbool.h>  
  
void printPermutation(int arr[], int n) {  
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  // @@ Extra trailing space after last number; should print without space after the last element.
    }  
    printf("\n");  
}  
  
void permute(int arr[], int n, int start, bool used[]) {  
    if (start == n) {  
        printPermutation(arr, n);  
        return;  
    }  
    for (int i = 1; i <= n; i++) {  
        if (!used[i]) {  
            used[i] = true;  
            arr[start] = i;  
            permute(arr, n, start + 1, used);  
            used[i] = false;  
        }  
    }  
}  
  
void generatePermutations(int n) {  
    int arr[n];  
    bool used[n + 1];  
    for (int i = 0; i <= n; i++) {  
        used[i] = false;  
    }  
    permute(arr, n, 0, used);  
}  
  
int main() {  
    int N;  
    printf("Enter the number of elements (1 <= N <= 10): ");  // @@ Prompt printed despite not required; must not produce any additional output.
    scanf("%d", &N);  
    if (N >= 1 && N <= 10) {  
        generatePermutations(N);  
    } else {  
        printf("Invalid input. N must be between 1 and 10.\n");  
    }  
    return 0;  
}