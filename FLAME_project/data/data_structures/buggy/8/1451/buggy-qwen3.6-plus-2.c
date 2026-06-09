#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
   int q[200][200];
   int flag[200];
   int m,n,time;       int l;
   void len(int a);
   void ret(int a);



int main(){
   scanf("%d",&n); // @@ The problem states input is "n m", but this reads only n. It should be scanf("%d %d", &n, &m);. Also, subsequent logic assumes n is the count, but then decrements it incorrectly.
   scanf("%d",&m);
   int a,b;
   n--; // @@ This incorrectly reduces the number of vertices by 1 before reading edges or processing. The vertex count n should remain as read from input for adjacency matrix size and loop bounds.
   
   while(m--){
       scanf("%d%d",&a,&b);
       q[a][b]=1;
       q[b][a]=1;
   }
   
    len(0);
    printf("\n");
    int u=n;
    while(u>=0){
        flag[u--]=0;
        
    }
    ret(0);
      printf("\n");
    scanf("%d",&l);
    int uu=n;
        while(uu>=0){
        flag[uu--]=0;
        
    }
    flag[l]=1;
    len(0);
      printf("\n");
      int ue=n;
            while(ue>=0){
        flag[ue--]=0;
        
    }
    flag[l]=1;
    ret(0);   
    printf("\n");


    return 0;

}
void len(int a){
    
    int p;
    printf("%d ",a);
    flag[a]=1;
    for(p=0;p<=n;p++){ // @@ Since n was decremented in main, this loop bound is incorrect. It should iterate up to the original number of vertices - 1. If n is modified, the adjacency matrix access might also be out of bounds or miss vertices.
        if(q[a][p]==1&&flag[p]!=1){
            
            len(p);
            
            
            
        }
        
        
        
        
    }
}
void ret(int a){
    
    int head=0,i,tail=1,tmp,tall[200];
    tall[head]=a;
    while(head<=tail){

        tmp=tall[head];
        head++;

        if(flag[tmp]){
            continue;
            
        }
        else{
            printf("%d ",tmp);
            flag[tmp]=1;
            for(int p=0;p<=n;p++){ // @@ Same issue as in len: loop bound depends on modified n, leading to incorrect traversal range.
                if(q[tmp][p]==1&&flag[p]!=1){
                        
                    tall[tail++]=p;
                }
            }
            
            
            
        }
        
        
        
    }
    
    
    
    
    
    
}