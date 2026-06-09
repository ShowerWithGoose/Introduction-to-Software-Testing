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
        a[x]=a[x+1]; // @@ [This line incorrectly modifies a[x] repeatedly instead of shifting elements; it should use a[i] = a[i+1] and loop condition should prevent out-of-bounds access. Also, the logic fails to restore the original array state correctly after recursion.]
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
        
        swapback(a,p,i); // @@ [Because swapback is flawed, the array state is not properly restored before the next iteration, leading to incorrect permutations and possibly undefined behavior.]
        if(p==q){
        prt(a,q); // @@ [The print statement is inside the loop and only triggered when p == q, but due to incorrect backtracking (swapback), the printed permutation may not be valid. Also, the base case should be handled before the loop or outside recursive calls for clarity and correctness.]
        }
        
    }
    

    
    
}


int main(){
    
    int n=0;
    
    scanf("%d",&n);
    int a[11]={0,1,2,3,4,5,6,7,8,9}; // @@ [Array initialization assumes N <= 10, which is acceptable per constraints, but unused elements beyond index n may cause confusion; however, not the primary error.]
    
    int num=1;
    pai_lie(a,num,n); // @@ [Initial call starts with p=1, but the base case check (p == q) happens after recursive calls and swaps, causing permutations to be printed at wrong times and in wrong order. Also, lexicographical order is not guaranteed due to flawed swapping logic.]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}