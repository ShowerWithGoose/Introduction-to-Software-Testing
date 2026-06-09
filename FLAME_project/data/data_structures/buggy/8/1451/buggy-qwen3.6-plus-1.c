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
   scanf("%d",&n); // @@ The input format specifies "number of vertices n and number of edges m", but the code reads only one integer into n first. It should read both n and m. Also, subsequent logic uses 'n' as the max vertex index, but reduces it prematurely.
   scanf("%d",&m);
   int a,b;
   n--; // @@ This decrements the number of vertices. If the original input was 3 vertices (0,1,2), n becomes 2. The loops later use p<=n, which means it iterates 0 to 2. This part might be okay if n is treated as max index, but the initial read was wrong. More critically, the adjacency matrix q is sized [200][200], but the logic for clearing flags and iterating depends on this modified n.
   
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
    for(p=0;p<=n;p++){
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
            for(int p=0;p<=n;p++){
                if(q[tmp][p]==1&&flag[p]!=1){
                        
                    tall[tail++]=p;
                }
            }
            
            
            
        }
        
        
        
    }
    
    
    
    
    
    
}