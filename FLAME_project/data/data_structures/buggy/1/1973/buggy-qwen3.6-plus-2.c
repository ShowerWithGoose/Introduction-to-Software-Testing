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
        a[x]=a[x+1]; // @@ [Logic Error: This loop incorrectly shifts elements and overwrites a[x] repeatedly. It should restore the array to its state before swap. The correct logic is to shift elements from x+1 to y left by one position, then place t at a[y]. Specifically, it should be a[i]=a[i+1] inside the loop, but the loop bounds and assignment are flawed here causing data corruption.]
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
        if(p==q){ // @@ [Logic Error: The print statement is executed after the recursive call and swapback, but the condition check is inside the loop after recursion. However, the main issue is that when p==q, we should print BEFORE returning or swapping back. Currently, it prints after swapback which might be okay if swapback is correct, but the standard permutation algorithm prints at the base case (p==q) before unwinding. More critically, the current structure calls recursion, then swapback, THEN checks if p==q to print. If p==q, the loop runs once, swaps (with itself), recurses (base case), swapbacks, then prints. This actually works for printing IF swapback is correct. But wait, if p==q, the loop runs for i=p. swap(a,p,p) does nothing. pai_lie(a,p+1,q) returns immediately if p+1>q? No, if p==q, p+1 > q. The function pai_lie will enter loop with i=p+1 which is > q, so loop doesn't run. Returns. Then swapback. Then if(p==q) is true, so it prints. This seems logically okay for the base case timing, BUT the swapback implementation is broken.]
        prt(a,q);
        }
        
    }
    

    
    
}


int main(){
    
    int n=0;
    
    scanf("%d",&n);
    int a[11]={0,1,2,3,4,5,6,7,8,9};
    
    int num=1;
    pai_lie(a,num,n);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}