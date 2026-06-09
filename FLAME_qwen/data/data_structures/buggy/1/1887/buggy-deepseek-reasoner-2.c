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
        printf("%d ",*p); // @@ This prints only one element, not the full permutation; also no newline. Should print the entire current permutation (arr[0..n-1]) and then a newline.
    }
    else if(len==2){
        if(*p>*(p+1)){
            swap(p,p+1);
        }
        for(i=0;i<n;i++){
            printf("%d ",arr[i]); // @@ Prints the full array but leaves a trailing space; the output should be space-separated without trailing space. More importantly, the algorithm does not generate permutations in lexicographic order as required.
        }
        printf("\n");
        swap(p,p+1);
        for(i=0;i<n;i++){
            printf("%d ",arr[i]); // @@ Same issue as above.
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
    dfs(arr,n); // @@ The dfs function does not output permutations in lexicographic order. A sorting step (like in the reference program) is missing.
    return 0;
}