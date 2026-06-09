#include <stdio.h>
struct line{
    int x0;
    int y0;
    int x2;
    int y2;
}l[110];
int k=0;
int mark=0;
int a[110][10]={0};
void search(int ,int ,int ,int);
int main()
{
    int num,max,b;
    scanf("%d",&num);//输入线段数目
    getchar();
    for(int i=0;i<num;i++){
         scanf("%d %d %d %d",&l[i].x0,&l[i].y0,&l[i].x2,&l[i].y2);//输入各段线段坐标
        getchar();
    }
    for(int i=0;i<num;i++){
        int x,y,m,n;
        x=l[i].x0;
        y=l[i].y0;
        m=l[i].x2;
        n=l[i].y2; 
        search(m,n,i,num); // @@ The variable 'k' is incremented inside the loop after this call, but 'search' uses the current value of 'k' to store results. However, 'k' is global and shared. More critically, the logic assumes that each segment starts a new chain, but 'search' modifies 'a[k]' which corresponds to the chain starting at segment 'i'. The issue is that 'k' is incremented *after* search returns. Inside search, it uses 'a[k][0]++'. This part is logically okay for accumulating count for the current start index 'k'.
        a[k][1]=x;
        a[k][2]=y;
        k++;
        
    }
    max=a[0][0];
    b=0; // @@ Variable 'b' is used uninitialized if the loop below doesn't execute or if a[0][0] remains max. It should be initialized to 0.
    for(int i=1;i<k;i++){
        if(a[i][0]>max){
            max=a[i][0];
            b=i;
        }
    }
    printf("%d %d %d",max+1,a[b][1],a[b][2]);
    return 0;
}
search(int p,int q,int f,int up){ // @@ Missing return type 'void' or 'int'. In C89 this defaults to int, but it's bad practice. More importantly, the logic here is flawed.
    for(int j=0;j<up;j++){
        //printf("i=%d,j=%d,m=%d,n=%d\n",f,j,p,q);
        if(j==f){
                continue;
            }
        if(p==l[j].x0&&q==l[j].y0){
                a[k][0]++;
                p=l[j].x2;
                q=l[j].y2;
                mark=1;
            }
    }
    if(mark==1){
        mark=0;
        search(p,q,f,up); // @@ Recursive call. The problem states "No three or more segments share a single endpoint". This implies a simple chain. However, the current implementation only checks if the *current* end point (p,q) matches the *start* point (x0,y0) of another segment. It does not handle the case where the continuous line might need to check against all segments again properly without revisiting 'f'. But the bigger issue is that 'search' doesn't prevent revisiting segments already in the chain. Although constraint 2 helps, constraint 1 says no intersection in middle. The main logical error is that 'search' only looks for ONE next segment in the loop. If multiple segments started at (p,q), it would pick the last one found in the loop due to overwriting p,q. But constraint 2 says max 2 segments share an endpoint (one incoming, one outgoing). So finding one is fine. HOWEVER, the recursion doesn't pass information about which segments have been visited. If the line loops back (unlikely given x increasing) or if there's ambiguity, it might fail. Given x1 < x2, x coordinates strictly increase, so no cycles.
        // The critical error is that 'search' finds the NEXT segment. But it iterates through ALL segments. If it finds a match, it updates p,q and sets mark. But if it finds ANOTHER match later in the loop (which shouldn't happen per constraints if we assume strict chaining), it would overwrite.
        // Actually, the biggest error is that 'search' is called with 'f' (the index of the starting segment of the chain). It skips 'j==f'. But it doesn't skip other segments that might have been part of the chain already. Since x increases, we won't go back to a previous x. So visiting a segment with higher x is fine.
        // Wait, look at the loop in search. It iterates j from 0 to up. If it finds a segment j that starts at (p,q), it extends the chain.
        // Is it possible that it misses the correct next segment? No, it scans all.
        // Is it possible it picks the wrong one? Only if two segments start at (p,q). Constraint 2 says no 3+ share an endpoint. One is the incoming segment (ending at p,q). The other is the outgoing. So only one outgoing segment exists. So finding one is correct.
        // However, there is a subtle bug: 'mark' is global. If 'search' is called recursively, 'mark' is set to 1. Then in the recursive call, if it finds a next segment, it sets mark=1 again. If it doesn't, mark stays 0? No, mark is set to 1 ONLY if a match is found. If no match is found in the loop, mark remains whatever it was? No, mark is reset to 0 before recursion? No.
        // Let's trace:
        // 1. Enter search. mark is 0 (initially).
        // 2. Loop finds match. Sets mark=1. Updates p,q.
        // 3. Loop continues. If another match found (impossible), overwrites p,q.
        // 4. Loop ends.
        // 5. if(mark==1): set mark=0, recurse.
        // 6. In recursion: mark is 0. Loop runs. If match found, mark=1.
        // This seems okay for mark.
        
        // BUT, look at 'a[k][0]++'. This increments the count for the chain starting at index 'k'.
        // The variable 'k' is global and is being incremented in main().
        // When search is called from main, 'k' has a specific value (say K_val).
        // Inside search, it uses 'a[K_val][0]++'.
        // Then it recurses. The recursive call also uses 'a[K_val][0]++' because 'k' hasn't changed in main yet (it changes after search returns).
        // So the count accumulation is correct for the current chain.
        
        // So where is the error?
        // Let's look at the output format. "max+1". a[k][0] counts the number of *additional* segments found. So total segments = 1 (start) + count. Correct.
        
        // Let's re-read the constraints and logic.
        // "x-coordinates ... increasing order".
        // The code sorts nothing. It just iterates.
        // If the segments are not given in order, does 'search' still work?
        // Yes, because 'search' scans all segments (j=0 to up) to find the one that starts at (p,q). It doesn't rely on order.
        
        // What about the starting point?
        // Main loop: for each segment i, it starts a chain.
        // It records start coords in a[k][1], a[k][2].
        // It calls search to find length.
        // Then k++.
        
        // This brute-force approach (starting a chain from every segment) is O(N^2) or O(N*L) which is fine for N=100.
        
        // Is there an error in 'b' initialization? Yes, added above.
        
        // Is there an error in 'search' signature? It returns int in declaration but void in definition?
        // Declaration: void search(...);
        // Definition: search(...) { ... return 0; } -> Implicit int return. Mismatch.
        
        // Let's look closer at the test case failure.
        // Input: W (Wait, the prompt says Test Case Input: W? That's likely a placeholder or error in the prompt description provided to me. I must assume standard integer inputs).
        // If the input is valid integers, does it work?
        
        // One major logical flaw:
        // The problem asks for the continuous line segment containing the MAXIMUM number of segments.
        // The code calculates the length of the chain starting at EVERY segment.
        // However, a continuous line segment is defined by connected segments.
        // If A->B->C is a chain.
        // Starting at A: finds B, then C. Count = 2. Total = 3.
        // Starting at B: finds C. Count = 1. Total = 2.
        // Starting at C: finds nothing. Count = 0. Total = 1.
        // The max will be found at A. This is correct.
        
        // However, consider the constraint: "Only one continuous line segment contains the maximum number of segments."
        
        // Let's look at the 'search' function again.
        // It uses global 'mark'.
        // If search(p,q,f,up) is called.
        // It sets mark=1 if it finds a next segment.
        // Then it resets mark=0 and recurses.
        // What if the recursive call DOESN'T find a segment?
        // Then mark remains 0.
        // The recursive call returns.
        // The parent call has already reset mark to 0.
        // So when the parent returns, mark is 0.
        // This seems fine.
        
        // Wait, look at this line in search:
        // if(p==l[j].x0&&q==l[j].y0)
        // It checks if the current END point (p,q) matches the START point of segment j.
        // This is correct for extending the line.
        
        // Is it possible that 'search' visits the SAME segment twice?
        // No, because x increases. l[j].x0 > l[prev].x0.
        // Unless two segments have same x0? "x1 < x2" for endpoints of a segment.
        // But different segments can have same x0?
        // If segment 1 is (0,0)-(1,1) and segment 2 is (1,1)-(2,2).
        // Start at 1. End (1,1). Search finds seg 2.
        // Seg 2 ends (2,2). Search finds nothing.
        
        // What if segment 3 is (1,1)-(3,3)?
        // Constraint 2: No three or more segments share a single endpoint.
        // So at (1,1), we have End of 1, Start of 2, Start of 3? That's 3 segments sharing (1,1). Forbidden.
        // So at any connection point, there is exactly 1 incoming and 1 outgoing (or 0 outgoing if end).
        // So the path is unique.
        
        // So why would it fail?
        
        // Let's look at the variable 'b' again.
        // int num,max,b;
        // b is uninitialized.
        // If k=1 (only 1 segment), the loop for(i=1;i<k;i++) doesn't run.
        // b is garbage.
        // printf uses a[b][1]. Crash or wrong output.
        // This is definitely an error.
        
        // Are there other errors?
        // The function 'search' is declared as void but returns 0 (int).
        // This is a warning/error in strict compilers.
        
        // Also, in 'search', the variable 'mark' is global.
        // If multiple chains are being calculated (in the loop in main), 'mark' is shared.
        // In main:
        // search(...)
        // ...
        // k++
        // Next iteration.
        // search(...)
        // Inside search, mark is used.
        // Since search is depth-first and completes fully before returning to main, the global state of 'mark' is reset to 0 by the time search returns (because the deepest level returns, then parent resets mark? No.)
        
        // Trace mark:
        // Level 0 (call from main): mark=0 initially.
        // Finds match. mark=1.
        // Resets mark=0.
        // Calls Level 1.
        //   Level 1: mark=0.
        //   Finds match. mark=1.
        //   Resets mark=0.
        //   Calls Level 2.
        //     Level 2: mark=0.
        //     No match.
        //     Returns.
        //   Level 1 resumes. Returns.
        // Level 0 resumes. Returns.
        // So mark is 0 on return. Correct.
        
        // So the main error is 'b' uninitialized.
        
        // Another potential error:
        // The problem says "output ... coordinates of its starting point".
        // The code outputs a[b][1] and a[b][2].
        // These are set to x and y of the segment 'i' that started the chain.
        // This is correct.
        
        // One more thing:
        // The reference program had sorting. This program doesn't sort.
        // Does it matter?
        // The search function scans all segments to find the next one.
        // So order doesn't matter for correctness of finding the chain.
        // It only matters for performance.
        
        // So, I will flag 'b' initialization and the return type mismatch.
    } else{
        return 0;
    }
}