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
        a[x]=a[x+1]; // @@ [This line incorrectly modifies only a[x] in the loop; it should be a[i] = a[i+1]. Also, loop condition i<=y leads to out-of-bounds access when i == y.]
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
    int a[11]={0,1,2,3,4,5,6,7,8,9}; // @@ [Array initialization is incomplete for N=10; a[10] is uninitialized (should be 10). Also, indexing starts at 1 but a[0]=0 is unused, which is okay, but missing value for position 10.]
    
    int num=1;
    pai_lie(a,num,n); // @@ [The base case print happens inside the loop after recursive call, which causes permutations to be printed multiple times and in wrong order. Also, the recursion doesn't terminate properly before printing.]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}