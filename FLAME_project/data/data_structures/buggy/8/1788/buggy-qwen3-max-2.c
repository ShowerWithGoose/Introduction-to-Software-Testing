#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1,const void* e2)
{
    return (int*)e1>(int*)e2 ? 1:-1; // @@ [The comparison function for qsort is incorrect. It should cast to int and subtract, not compare pointers directly. This leads to undefined behavior and incorrect sorting.]
}
int delete=-1;
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
        ergodicWide(temp[p++]); // @@ [This recursive BFS implementation is flawed. It does not correctly simulate a queue-based BFS because it recursively processes nodes in DFS-like manner after initial level, leading to incorrect traversal order in general cases. However, in this specific test case it coincidentally works. The main issue is the extra space printed due to unconditional "0 " print before calling ergodicWide.]
}
void ergodicDepth(int n)
{
    printf("%d ",n);
    Node[n].flag=1;
    for(int l=0;l<Node[n].i;l++)
        if(Node[Node[n].connect[l]].flag==0&&Node[n].connect[l]!=delete)
            ergodicDepth(Node[n].connect[l]);
}
int main()
{
    int numNode,numLine;
    scanf("%d%d",&numNode,&numLine);
    for(int j=1;j<numNode;j++) // @@ [Initialization loop starts from j=1, so Node[0] is not initialized. This leaves Node[0].i and Node[0].flag with garbage values, causing undefined behavior.]
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
        qsort(Node[k].connect,Node[k].i,sizeof(Node[k].connect[0]),cmp);
    }
    ergodicDepth(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    Node[0].flag=1;
    printf("\n");
    printf("0 "); // @@ [Unconditionally prints "0 " before BFS, but if the graph had more complex structure or if 0 had no neighbors, this could cause duplication or incorrect output. In this test case, it causes an extra space at the end of BFS lines because ergodicWide also prints space after each number.]
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
    printf("0 "); // @@ [Same issue as above: unconditional "0 " print adds trailing space in BFS output.]
    ergodicWide(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    printf("\n"); // @@ [This final newline causes an extra blank line at the end, but the expected output doesn't have it. However, the main WA reason is trailing spaces in each line due to printf("%d ").]
    return 0;
}