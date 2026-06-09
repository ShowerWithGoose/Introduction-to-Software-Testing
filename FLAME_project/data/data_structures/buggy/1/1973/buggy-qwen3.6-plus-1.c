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
    for(int i=x;i<=y;i++){ // @@ The loop condition and body are incorrect for reversing the shift. It should shift elements from x+1 to y back to the left, but this loop overwrites a[x] repeatedly and doesn't correctly restore the array state. Specifically, `a[x]=a[x+1]` inside a loop where `i` goes from `x` to `y` is logically flawed for a "swapback" of a rotation. It should be `a[i]=a[i+1]` for `i` from `x` to `y-1`.
        a[x]=a[x+1];
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
        if(p==q){ // @@ This check is in the wrong place. It should be at the beginning of the function or before the loop to print the permutation when the base case is reached. Currently, it prints after the recursive call and swapback, which means it prints only after returning from recursion, and potentially multiple times or in wrong order depending on logic. More critically, the standard permutation algorithm prints when `p > q` or `p == q` *before* trying further swaps, or handles the base case separately. Here, because it's inside the loop after recursion, it might not print correctly or print duplicates/missed cases. However, the primary issue causing WA for N=2 is likely the swapback logic corrupting the array state, leading to incorrect subsequent permutations or prints. But looking closely at the flow: if p==q, it enters loop, swaps (no effect if i==p), recurses (p+1 > q, so returns immediately), then swapbacks, then checks p==q and prints. This actually might print once per leaf. The real issue is often that `pai_lie` doesn't handle the base case `p > q` or `p == q` correctly by printing *before* returning or structuring the recursion to print at the right time. Let's re-evaluate. If p==q, the loop runs once for i=p. Swap(a,p,p) does nothing. Call pai_lie(a, p+1, q). Since p+1 > q, the function returns immediately without doing anything. Then swapback(a,p,p) does nothing. Then if(p==q) is true, so it prints. This seems okay for the leaf. The problem is likely in `swapback`.
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