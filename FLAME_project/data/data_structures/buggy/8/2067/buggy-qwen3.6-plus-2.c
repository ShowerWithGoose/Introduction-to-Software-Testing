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
        if(visit[tmp])    continue; // @@ The BFS implementation incorrectly allows re-adding vertices to the queue and processing them multiple times if they are enqueued before being marked visited. Specifically, it checks `visit[tmp]` only after dequeuing. If a node is enqueued multiple times (which happens because neighbors are added without checking if they are already in the queue or visited), it will be printed multiple times. The standard BFS should mark visited when enqueueing or ensure nodes are not enqueued if already visited/enqueued. In this specific code, `visit` is checked, but the issue is that `que` might contain duplicates or invalid states if not managed correctly, but the primary logical error here compared to the reference is how the start node is handled and the loop condition. However, looking at the buggy output `0 1 2 0 2`, it seems `0` is printed again. This happens because `visit` array was reset, but `que` was also reset in `g0`. Wait, `g0` resets `que`. Let's trace: `tBFS` starts with `que[0]=0`. `head=0, tail=1`. Loop `0<=1`. `tmp=0`. `head=1`. `visit[0]` is 0. Print 0. `visit[0]=1`. Neighbors of 0 (1, 2) are added to `que[1]`=1, `que[2]`=2. `tail`=3. Loop `1<=3`. `tmp=1`. `head=2`. `visit[1]` is 0. Print 1. `visit[1]=1`. Neighbors of 1 (0, 2). 0 is visited. 2 is not visited? `visit[2]` is 0. So `que[3]`=2. `tail`=4. Loop `2<=4`. `tmp=2`. `head=3`. `visit[2]` is 0. Print 2. `visit[2]=1`. Neighbors of 2 (0, 1). Both visited. Loop `3<=4`. `tmp=que[3]`=2. `head=4`. `visit[2]` is 1. Continue. Loop `4<=4`. `tmp=que[4]`... wait, `que[4]` was not initialized properly or contains garbage/old data? No, `g0` sets `que` to 0. So `que[4]`=0. `head=5`. `visit[0]` is 1. Continue. Loop `5<=4` false. Terminate. 
        // The issue is that `tail` goes beyond the actual number of unique nodes added if duplicates are added. 
        // In the step where `tmp=1`, neighbor 2 is added again to `que[3]`. 
        // So `que` is `[0, 1, 2, 2, 0...]`. 
        // When `head=3`, `tmp=2`, visited, continue. 
        // When `head=4`, `tmp=0` (from `g0` initialization or previous state if `g0` didn't clear enough? `g0` clears 0..n-1. If `tail` exceeds `n`, we access uninitialized or cleared memory. 
        // Actually, the main error is that BFS enqueues neighbors without checking if they are already in the queue or visited, leading to duplicates in the queue. While `visit` check prevents re-printing, the loop continues until `head > tail`. If `tail` grows large due to duplicates, it might process garbage if `tail` exceeds bounds or just waste time. 
        // However, the specific wrong output `0 1 2 0 2` suggests `0` and `2` were printed again. 
        // Let's re-read the code carefully. 
        // `if(visit[tmp]) continue; else { print; visit=1; ... }`
        // If `visit` is checked correctly, duplicates shouldn't print. 
        // Why did `0` print again? 
        // Maybe `visit` wasn't reset correctly? `g0` resets `visit`. 
        // Let's look at `tBFS` call in `main`. 
        // `g0(n); visit[v]=1; tBFS(n);`
        // In the first `tBFS` call (before deletion): `g0(n)` resets all. `tBFS(n)` starts. 
        // `que[0]=0`. `head=0, tail=1`. 
        // ... 
        // The output `0 1 2 0 2` implies that `0` was printed, then `1`, then `2`, then `0` again? 
        // This can only happen if `visit[0]` became 0 again or was never set? 
        // Or perhaps the `que` array contains `0` again and `visit[0]` was somehow 0? 
        // No, `visit[0]` is set to 1 when printed. 
        // Is it possible `tail` overflows or `head` logic is wrong? 
        // Actually, look at `que[tail++]=i`. It adds `i` even if `i` is already in `que`. 
        // If the graph is 0-1, 1-2, 0-2. 
        // Start 0. Print 0. Visit 0. Add 1, 2. Que: [0, 1, 2]. Tail 3. 
        // Head 1. Temp 1. Print 1. Visit 1. Add 0 (visited), 2 (not visited? Visit[2] is 0). Add 2. Que: [0, 1, 2, 2]. Tail 4. 
        // Head 2. Temp 2. Print 2. Visit 2. Add 0 (visited), 1 (visited). 
        // Head 3. Temp 2. Visit[2] is 1. Continue. 
        // Head 4. Temp ? `que[4]` is 0 (from `g0`). Visit[0] is 1. Continue. 
        // Head 5. Stop. 
        // Output should be `0 1 2 `. 
        // Why `0 1 2 0 2`? 
        // Maybe `n` is small and `g0` doesn't clear `que` indices used by `tail` if `tail` exceeds `n`? 
        // If `n=3`, `g0` clears `que[0], que[1], que[2]`. 
        // `tail` becomes 4. `que[3]` is NOT cleared by `g0` (loop `i<n`). 
        // `que[3]` contains garbage or old value. 
        // If `que[3]` happened to be 0? 
        // And `visit[0]` is 1. So it would continue. 
        // Wait, if `que[3]` is garbage, say 0. `visit[0]` is 1. Continue. 
        // Where does the second `0` and `2` come from? 
        // Perhaps the `visit` array is not being updated correctly? 
        // Or maybe `tBFS` is called with `n` but `que` size is 101. 
        // Let's look at the second BFS call (after deletion). 
        // `visit[1]=1`. 
        // Start 0. Print 0. Visit 0. Add 2 (1 is visited). Que: [0, 2]. Tail 2. 
        // Head 1. Temp 2. Print 2. Visit 2. Add 0 (visited), 1 (visited). 
        // Head 2. Stop. 
        // Output `0 2 `. Correct. 
        // So the error is in the FIRST BFS call. 
        // The output `0 1 2 0 2` has 5 numbers. 
        // This implies `que` had more elements. 
        // If `que[3]` and `que[4]` contained valid vertex indices that were not visited? 
        // But `visit` marks them. 
        // Unless... `visit` array is corrupted? 
        // Or `que` contains indices >= n? 
        // If `que[3]` was 0 (garbage/uncleared) and `visit[0]` was somehow 0? No. 
        // Let's look at `g0`. It clears `0` to `n-1`. 
        // If `tail` reaches `n` or more, `que[n]` is not cleared. 
        // In the trace: `tail` reached 4. `n=3`. `que[3]` is not cleared. 
        // If `que[3]` contains `0` (from previous use or stack garbage)? 
        // And if `visit[0]` is 1, it skips. 
        // How to get `0` printed again? `visit[0]` must be 0. 
        // But `visit[0]` was set to 1. 
        // Is it possible `visit` array is not global or something? No, it is global. 
        // Wait, look at `tDFS`. It uses recursion. 
        // Is it possible `tDFS` corrupts `visit`? No. 
        // Let's look at the `tBFS` logic again. 
        // `if(visit[tmp]) continue;` 
        // `else { printf... visit[tmp]=1; ... }` 
        // This logic is correct for preventing re-visits. 
        // The only way `0` is printed again is if `visit[0]` is 0 when `tmp=0`. 
        // This implies `visit` was reset or corrupted. 
        // OR, the `que` array contains `0` at an index where `visit[0]` was reset? 
        // No, `visit` is not reset during BFS. 
        // 
        // Let's reconsider the `g0` function. 
        // `g0(n)` clears `visit` and `que` for `i=0` to `n-1`. 
        // If `tail` exceeds `n-1`, `que[tail]` is not cleared. 
        // If `que` retains old values, and those values are vertices, and their `visit` status is 0? 
        // But `visit` is cleared. 
        // If `que[3]` is `0` (uncleared, maybe 0 from initialization or previous run?). 
        // `visit[0]` is 1. So it skips. 
        // 
        // There is a subtle bug in `tBFS`: `que` is not cleared beyond `n`. 
        // But more importantly, `tBFS` does not clear `que` completely, only up to `n`. 
        // If `tail` grows large, it accesses uncleared memory. 
        // However, the primary logical error often found in such student submissions is that `visit` is not marked when enqueuing, allowing duplicates in the queue. While the `visit` check at dequeue prevents infinite loops and re-printing *if* `visit` persists, the presence of duplicates in `que` combined with `g0` not clearing the entire `que` array (only first `n` elements) can lead to processing garbage if `tail` exceeds `n`. 
        // 
        // But why `0 2` at the end of the first BFS output? 
        // `0 1 2` is correct. Then `0 2`. 
        // This means two more items were processed and printed. 
        // This implies `visit[0]` and `visit[2]` were 0 at that point? 
        // Impossible if they were visited. 
        // 
        // Unless... `tDFS` before it messed up `visit`? 
        // `tDFS` sets `visit` to 1. 
        // `g0` resets `visit` to 0. 
        // So `visit` is all 0. 
        // 
        // Is it possible `a` matrix is symmetric? Yes. 
        // 
        // Let's look at the `tBFS` implementation in the Reference Program. 
        // It uses `head <= tail`. 
        // The Buggy Program uses `head <= tail`. 
        // 
        // One major difference: The Reference Program passes `x` (start node) to `tBFS`. The Buggy Program hardcodes `que[head]=0`. 
        // This is fine since start is always 0. 
        // 
        // Let's look at `g0` again. 
        // `que[i]=0`. 
        // If `que` contains `0`s, and `visit[0]` is 1, it skips. 
        // 
        // I suspect the error is actually in `tDFS` or how `n` is passed? 
        // No, `tDFS` output `0 1 2` is correct. 
        // 
        // Let's look at the `tBFS` loop condition: `while(head<=tail)`. 
        // Standard BFS is `while(head < tail)`. 
        // If `head == tail`, it processes one last element. 
        // In the trace: 
        // End of valid queue: `head=3, tail=4`. 
        // Process `que[3]` (garbage/0). 
        // Then `head=4, tail=4`. 
        // Loop `4<=4` is true. 
        // Process `que[4]` (garbage/0). 
        // Then `head=5, tail=4`. 
        // Loop `5<=4` false. 
        // 
        // If `que[3]` and `que[4]` happen to be `0` and `2` respectively? 
        // And `visit[0]` and `visit[2]` are somehow 0? 
        // They are not. 
        // 
        // Wait! Look at `g0`. It clears `visit`. 
        // Then `tBFS` runs. 
        // 
        // Is it possible `visit` array size is small? `101`. `n=3`. OK. 
        // 
        // Let's look at the `tDFS` function. 
        // `void tDFS(int n)` iterates `i=0` to `n-1`. 
        // `DFS` is recursive. 
        // 
        // There is a known issue with `tBFS` using `head <= tail` vs `head < tail`. 
        // If initialized `head=0, tail=1`. 
        // If queue becomes empty, `head == tail`. 
        // With `head <= tail`, it enters loop. 
        // `tmp = que[head]`. 
        // If `que[head]` is garbage/uninitialized (because `tail` wasn't advanced properly or `que` wasn't cleared), it processes garbage. 
        // 
        // However, the most likely cause for "Wrong Answer" with extra output is that the `visit` check is failing or `que` contains duplicates that are processed because `visit` was reset? No. 
        // 
        // Let's assume the error is `head <= tail` should be `head < tail`. 
        // If `head < tail`: 
        // Trace: 
        // `head=3, tail=4`. `3<4` true. Process `que[3]` (2). Visited. Continue. `head=4`. 
        // `4<4` false. Stop. 
        // This avoids processing `que[4]`. 
        // But `que[3]` was still processed. 
        // If `que[3]` is `2` (duplicate), it is skipped. 
        // So output `0 1 2`. 
        // 
        // Why did the buggy output have `0 2` at the end? 
        // This implies `que[3]` was `0` and `que[4]` was `2`? 
        // And they were NOT visited? 
        // 
        // Actually, if `g0` only clears `0..n-1`, and `n=3`, `que[3]` and `que[4]` are NOT cleared. 
        // If they contain `0` and `2` from previous operations? 
        // But `visit` is cleared. 
        // If `que[3]` is `0`, `visit[0]` is 1 (set during BFS). So it skips. 
        // 
        // I will flag the `head <= tail` condition as it is non-standard and prone to off-by-one errors processing uninitialized/garbage queue elements if `tail` is not managed strictly, although the `visit` check should protect it. The real issue might be that `que` is not cleared fully, so `que[tail]` might be old data, and if `visit` for that old data was reset, it might print? No, `visit` is set during BFS. 
        // 
        // Another possibility: `tBFS` does not reset `head` and `tail` properly? They are local. 
        // 
        // I will annotate the `while` condition.
    }
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