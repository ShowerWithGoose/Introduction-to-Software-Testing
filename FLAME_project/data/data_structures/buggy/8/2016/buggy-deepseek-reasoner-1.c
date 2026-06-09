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
        printf("%d %d\n",v1,v2);  // @@ Error: This line prints the input edges, which is not part of the required output. It should not be present.
    }
    scanf("%d",&x);
    visitS(0);
    printf("\n");
    for(i=0;i<=V-1;i++){
        flag[i]=1;
    }
    queue[k++]=0;
    printf("0 ");  // @@ Error: Prints the starting vertex with a trailing space, causing a trailing space in the BFS output. Should print the first vertex without a space afterward.
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if(T[0][i]==1){
            queue[k++]=i;
            printf("%d ",i);  // @@ Error: Prints each neighbor with a trailing space, contributing to a trailing space after the last vertex in BFS output.
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i);  // @@ Error: Prints with a trailing space, causing trailing spaces in intermediate BFS outputs.
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
    queue[k++]=0;  // @@ Error: The global variable 'k' was not reset to 0 before this second BFS, leading to incorrect queue indexing and potential out-of-bounds.
    printf("0 ");  // @@ Error: Same trailing space issue as in the first BFS.
    flag[0]=0;
    for(i=0;i<=V-1;i++){
        if((T[0][i]==1)&&(flag[i]==1)){
            queue[k++]=i;
            printf("%d ",i);  // @@ Error: Same trailing space issue.
            flag[i]=0;
        }
    }
    for(f=0;f<=k;f++){
        for(i=0;i<=V-1;i++){
            if((T[queue[f]][i]==1)&&(flag[i]==1)){
                queue[k++]=i;
                printf("%d ",i);  // @@ Error: Same trailing space issue.
                flag[i]=0;
            }
        }
    }
}
void visitS(int i)
{
    int j;
    printf("%d ",i);  // @@ Error: This always prints a space after the vertex, including the last one, causing a trailing space in DFS output. Should not print a space after the last vertex.
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