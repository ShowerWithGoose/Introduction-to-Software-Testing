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
        printf("%d %d\n",v1,v2); // @@ [This debug print statement should not be in the final output; it causes extra lines in output that do not match expected format]
    }
    scanf("%d",&x);
    visitS(0);
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    queue[k++]=0;
    printf("0 "); // @@ [Hardcoded initial print assumes vertex 0 is always first, but does not handle formatting correctly if traversal logic changes or if multiple components exist (though graph is connected). Also, inconsistent with DFS which prints space after each including last.]
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i);
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Loop condition f<=k may access queue out of current valid range because k increases inside loop; should be f < k]
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
    queue[k++]=0; // @@ [k is not reset to 0 before reusing queue for second BFS, causing previous values to remain and corrupt traversal]
    printf("0 ");
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i);
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Same issue as earlier: f<=k instead of f < k leads to potential out-of-bounds access and incorrect traversal]
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
    printf("%d ",i); // @@ [Prints trailing space after last vertex, which may not match expected output format requiring space-separated values without trailing space]
    flag[i]=0;
    for(j=0;j<=V-1;j++){
        if((flag[j]==1)&&(T[i][j]==1)){
            visitS(j);
        }
    }
}
void visitG(int i)
{
    
} // @@ [Unused function; not an error per se but indicates incomplete or incorrect implementation plan]