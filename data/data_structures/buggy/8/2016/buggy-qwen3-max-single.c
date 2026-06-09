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
        printf("%d %d\n",v1,v2); // @@ [Unnecessary output: The problem does not require printing input edges, which causes extra lines in output and mismatches expected format]
    }
    scanf("%d",&x);
    visitS(0);
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    queue[k++]=0;
    printf("0 "); // @@ [Incorrect BFS start formatting: Should not hardcode "0 " here; traversal must follow general BFS logic and spacing rules consistent with DFS (space-separated, no trailing space)]
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i); // @@ [Trailing space issue: Printing space after each vertex leads to trailing space at end of line, violating output format]
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Loop bound error: 'f <= k' may access queue out of current valid range; should be 'f < k' since k is the next insertion index]
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i); // @@ [Trailing space issue: Same as above, causes trailing space]
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
    queue[k++]=0; // @@ [Queue not reset: 'k' retains value from previous BFS, causing incorrect queue state; should reset k=0 before reusing queue]
    printf("0 "); // @@ [Same hardcoded output and trailing space issues as earlier BFS]
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i); // @@ [Trailing space and queue reuse without reset compound errors]
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Same loop bound error: f <= k instead of f < k]
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i); // @@ [Trailing space and potential out-of-bound queue access]
                flag[i]=0;
            }
        }
    }
}
void visitS(int i)
{
    int j;
    printf("%d ",i); // @@ [Trailing space: DFS also prints trailing space, violating output format which requires space-separated values with no trailing space]
    flag[i]=0;
    for(j=0;j<=V-1;j++){
        if((flag[j]==1)&&(T[i][j]==1)){
            visitS(j);
        }
    }
}
void visitG(int i)
{
    
} // @@ [Unused function: visitG is declared and defined but never used; while not a direct cause of wrong output, it indicates incomplete or confused implementation]