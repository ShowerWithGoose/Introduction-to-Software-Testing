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
        printf("%d ",*p); // @@ 错误：当len==1时，应输出完整的排列（即整个arr数组）并换行，而不是只输出一个元素。这导致N=1时输出格式错误。
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
    dfs(arr,n);
    return 0;
}