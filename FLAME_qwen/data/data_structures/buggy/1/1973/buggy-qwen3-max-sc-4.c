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
} // @@ [The loop in swapback incorrectly modifies only a[x] repeatedly instead of shifting elements; it should use 'i' as the index, not 'x'. Also, this function does not correctly reverse the effect of 'swap'.]

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
        
        swapback(a,p,i); // @@ [Because swapback is implemented incorrectly, the array state is not restored properly after recursion, leading to wrong permutations and possibly undefined behavior.]
        if(p==q){
        prt(a,q); // @@ [The print statement is inside the loop and only triggered when p==q, but it's placed after recursive call and swapback, which may print incorrect or duplicate states. Moreover, it should be printed before returning from base case, not inside the loop after backtracking.]
        }
        
    }
    

    
    
}


int main(){
    
    int n=0;
    
    scanf("%d",&n);
    int a[11]={0,1,2,3,4,5,6,7,8,9}; // @@ [Array initialization assumes N up to 10, but if N<10, unused elements remain, which may not affect logic directly, but the bigger issue is that the permutation logic itself is flawed due to incorrect swapping/backtracking.]
    
    int num=1;
    pai_lie(a,num,n); // @@ [The initial call starts with p=1, but the base case condition (p==q) and printing logic is misplaced, causing permutations not to be generated or printed correctly. Also, no base case guard exists to stop recursion when p > q.]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}