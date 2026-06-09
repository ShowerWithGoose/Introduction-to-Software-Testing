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
        a[x]=a[x+1]; // @@ [This line incorrectly modifies only a[x] in every iteration; it should be a[i] = a[i+1] to shift elements properly. Also, loop condition may cause out-of-bounds access when i == y.]
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
    int a[11]={0,1,2,3,4,5,6,7,8,9}; // @@ [Array initialization is incomplete for N=10; it only initializes up to index 9 (value 9), but a[10] remains 0. Should initialize all values from 1 to 10 for correctness when N=10.]
    
    int num=1;
    pai_lie(a,num,n); // @@ [The base case for recursion (when p == q) prints the permutation, but it's inside the loop and after recursive call, which leads to multiple prints and wrong order. Also, permutations are not generated in lexicographical order due to flawed swapping logic.]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}