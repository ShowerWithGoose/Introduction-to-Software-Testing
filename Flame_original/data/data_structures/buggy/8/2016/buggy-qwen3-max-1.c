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
        printf("%d %d\n",v1,v2); // @@ [Unnecessary output: the problem does not require printing input edges, which corrupts the expected output format]
    }
    scanf("%d",&x);
    visitS(0);
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    queue[k++]=0;
    printf("0 "); // @@ [Incorrect BFS start: prints "0 " unconditionally even if vertex 0 is deleted later; also, BFS logic is flawed and duplicates traversal code instead of using a proper function]
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i);
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Loop condition error: should be f < k, not f <= k, leading to out-of-bound access and incorrect traversal]
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
    queue[k++]=0; // @@ [Array reuse error: 'k' is not reset to 0 before reusing 'queue', causing previous BFS data to remain and corrupt the next BFS]
    printf("0 ");
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i);
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Same loop condition error as before: f <= k causes invalid memory access and wrong traversal]
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
    
} // @@ [Unused function: visitG is declared but never used, indicating incomplete or incorrect implementation of BFS as a reusable function]