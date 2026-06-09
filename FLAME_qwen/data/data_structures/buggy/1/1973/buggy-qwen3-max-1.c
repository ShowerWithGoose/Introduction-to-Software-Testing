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
        a[x]=a[x+1]; // @@ [This line incorrectly modifies a[x] repeatedly instead of shifting elements; it should use a[i] = a[i+1] and loop condition should prevent out-of-bounds access. Also, the logic fails to restore the original array correctly after recursion.]
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
        
        swapback(a,p,i); // @@ [swapback is flawed due to incorrect shifting logic, leading to corrupted array state during backtracking, which breaks permutation generation.]
        if(p==q){
        prt(a,q); // @@ [Printing only when p == q inside the loop causes permutations to be printed multiple times or at wrong recursion levels; it should be printed once when base case is reached, not inside the loop after backtracking.]
        }
        
    }
    

    
    
}


int main(){
    
    int n=0;
    
    scanf("%d",&n);
    int a[11]={0,1,2,3,4,5,6,7,8,9}; // @@ [Array initialization assumes N <= 9, but problem allows N up to 10; a[10] is uninitialized (since initializer has 10 elements: indices 0-9), so a[10] is zero, breaking permutation for N=10.]
    
    int num=1;
    pai_lie(a,num,n); // @@ [The recursive function does not handle base case properly (missing explicit base case check before loop), leading to infinite recursion or incorrect behavior when p > q. Also, initial call uses global-like state without ensuring correct starting array for given N.]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}