#include <stdio.h>
void visitS(int i);
void visitG(int i);
int flag[110],B,V,T[110][110],queue[110],k=0,f;
int main()
{
    int i,v1,v2,x;
    scanf("%d %d",&V,&B);
    for(i=1;i<=B;i++){
        scanf("%d %d",&v1,&v2);
        flag[v1]=1; // @@ The flag array is used for visited status in traversal, but here it is incorrectly initialized to 1 during input. It should be initialized to 0 or a separate array should be used for existence. More importantly, this overwrites any previous state if vertices repeat (though problem says no repeat edges, vertices appear multiple times). This logic is flawed because flag is later reset. However, the critical error is that `flag` is being used as both an "exists" marker and a "visited" marker inconsistently.
        flag[v2]=1; // @@ Same as above.
        T[v1][v2]=1;
        T[v2][v1]=1;
        printf("%d %d\n",v1,v2); // @@ This line prints the edges during input, which is not required by the output format. It causes Wrong Answer because of extra output.
    }
    scanf("%d",&x);
    for(i=0;i<=V-1;i++){ // @@ Missing initialization of flag array to 1 (unvisited) before the first DFS. The flag array contains garbage or values from the input loop (1 for existing vertices). If flag[i] was set to 1 in the input loop, DFS might work accidentally for existing nodes, but non-existing nodes (if any gaps) would be 0. However, standard practice is to initialize visited array. Let's look at visitS: it checks if flag[j]==1. In the input loop, flag was set to 1. So initially flag is 1 for all seen vertices. This might actually work for the first DFS if all vertices 0..V-1 are seen. But wait, if vertex 0 is not connected to some vertex in input? No, graph is connected. But what if V=3, edges 0-1, 1-2. Vertices 0,1,2 are set to 1. So flag is 1. This part might be okay logically for the first run, BUT the previous printf is definitely an error.
        flag[i]=1; // @@ This loop initializes flag to 1. This is correct for "unvisited" state given the logic in visitS (where 1 means unvisited/available). However, this block is MISSING before the first visitS(0) call in the original code structure provided in the prompt's "Source Code" section? Let's re-read the provided buggy source code carefully.
    } 
    // Looking at the provided source code in the prompt:
    // It goes: scanf -> loop(input) -> scanf(x) -> visitS(0).
    // There is NO initialization of flag to 1 for all vertices before visitS(0).
    // The flag array was only set to 1 for vertices appearing in edges.
    // If vertex 0 exists, flag[0] is 1.
    // The real issue is the extra printf in the input loop.
    
    visitS(0);
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    queue[k++]=0;
    printf("0 ");
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i);
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ The condition f<=k is incorrect for BFS queue processing. k is the tail index (next empty slot). The elements are in queue[0] to queue[k-1]. Using f<=k will process queue[k] which is uninitialized/garbage, leading to undefined behavior or out-of-bounds access. It should be f<k.
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i);
                flag[i]=0;
            }
        }
    }
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    flag[x]=0;
    visitS(0);
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    flag[x]=0;
    queue[k++]=0; // @@ The queue array and index k were not reset. k still holds the value from the previous BFS. This means we are appending to the old queue contents instead of starting fresh. k should be reset to 0.
    printf("0 ");
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i);
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ Same error as before: f<=k should be f<k. Also, k is now even larger because it wasn't reset.
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i);
                flag[i]=0;
            }
        }
    }
}
void visitS(int i)
{
    int j;
    printf("%d ",i);
    flag[i]=0;
    for(j=0;j<=V-1;j++){
        if((flag[j]==1)&&(T[i][j]==1)){
            visitS(j);
        }
    }
}
void visitG(int i)
{
    
}