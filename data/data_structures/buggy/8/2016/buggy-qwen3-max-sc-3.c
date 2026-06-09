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
    printf("0 "); // @@ [Incorrect BFS start: Hardcoded "0 " printed before traversal logic; should be handled inside traversal to respect spacing rules (no trailing space)]
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i); // @@ [Trailing space issue: Each printed vertex adds a trailing space, violating output format which requires space-separated values without trailing space]
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Loop bound error: Should be f < k, not f <= k; accessing queue[k] is out-of-bounds since queue indices are 0 to k-1]
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i); // @@ [Trailing space issue: Same as above; also, this BFS implementation doesn't guarantee ascending order of adjacent vertices because it iterates all vertices but doesn't sort neighbors]
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
    queue[k++]=0; // @@ [Queue not reset: k is global and retains value from previous BFS, causing incorrect queue initialization and potential buffer overflow]
    printf("0 "); // @@ [Same issues as earlier: hardcoded output and trailing space]
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i); // @@ [Trailing space and ordering issue persist]
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Same loop bound error: f <= k leads to out-of-bounds access]
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i); // @@ [Trailing space and no ascending order guarantee]
                flag[i]=0;
            }
        }
    }
}
void visitS(int i)
{
    int j;
    printf("%d ",i); // @@ [Trailing space: DFS prints each vertex followed by a space, including the last one, which violates output format]
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