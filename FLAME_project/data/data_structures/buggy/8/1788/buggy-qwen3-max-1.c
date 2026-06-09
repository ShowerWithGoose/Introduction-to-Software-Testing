#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1,const void* e2)
{
    return (int*)e1>(int*)e2 ? 1:-1; // @@ [The comparison function for qsort is incorrect. It should cast to int and subtract: *(int*)e1 - *(int*)e2. The current version returns -1 even when e1 > e2 due to pointer comparison and ternary logic, leading to unstable/incorrect sorting.]
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
    for(int j=1;j<numNode;j++) // @@ [Initialization loop starts from j=1, so Node[0] is uninitialized. This leads to undefined behavior when accessing Node[0].i or Node[0].connect. Should initialize all nodes from j=0 to numNode-1.]
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
    printf("0 "); // @@ [Hardcoded "0 " output before BFS causes duplication if BFS starts correctly. The BFS function ergodicWide already prints neighbors of 0, but since 0 is pre-printed, it's okay only if ergodicWide doesn't print 0 again. However, the real issue is that Node[0] wasn't initialized, so its data may be garbage, but the immediate visible error is extra space or formatting. However, the main logical errors are earlier. But note: the expected output has no trailing space, but this prints "0 " then more numbers with space — may cause presentation error. However, the test case matches output format-wise, so primary bugs are in cmp and initialization.]
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
    printf("\n"); // @@ [This final newline causes an extra blank line at the end, but the expected output ends after the last sequence. However, the sample expected output shows four lines, and this outputs five (including final \n). But the problem says "output the sequences" in four lines — so trailing newline may be acceptable. The core errors are in cmp and uninitialized Node[0].]
    return 0;
}