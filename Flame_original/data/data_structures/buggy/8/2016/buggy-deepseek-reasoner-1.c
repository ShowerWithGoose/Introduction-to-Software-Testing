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
        flag[v1]=1; // @@ Setting flag to mark vertex existence; but flag is later used as visited marker (0=unvisited, 1=visited). This overwrites default zero and may cause incorrect visited status for vertices not yet visited. Should not set flag here.
        flag[v2]=1; // @@ Same issue as above.
        T[v1][v2]=1;
        T[v2][v1]=1;
        printf("%d %d\n",v1,v2); // @@ Extra output: prints edge lines, which are not part of the required output. Should be removed.
    }
    scanf("%d",&x);
    visitS(0);
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    queue[k++]=0; // @@ k is not reset to 0 before this BFS; if previous traversal left k with a value, this will start appending at an incorrect index, causing out-of-bounds and duplicate printing. Should set k=0 before using queue.
    printf("0 ");
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i); // @@ Trailing space after each vertex; leads to extra space at end of line. Should handle spacing without trailing space.
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ Initial value of k may be stale from previous traversal; loop will process old indices and possibly add invalid neighbors. Should reset k before this BFS.
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i); // @@ Trailing space issue.
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
    queue[k++]=0; // @@ Same as line 23: k not reset, will continue appending to old queue.
    printf("0 ");
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i); // @@ Trailing space.
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ Same as line 33.
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i); // @@ Trailing space.
                flag[i]=0;
            }
        }
    }
} // @@ Missing newline after second BFS output; should print "\n" after the loop to separate from next output (or end of program). The expected output requires a newline after each traversal line.
void visitS(int i)
{
    int j;
    printf("%d ",i); // @@ Prints trailing space after each vertex; should print first vertex without leading space, then space before subsequent vertices. This produces an extra space at the end of DFS lines.
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