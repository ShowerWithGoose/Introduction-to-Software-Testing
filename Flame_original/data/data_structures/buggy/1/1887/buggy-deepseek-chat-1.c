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
        printf("%d ",*p); // @@ Error: This prints only one number without a newline, and does not handle the full permutation output correctly. The function should print the entire array arr when a complete permutation is formed, not just a single element.
    }
    else if(len==2){
        if(*p>*(p+1)){
            swap(p,p+1);
        }
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        swap(p,p+1);
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        swap(p,p+1); // @@ Error: This approach for len==2 is flawed. It only handles the case of two elements and does not generate permutations recursively for larger N. The logic is incomplete and does not produce all permutations correctly.
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
    dfs(arr,n);
    return 0;
}