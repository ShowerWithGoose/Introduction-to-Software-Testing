#include <stdio.h>

void swap(int a[],int x,int y){
    int t=a[y];
    for(int i=y;i>x;i--){
    a[i]=a[i-1];
    }
    a[x]=t;
    }
void swapback(int a[],int x,int y){
    int t=a[x];
    for(int i=x;i<=y;i++){
        a[x]=a[x+1]; // @@ [This line causes undefined behavior: it repeatedly assigns a[x+1] to a[x] without updating the index, leading to infinite overwrites and potential out-of-bounds access. It should use 'i' instead of 'x' in the loop body.]
    }
    a[y]=t;
}
void prt(int a[],int q){
    for(int i=1;i<=q;i++){
    printf("%d ",a[i]);
    }
    printf("\n");
}
void pai_lie(int a[],int p,int q){
    
    for(int i=p;i<=q;i++){
    
        swap(a,p,i);
        
        pai_lie(a,p+1,q);
        
        swapback(a,p,i);
        if(p==q){
        prt(a,q);
        }
        
    }
    

    
    
}


int main(){
    
    int n=0;
    
    scanf("%d",&n);
    int a[11]={0,1,2,3,4,5,6,7,8,9}; // @@ [Array initialization is incomplete for N=10; only indices 0-9 are initialized, but a[10] remains uninitialized (though set to 0 by partial init). However, more critically, the logic in swap/swapback does not generate permutations correctly and leads to incorrect or duplicated outputs. Also, base case printing happens inside loop after recursive call, which is logically flawed.]
    
    int num=1;
    pai_lie(a,num,n);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}