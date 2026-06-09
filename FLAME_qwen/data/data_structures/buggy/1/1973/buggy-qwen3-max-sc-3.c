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
        a[x]=a[x+1]; // @@ [Infinite loop and incorrect logic: 'x' is not incremented in the loop, so it keeps assigning a[x+1] to a[x] without moving forward. Also, this overwrites a[x] repeatedly and never restores the original array correctly.]
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
        
        swapback(a,p,i); // @@ [swapback is logically flawed and does not correctly reverse the effect of swap(), leading to corrupted permutations and incorrect output order.]
        if(p==q){
        prt(a,q); // @@ [Printing only when p==q inside the loop causes permutations to be printed multiple times or at wrong recursion levels; should print only once at base case before returning.]
        }
        
    }
    

    
    
}


int main(){
    
    int n=0;
    
    scanf("%d",&n);
    int a[11]={0,1,2,3,4,5,6,7,8,9}; // @@ [Array initialization assumes N up to 10, but if N<10, unused elements remain and may interfere; however, more critically, the algorithm doesn't generate lexicographical order due to flawed swapping logic.]
    
    int num=1;
    pai_lie(a,num,n); // @@ [The recursive permutation generation uses an incorrect swapping mechanism that doesn't produce all permutations nor in lexicographical order as required.]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}