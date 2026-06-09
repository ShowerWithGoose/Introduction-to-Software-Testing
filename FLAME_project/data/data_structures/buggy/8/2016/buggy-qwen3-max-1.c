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
        printf("%d %d\n",v1,v2); // @@ [Unnecessary output: The problem does not require printing the input edges. This causes extra lines in output, leading to wrong answer.]
    }
    scanf("%d",&x);
    visitS(0);
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    queue[k++]=0;
    printf("0 "); // @@ [Incorrect BFS start: Always prints "0 " even if vertex 0 is deleted later; also, this hardcoded print breaks consistency with DFS format and may cause spacing issues. More critically, BFS logic is flawed.]
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i);
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Loop condition error: Should be f < k, not f <= k. Accessing queue[k] is out-of-bounds since queue indices are 0 to k-1. Also, k is never reset between BFS runs, causing carry-over from previous traversal.]
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
    queue[k++]=0; // @@ [k is not reset to 0 before second BFS, so queue starts at previous k value, causing incorrect queue initialization and potential buffer overflow or skipped vertices.]
    printf("0 ");
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i);
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){ // @@ [Same loop condition error as before: f <= k instead of f < k, and k still carries over from prior traversals.]
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
    printf("%d ",i); // @@ [Trailing space issue: Each DFS call prints a space after the vertex, including the last one. Expected output has no trailing space. Also, DFS visits neighbors in ascending order? Loop from 0 to V-1 is correct for order, but global flag misuse affects correctness.]
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