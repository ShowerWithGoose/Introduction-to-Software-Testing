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
        a[x]=a[x+1];
    }
    a[y]=t;
} // @@ [The loop in swapback incorrectly modifies a[x] repeatedly instead of shifting elements; it should shift left from x to y-1 and then assign t to a[y]. Also, the loop condition causes out-of-bound access when i == y because a[x+1] becomes a[y+1].]

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
        } // @@ [The base case check 'if(p==q)' is inside the loop and after recursive call, so permutations are printed multiple times and at wrong recursion levels. It should be before the loop as a base condition.]
        
    }
    

    
    
}


int main(){
    
    int n=0;
    
    scanf("%d",&n);
    int a[11]={0,1,2,3,4,5,6,7,8,9}; // @@ [Array initialization only sets first 10 elements (indices 0-9), but for N=10, a[10] is needed and remains uninitialized (0). Should initialize up to index 10 with values 0..10 or better: use loop.]

    
    int num=1;
    pai_lie(a,num,n); // @@ [The algorithm does not generate permutations in lexicographical order due to flawed swapping logic and incorrect restoration in swapback. Also, missing base case handling leads to redundant/misplaced output.]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}