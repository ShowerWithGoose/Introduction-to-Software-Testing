#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1,const void* e2)
{
    return *(int*)e1 - *(int*)e2; // @@ [The original comparison logic (int*)e1>(int*)e2 compares pointer addresses, not integer values. This leads to incorrect sorting of adjacency lists, violating the requirement to visit adjacent vertices in ascending order.]
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
        ergodicWide(temp[p++]);
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
    for(int j=1;j<numNode;j++)
    {
        Node[j].i=0;
        Node[j].flag=0;
    }
    Node[0].i = 0; // @@ [Vertex 0's neighbor count and flag are not initialized in the loop above (which starts at j=1). This leaves Node[0].i with garbage value, causing undefined behavior when adding edges or sorting.]
    Node[0].flag = 0; // @@ [Vertex 0's flag is not initialized, leading to undefined behavior during traversal checks.]

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