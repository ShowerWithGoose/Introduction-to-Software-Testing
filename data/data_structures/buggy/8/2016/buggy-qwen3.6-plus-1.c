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
        flag[v1]=1;
        flag[v2]=1;
        T[v1][v2]=1;
        T[v2][v1]=1;
        printf("%d %d\n",v1,v2); // @@ Unnecessary output during input reading, violates the specified output format.
    }
    scanf("%d",&x);
    visitS(0); // @@ flag array is not explicitly initialized to 1 (unvisited) for all vertices before the first DFS, which may cause incorrect traversal.
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    queue[k++]=0;
    printf("0 "); // @@ Prints a trailing space after the vertex, which may cause format mismatch; vertices should be separated by spaces without a trailing space.
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i); // @@ Prints a trailing space after each vertex, potentially violating the exact output format.
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i); // @@ Prints a trailing space after each vertex, potentially violating the exact output format.
                flag[i]=0;
            }
        }
    }
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    flag[x]=0;
    queue[k++]=0; // @@ Variable k is not reset to 0 before the second BFS, causing the queue to use incorrect indices and process stale data from the first BFS.
    printf("0 "); // @@ Prints a trailing space after the vertex, potentially violating the exact output format.
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i); // @@ Prints a trailing space after each vertex, potentially violating the exact output format.
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i); // @@ Prints a trailing space after each vertex, potentially violating the exact output format.
                flag[i]=0;
            }
        }
    }
}
void visitS(int i)
{
    int j;
    printf("%d ",i); // @@ Prints a trailing space after each vertex, potentially violating the exact output format.
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