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
        printf("%d ",*p); // @@ Missing newline; also trailing space after the only number may not be acceptable.
    }
    else if(len==2){
        if(*p>*(p+1)){
            swap(p,p+1);
        }
        for(i=0;i<n;i++){
            printf("%d ",arr[i]); // @@ Trailing space after last number; may not match expected format.
        }
        printf("\n");
        swap(p,p+1);
        for(i=0;i<n;i++){
            printf("%d ",arr[i]); // @@ Trailing space after last number; may not match expected format.
        }
        printf("\n");
        swap(p,p+1);
    }
    else if(len>=3){
        for(i=0;i<len;i++){ // @@ Algorithm does not produce lexicographic order for N>=4; subarray after swap is not sorted.
            swap(p,p+i);
            dfs(p+1,len-1); // @@ Recursive call on unsorted subarray breaks lexicographic ordering.
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