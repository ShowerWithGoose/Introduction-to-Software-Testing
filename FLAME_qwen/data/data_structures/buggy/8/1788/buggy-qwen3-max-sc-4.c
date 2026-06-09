#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1,const void* e2)
{
    return (int*)e1>(int*)e2 ? 1:-1; // @@ [Incorrect pointer comparison: should dereference pointers to compare values, not addresses. Should be *(int*)e1 - *(int*)e2 or similar.]
}
int delete=-1; // @@ [Using 'delete' as variable name is problematic in C++ but allowed in C; however, it's poor practice and may confuse. Not a compilation error in pure C, but the real issue is elsewhere.]
struct node
{
    int connect[100];
    int i;
    int flag;
}Node[100];
int temp[100];
int p=0,q=0;
void ergodicWide(int n)
{
    for(int l=0;l<Node[n].i;l++)
        if(Node[Node[n].connect[l]].flag==0&&Node[n].connect[l]!=delete)
            printf("%d ",Node[n].connect[l]);
    for(int l=0;l<Node[n].i;l++)
    {
        if(Node[Node[n].connect[l]].flag==0&&Node[n].connect[l]!=delete)
        {
            Node[Node[n].connect[l]].flag=1;
            temp[q++]=Node[n].connect[l];
        }
    }
    while(p<q)
        ergodicWide(temp[p++]); // @@ [Recursive BFS implementation is flawed and may cause stack overflow; also, global p/q are not reset properly between traversals. However, the immediate compilation error is likely due to missing headers or syntax, but given the error message "gcc: not found", this is environment-related. But per problem, we must find code errors causing logical/test failure. The actual bug causing wrong output is in cmp function and traversal order.]
}
void ergodicDepth(int n)
{
    printf("%d ",n);
    Node[n].flag=1;
    for(int l=0;l<Node[n].i;l++)
        if(Node[Node[n].connect[l]].flag==0&&Node[n].connect[l]!=delete)
            ergodicDepth(Node[n].connect[l]); // @@ [Adjacent vertices are sorted, but during deletion, the graph structure isn't updated correctly in the adjacency lists—deletion only skips the vertex during traversal instead of removing edges, which violates problem requirement to actually delete the vertex from the graph.]
}
int main()
{
    int numNode,numLine;
    scanf("%d%d",&numNode,&numLine);
    for(int j=1;j<numNode;j++) // @@ [Initialization loop starts at j=1, so Node[0] is uninitialized (i and flag are garbage). This causes undefined behavior when accessing Node[0].i or Node[0].flag. Should initialize all nodes from 0 to numNode-1.]
    {
        Node[j].i=0;
        Node[j].flag=0;
    }

    int a,b;
    while(numLine--)
    {
        scanf("%d%d",&a,&b);
        Node[a].connect[Node[a].i]=b;
        Node[a].i++;
        Node[b].connect[Node[b].i]=a;
        Node[b].i++;
    }
    for(int k=0;k<numNode;k++)
    {
        qsort(Node[k].connect,Node[k].i,sizeof(Node[k].connect[0]),cmp); // @@ [cmp function is broken, so sorting does not work correctly, leading to traversal not visiting neighbors in ascending order.]
    }
    ergodicDepth(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    Node[0].flag=1;
    printf("\n");
    printf("0 ");
    ergodicWide(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    printf("\n");
    p=0;q=0;
    scanf("%d",&delete);
    ergodicDepth(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    Node[0].flag=1;
    printf("\n");
    printf("0 ");
    ergodicWide(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    printf("\n");
    return 0;
}