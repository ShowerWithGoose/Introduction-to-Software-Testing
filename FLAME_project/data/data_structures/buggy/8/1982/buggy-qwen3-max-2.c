#include<stdio.h>
#include<stdlib.h>
#define MaxValue 1000
#define MaxVNum 100
#define MaxV    256
int n1,n2;
int item;
int Queue[1000];
int Queue1[1000];
int rear1=0,front1=0;
int rear=0,front=0;
int  Visited[105]={0};
int  Visited1[105]={0}; //标识顶点是否被访问过，n1为顶点数
typedef struct  edge{ 
       int  adjvex;
       int  wei;
       struct edge *next;
} ELink;
typedef struct ver{
       ELink *link;
} VLink;
VLink  G[MaxV];
//在链表尾插入一个节点
void insert(VLink *p, int a)
{
    ELink *r=NULL;
    ELink *t=NULL;
    ELink *q=NULL;
    if(p->link==NULL){
        r=(ELink*)malloc(sizeof(ELink));
        r->adjvex=a;
        r->next=NULL;
        p->link=r;
        return;
    }
    if(p->link->adjvex>a){
        r=(ELink*)malloc(sizeof(ELink));
        r->adjvex=a;
        r->next=p->link;
        p->link=r;
    }
    else{
    r=p->link->next;
    q=p->link;
    while(r!=NULL){
        if(r->adjvex>a){
            t=(ELink*)malloc(sizeof(ELink));
            t->adjvex=a;
            t->next=r;
            q->next=t;
            return;
        }
            r=r->next;
            q=q->next;
    }
    t=(ELink*)malloc(sizeof(ELink));
    t->adjvex=a;
    q->next=t;
    t->next=NULL;

}
}

void createGraph(VLink graph[]){
  int i,v1,v2;
  scanf("%d%d",&n1,&n2);
  for(i=0; i<n2; i++){
    scanf("%d%d",&v1,&v2);
      insert(&G[v1],v2);
      insert(&G[v2],v1);
    }
  }

void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    p = G[v].link;
    Visited[v] = 1;    //标识某顶点被访问过
     printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next){
         if( !Visited[p->adjvex] ){
             DFS(G, p->adjvex);
         }
         
}
}
void  travelDFS(VLink  G[], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++){
        if( !Visited[i] ) {
        DFS(G,i);
    }
}
}
void DFS1(VLink  G[ ], int v,int item)
{
    ELink  *p;
    p = G[v].link;
    Visited[v] = 1;    //标识某顶点被访问过
if(v!=item)
     printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next){
         if( !Visited[p->adjvex] &&p->adjvex!=item){
             DFS1(G, p->adjvex,item);
         }
         
}
}
void  travelDFS1(VLink  G[], int n,int item)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++){
        if( !Visited[i] ) {
        DFS1(G,i,item);
    }
}
}

void enQueue(int a){
  Queue[rear++]=a;
}
int deQueue(){
  return Queue[front++];
}
int isEmpty(){
  return front>rear;
}

void BFS(VLink  G[ ], int v)
{
    ELink  *p;
   printf("%d ",v); //访问当前顶点
    Visited[v] = 1; //标识某顶点被访问过
   enQueue(v); // 入口的第一个顶点入队
    while( !isEmpty()){  //  循环，直到队空为止 
         v = deQueue();  //取出队头元素
         p = G[v].link;//获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if( !Visited[p->adjvex] ) {
                   printf("%d ",p->adjvex); //访问当前顶点
                    Visited[p->adjvex] = 1; //标识某顶点被访问过
                    enQueue(p->adjvex); //邻接顶点依次分别入队
           }
     }
}
void  travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void enQueue1(int a){
  Queue1[rear1++]=a;
}
int deQueue1(){
  return Queue1[front1++];
}
int isEmpty1(){
  return front1>rear1;
}
void BFS1(VLink  G[ ], int v)
{
    ELink  *p;
    if(v!=item)
   printf("%d ",v); //访问当前顶点
    Visited1[v] = 1; //标识某顶点被访问过
   enQueue1(v); // 入口的第一个顶点入队
    while( !isEmpty1()){  //  循环，直到队空为止 
         v = deQueue1();  //取出队头元素
         p = G[v].link;//获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if( !Visited1[p->adjvex] ) {
                 
                   if(p->adjvex!=item)
               printf("%d ",p->adjvex);
                    Visited1[p->adjvex] = 1; //标识某顶点被访问过
                    enQueue1(p->adjvex);
                     //邻接顶点依次分别入队
           }
           
     }
}
void  travelBFS1(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited1[i] = 0;
    for(i=0; i<n; i++)
        if( !Visited1[i] &&i!=item) BFS1(G, i); @@ [The condition `i!=item` prevents starting BFS from vertex 0 if it were the deleted vertex, but more critically, the BFS1 function does not skip the deleted vertex when dequeuing and processing neighbors properly. However, the main error is that in `travelBFS1`, the call to `BFS1(G, i)` passes only one argument, but `BFS1` expects three: `VLink G[], int v, int item`. This causes undefined behavior or compilation error, but assuming it compiles due to old C rules, `item` would be garbage. However, looking at the function definition of `BFS1`, it uses global `item`, so maybe it's okay. But the real issue is in the BFS1 logic: when the starting vertex `v` is not the deleted vertex, it prints it, but then enqueues it even if it's the deleted vertex? Actually, the call in `travelBFS1` has `i!=item`, so `v` passed to BFS1 is never `item`. But inside BFS1, when processing neighbors, it checks `p->adjvex!=item` before printing, but still enqueues `p->adjvex` even if it is `item`? No: the enqueue happens unconditionally after the print check. Wait: the code does:
if (!Visited1[p->adjvex]) {
    if (p->adjvex != item) printf(...);
    Visited1[p->adjvex] = 1;
    enQueue1(p->adjvex);
}
So if p->adjvex == item, it marks it visited and enqueues it, but doesn't print. Then when dequeued, since v==item, it won't print (because of `if(v!=item) printf...`), but then it will process its neighbors, which may include valid vertices that haven't been visited. However, the problem states the graph remains connected after deletion, and we should not traverse through the deleted vertex at all. So the deleted vertex should be completely ignored: not enqueued, not used to reach other vertices. But here, the deleted vertex is enqueued and processed (its adjacency list is traversed), which is wrong. The condition to enqueue should also exclude the deleted vertex. So the error is that in BFS1, even if p->adjvex is the deleted vertex, it is marked visited and enqueued, which allows traversal through it. The correct approach is to skip the deleted vertex entirely: do not mark it visited, do not enqueue it. So the condition should be: if (!Visited1[p->adjvex] && p->adjvex != item). But in the current code, the condition for the if-block is only !Visited1[p->adjvex], and then inside, it checks p->adjvex!=item only for printing. So the enqueue and marking happen even for the deleted vertex. This is the bug.]

}
int main(){
        createGraph(G);
        scanf("%d",&item);
    travelDFS(G,n1);
    printf("\n");
    travelBFS(G,n1);
    printf("\n");
    travelDFS1(G,n1,item);
    printf("\n");
    travelBFS1(G,n1); @@ [The function call `travelBFS1(G,n1)` does not pass the `item` parameter, but the function `travelBFS1` is defined to take only two parameters. However, inside `travelBFS1`, it uses the global variable `item`, so this might be okay. But the real issue is in the BFS1 implementation as explained above. However, note that in the test case, the output for after deletion is correct: "0 2" for both DFS and BFS. So why is the expected output matching? Wait, the buggy output shown in the problem for the reference program had extra spaces, but the actual expected output doesn't have trailing spaces. However, the provided source code's output for the test case is:
0 1 2 
0 1 2 
0 2 
0 2
Which has trailing spaces and newlines. But the expected output is without trailing spaces. However, the problem says "Wrong Answer", and the example shows the outputs with spaces between numbers and no trailing space. But the main logical error is in BFS1: it processes the deleted vertex by enqueuing it and using it to traverse, which could lead to incorrect results in other test cases. However, in this specific test case, the deleted vertex is 1. When doing BFS after deletion, starting from 0 (since i=0 and 0!=1, so BFS1(G,0) is called). In BFS1:
- v=0, which is not item (1), so prints "0 ".
- Marks Visited1[0]=1, enqueues 0.
- Dequeues 0, then looks at neighbors: 1 and 2.
  - For neighbor 1: !Visited1[1] is true. Then, since 1==item, it doesn't print, but marks Visited1[1]=1 and enqueues 1.
  - For neighbor 2: !Visited1[2] is true, 2!=1, so prints "2 ", marks Visited1[2]=1, enqueues 2.
- Now queue has [1,2].
- Dequeue 1: v=1, which is item, so doesn't print. Then processes neighbors of 1: 0 and 2. But both are already visited, so nothing happens.
- Dequeue 2: v=2, not item, but it was already printed when it was first encountered as a neighbor of 0. However, in BFS, each vertex should be printed only once, when it is first visited (i.e., when it is enqueued). But in this code, the printing for non-starting vertices happens when they are first encountered (as neighbors), not when dequeued. Wait, look at BFS function (without deletion): 
   - It prints the starting vertex v at the beginning.
   - Then, when processing neighbors, if not visited, it prints the neighbor immediately and enqueues it.
This is actually a non-standard BFS printing order. Standard BFS prints when dequeuing. But the problem requires: "the traversal should start from vertex 0. When accessing adjacent vertices, visit them in ascending order". The reference program uses standard DFS and BFS (printing when visited, i.e., when first discovered). However, in the provided source code, the BFS implementation prints the starting vertex, then when discovering neighbors, prints them immediately. This is acceptable as long as the order is correct. But in the after-deletion BFS, the output is "0 2", which is correct. However, the issue is that vertex 1 is enqueued and processed, which is unnecessary and could cause issues if the graph were larger. But in this test case, it doesn't affect the output. However, the problem states the graph is connected after deletion, so the deleted vertex is not needed. The real error that causes "Wrong Answer" in general is that the BFS1 function enqueues the deleted vertex, which might lead to visiting vertices through it in some cases? But the problem says the graph is connected after deletion, so there should be no need to go through the deleted vertex. However, the code marks the deleted vertex as visited and enqueues it, which is logically incorrect. But in this test case, it doesn't produce wrong output. Another possibility: the output has trailing spaces. The expected output does not have trailing spaces, but the program outputs a space after each number, including the last one. For example, "0 1 2 " instead of "0 1 2". The problem's expected output is without trailing space. So the error is in the printing: it prints a space after every vertex, including the last one. The reference program in the problem description also has this issue, but the expected output doesn't have trailing spaces. So the judge likely trims or expects no trailing space. Therefore, the main error is the trailing space in the output. However, the problem says the reference program is correct, and the reference program also prints with trailing space. But the expected output shown does not have trailing space. This is a common issue. Looking at the test case input and expected output:

Expected Output:
0 1 2
0 1 2
0 2
0 2

Each line has numbers separated by spaces, no trailing space.

But the program outputs:
0 1 2[space]
0 1 2[space]
0 2[space]
0 2[space]

So the trailing space causes "Wrong Answer".

However, the problem asks to identify the location of errors in the program below (the second program, not the reference). And the error type is "Wrong Answer".

But the instructions say: "If you think an error may occur on a particular line, add @@ symbol directly after that line and explain the reason for the error."

The trailing space is caused by the printf statements that print "%d " (with a space). This happens in multiple places:

In DFS: printf("%d ",v);
In DFS1: printf("%d ",v);
In BFS: printf("%d ",v); and printf("%d ",p->adjvex);
In BFS1: printf("%d ",v); and printf("%d ",p->adjvex);

But the problem is that the last number in each traversal also has a trailing space.

However, the reference program also does this, but the problem says the reference program is correct. This is confusing.

Looking back at the problem statement: "For each traversal, the vertices should be printed in a single line, separated by spaces."

It doesn't specify no trailing space, but typically online judges require no trailing space.

But the expected output shown has no trailing space.

So the error is the trailing space.

But the problem says the reference program is correctly implemented, and the reference program also prints with trailing space. Let me check the reference program's output for the test case:

Reference program output as given in the problem:
0 1 2 
0 1 2 
0 2 
0 2

But the expected output is:
0 1 2
0 1 2
0 2
0 2

So the reference program's output has trailing spaces and a newline, but the expected output does not have trailing spaces.

However, the problem says the reference program is correct, which suggests that maybe the trailing space is acceptable, or the example output formatting is just for illustration.

But the "Buggy Output" shown for the reference program includes trailing spaces, and the expected output does not, yet the problem says the reference program is correct. This is a contradiction.

Alternatively, the real error in the provided source code (the second program) is in the BFS1 function's logic, as explained earlier, but in the given test case it works by accident.

However, the problem states: "the program failed" on the test case input, and shows the buggy output as having the same numbers as expected but with trailing spaces. But the expected output is shown without trailing spaces.

Given that, the most likely reason for "Wrong Answer" is the trailing space.

But the problem asks to annotate the source code with @@ on the lines where errors occur.

The printf statements that print a space after the number are the cause.

However, there are many such lines.

But the problem might consider the trailing space as the error.

Alternatively, in the main function, the last call is `travelBFS1(G,n1);` but it should be `travelBFS1(G,n1,item);` — however, the function `travelBFS1` is defined to take two parameters, and it uses the global `item`, so it's okay.

Another error: in the BFS function (without deletion), the printing is done when the vertex is first discovered (for neighbors) and at the start for the initial vertex. But the order might be correct.

But let's simulate the BFS without deletion for the test case:

Graph: 0-1, 1-2, 0-2.

BFS starting from 0:
- Print "0 "
- Enqueue 0.
- Dequeue 0, then look at neighbors: 1 and 2 (in ascending order, because the insert function inserts in sorted order).
  - Visit 1: not visited, print "1 ", enqueue 1.
  - Visit 2: not visited, print "2 ", enqueue 2.
- Dequeue 1: look at neighbors 0 (visited), 2 (visited) — nothing.
- Dequeue 2: look at neighbors 0 (visited), 1 (visited) — nothing.
Output: "0 1 2 "

Which is correct order.

After deletion of 1:
- Start from 0 (only component).
- Print "0 "
- Enqueue 0.
- Dequeue 0, neighbors: 1 and 2.
  - 1: not visited, but is item, so don't print, but mark visited and enqueue.
  - 2: not visited, print "2 ", enqueue.
- Dequeue 1: don't print, process neighbors: 0 (visited), 2 (visited).
- Dequeue 2: already printed.
Output: "0 2 "

So the output is correct in content, but has trailing space.

Given that the expected output has no trailing space, and the judge likely requires no trailing space, the error is the trailing space in the printf statements.

But which lines to annotate?

Every printf that prints a vertex followed by a space.

However, the problem might expect us to notice that the BFS1 function has a logical error in enqueuing the deleted vertex, which could cause issues in other test cases, even if not in this one.

But the problem says: "based on the problem description, the reference program correctly implemented, the test case inputs that the program failed, the program's output, and the expected output"

The program's output for the test case is:
0 1 2 
0 1 2 
0 2 
0 2

Expected:
0 1 2
0 1 2
0 2
0 2

The only difference is the trailing space on each line.

Therefore, the error is the trailing space.

But how to fix it? Usually, we print the first vertex without a space, and subsequent vertices with a preceding space, or build a string.

Since the problem asks to identify the location, we should annotate every printf that prints "%d ".

However, the instructions say: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

So for each printf that outputs a space after the number, we add @@.

Let's list them:

1. In DFS: printf("%d ",v);
2. In DFS1: printf("%d ",v);
3. In BFS: printf("%d ",v);
4. In BFS: printf("%d ",p->adjvex);
5. In BFS1: printf("%d ",v);
6. In BFS1: printf("%d ",p->adjvex);

But also, the travel functions call these, so the output has trailing space.

However, the problem might consider this as the error.

Alternatively, the reference program also has this, but the problem says the reference program is correct, which is confusing.

Wait, looking at the reference program's code:

In DFS: printf("%d ",v);
In BFS: printf("%d ",v);

So it also has trailing space.

But the problem states: "the reference program correctly implemented", and then shows its output as having trailing space, and the expected output without, but says the reference program is correct.

This suggests that the trailing space might be acceptable, and the real error is elsewhere.

Let me read the problem again: "the program failed" — meaning the second program (the source code provided) failed on the test case.

The second program's output is shown as:
0 1 2 
0 1 2 
0 2 
0 2

And expected:
0 1 2
0 1 2
0 2
0 2

But perhaps the judge is sensitive to whitespace.

However, there's another possibility: in the main function, the last line is:

    travelBFS1(G,n1);

But the function travelBFS1 is defined as:

void  travelBFS1(VLink  G[ ], int n)

So it's correct.

But wait, in the BFS1 function, when the deleted vertex is encountered as a neighbor, it is marked as visited and enqueued, which is wrong because we should not traverse through it. In a different graph, this could cause a vertex to be missed.

For example, consider a graph: 0-1-2-3, and delete vertex 1. The graph after deletion has two components: [0] and [2,3]. But the problem states: "The graph is connected both before and after deleting the specified vertex." So this example is invalid.

Given the constraints, the graph remains connected after deletion, so there is a path between any two vertices not including the deleted vertex.

In the test case, after deleting 1, 0 and 2 are directly connected, so it's fine.

But in the BFS1 implementation, when at vertex 0, it sees neighbor 1 (deleted) and neighbor 2. It marks 1 as visited and enqueues it. Then when processing 1, it looks at its neighbors, but they are already visited, so no harm.

So for this test case, it works.

Then why "Wrong Answer"?

The only difference is the trailing space.

Perhaps the online judge requires no trailing space.

Given that, I will annotate every printf that prints a space after the number.

But the problem says "add @@ symbol directly after that line", so for each such printf line.

Let's do it.