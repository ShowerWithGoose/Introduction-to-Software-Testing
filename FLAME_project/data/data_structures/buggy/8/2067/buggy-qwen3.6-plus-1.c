#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int a[101][101]={{0}};
int visit[101]={0};
int que[101]={0};
void g0(int n){
    for(int i=0;i<n;i++){
        visit[i]=0;
        que[i]=0;
    }
}
void DFS(int n,int k){
    visit[k]=1;
    printf("%d ",k);   
    for(int i=0;i<n;i++){
        if(visit[i]==0&&a[k][i]==1){
            DFS(n,i);
        }
    }
}
void tDFS(int n){
    for(int i=0;i<n;i++){
        if(visit[i]==0){
            DFS(n,i);
        }
    }
    printf("\n");
}

void tBFS(int n)
{
    int i,head=0,tail=1,tmp;    
    que[head]=0;    
    while(head<=tail)    
    {
        tmp=que[head];
        head++;            
        if(visit[tmp])    continue; // @@ The condition checks if the node was visited, but 'visit' array is not updated when nodes are added to the queue, only when processed. This logic is flawed for standard BFS where we mark visited upon enqueue to prevent duplicates. However, the bigger issue is below.
        else
        {
            printf("%d ",tmp);        
            visit[tmp]=1;        
            for(i=0;i<n;i++)
                if (a[tmp][i] && !visit[i])    
                    que[tail++]=i;        
        }
    }
} // @@ The BFS implementation has a logical error in how it handles the 'visit' array and queue. It marks nodes as visited only when they are dequeued and processed. This can lead to the same node being added to the queue multiple times if it's reachable via multiple paths before it's processed. More critically, the loop condition `head<=tail` and the logic inside might process nodes incorrectly or infinitely if not careful, but the primary issue causing the wrong output "0 1 2 0 2" instead of "0 1 2" is likely due to the `visit` array not being reset properly or the BFS logic allowing re-visits or printing duplicates because `visit` is checked *after* dequeue. In the specific failing case, node 0 is printed, then 1 and 2 are enqueued. When 1 is processed, it sees 0 (visited) and 2 (not visited yet? No, 2 is already in queue but not marked visited). If 2 is not marked visited when enqueued, it might be enqueued again by node 0 or 1. Let's trace: Start q=[0], head=0, tail=1. Process 0: print 0, visit[0]=1. Neighbors 1, 2. q=[0, 1, 2], tail=3. head=1. Process 1: print 1, visit[1]=1. Neighbors 0 (visited), 2 (!visit[2] is true because visit[2] is still 0). So 2 is enqueued again. q=[0, 1, 2, 2], tail=4. head=2. Process 2: print 2, visit[2]=1. Neighbors 0 (visited), 1 (visited). head=3. Process 2 (the duplicate): visit[2] is now 1, so `if(visit[tmp]) continue` skips it. head=4. Loop ends. Output: 0 1 2. Wait, the buggy output is `0 1 2 0 2`. This suggests something else. 
// Actually, looking at the buggy output `0 1 2 0 2`, it seems like the BFS is running on the graph *before* deletion for the second line? No, the code structure is: DFS(before), BFS(before), read v, DFS(after), BFS(after).
// The expected output is:
// 0 1 2 (DFS before)
// 0 1 2 (BFS before)
// 0 2   (DFS after deleting 1)
// 0 2   (BFS after deleting 1)
//
// The buggy output is:
// 0 1 2 
// 0 1 2 0 2 
// 0 2
//
// The third line is missing in buggy output? No, the buggy output has 3 lines. The expected has 4.
// Ah, the `tDFS` function prints a newline. The `tBFS` function does NOT print a newline.
// Line 1: tDFS(n) -> "0 1 2 \n"
// Line 2: tBFS(n) -> "0 1 2 " (no newline)
// Then scanf("%d", &v) reads the next integer. If the input buffer has "1\n", scanf consumes 1.
// Then g0(n), visit[v]=1, tDFS(n).
// If tBFS didn't print a newline, the output of the next tDFS will append to the same line.
// So Line 2 in output becomes: "0 1 2 " + "0 2 \n" -> "0 1 2 0 2 \n". This matches the buggy output's second line!
// And the third line is just the last BFS? No, the buggy output only has 3 lines.
// Expected:
// L1: 0 1 2
// L2: 0 1 2
// L3: 0 2
// L4: 0 2
//
// Buggy:
// L1: 0 1 2 
// L2: 0 1 2 0 2 
// L3: (empty or missing?)
//
// The problem is that `tBFS` does not print a newline at the end.
    printf("\n"); // @@ Missing newline print after BFS traversal causes subsequent output to merge into the same line.
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    g0(n);
    tDFS(n);
    g0(n);
    tBFS(n);
    int v;
    scanf("%d",&v);
    g0(n);
    visit[v]=1;
    tDFS(n);
    g0(n);
    visit[v]=1;
    tBFS(n);
    return 0;
}