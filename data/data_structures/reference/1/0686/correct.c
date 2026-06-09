#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

#define M 10000


void swap(int *A, int a, int b){
    int tmp = A[b], k = b;
    for(k; k>a; k--){
        A[k] = A[k-1];
    }
    A[a] = tmp;
}

void swapback(int *A, int a, int b){
    int tmp = A[a], k = a;
    for(k; k<b; k++){
        A[k] = A[k+1];
    }
    A[b] = tmp;
}

void output(int *A, int n){
    for(int i= 0; i< n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Perm(int *Array, int fron, int rear){
    if(fron == rear){
        output(Array, rear+1);
    }
    else{
        int i; 
        for(i=fron; i<rear+1; i++){
            swap(Array, fron, i);
            Perm(Array, fron + 1, rear);
            swapback(Array, fron, i);
        }
    }
}

int main(){
    int a[100], n;
    scanf("%d", &n);

    int i;
    for(i = 0; i<n; i++){
        a[i] = i+1;
    }

    Perm(a, 0, n-1);

    return 0;
}
