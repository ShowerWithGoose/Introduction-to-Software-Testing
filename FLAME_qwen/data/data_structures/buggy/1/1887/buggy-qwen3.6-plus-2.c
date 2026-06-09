#include<stdio.h>
#include<string.h>
int arr[15];
int n;
void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}
void dfs(int *p,int len){
    int i;
    if(len==1){
        printf("%d ",*p); @@ Missing newline character, causes incorrect output format for N=1.
    }
    else if(len==2){
        if(*p>*(p+1)){
            swap(p,p+1);
        }
        for(i=0;i<n;i++){
            printf("%d ",arr[i]); @@ Prints a trailing space after the last number, violating the output format requirement.
        }
        printf("\n");
        swap(p,p+1);
        for(i=0;i<n;i++){
            printf("%d ",arr[i]); @@ Prints a trailing space after the last number, violating the output format requirement.
        }
        printf("\n");
        swap(p,p+1);
    }
    else if(len>=3){
        for(i=0;i<len;i++){
            swap(p,p+i);
            dfs(p+1,len-1);
            swap(p,p+i);
        }
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        arr[i]=i+1;
    }
    dfs(arr,n); @@ The swap-based recursion does not generate permutations in lexicographical order, and the program lacks a sorting mechanism to meet the output requirement.
    return 0;
}