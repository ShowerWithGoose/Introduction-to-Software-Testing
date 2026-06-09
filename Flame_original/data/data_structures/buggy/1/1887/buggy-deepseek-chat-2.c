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
        printf("%d ",*p); // @@ This prints only one number without a newline, and does not handle the full permutation output correctly for len==1 case; the recursion base case should print the entire array arr.
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
        swap(p,p+1); // @@ This logic for len==2 is flawed: it only prints two permutations (sorted and swapped) but does not generate all permutations recursively; also the swap back is unnecessary and the base case should be handled uniformly.
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