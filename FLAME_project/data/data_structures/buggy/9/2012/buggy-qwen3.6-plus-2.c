#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
struct left{
    int x1;
    int y1;
};
struct right{
    int x2;
    int y2;
};
struct left left1[105],temp1,min[105];
struct right right1[105],temp2,max[105];
int cnt[105],flag[105],ans,ans1;
 
int main(){
    
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d%d",&left1[i].x1,&left1[i].y1);
    scanf("%d%d",&right1[i].x2,&right1[i].y2);
}//录入 
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(left1[j].x1<left1[i].x1){
            temp1=left1[j];temp2=right1[j];
            left1[j]=left1[i];right1[j]=right1[i];
            left1[i]=temp1;    right1[i]=temp2;
        }
    
    }
}//按左端点的x值排序 
for(int i=0;i<n;i++){
    if(flag[i]==0){
        min[i]=left1[i];
        max[i]=right1[i];
    for(int j=i;j<n;j++){ // @@ The inner loop should start from i+1 or check all unvisited segments, but more importantly, it only checks one step ahead in a sorted list incorrectly. It fails to chain multiple segments because it doesn't update the search range or restart properly for chained segments. Specifically, it iterates j from i to n, but if segment k connects to i, and segment m connects to k, this linear scan might miss m if it's not immediately following or if the logic doesn't recursively/iteratively extend the chain correctly. The main issue is that it only makes one pass. If segment A connects to B, and B connects to C, when i=A, it finds B. But it doesn't then look for what connects to B within the same chain building process effectively if the segments aren't adjacent in the sorted array or if the logic is flawed. Actually, the logic `if(left1[j].x1==max[i].x2&&left1[j].y1==max[i].y2)` updates `max[i]`. This allows chaining. However, the loop `for(int j=i;j<n;j++)` proceeds linearly. If segments are sorted by start X, this *should* work for simple chains. Let's look at the test case.
        // Segments sorted by start X:
        // 1: (1,2)-(7,8)
        // 2: (7,8)-(9,10)
        // 3: (7,78)-(27,50)
        // 4: (27,50)-(75,78)
        // 5: (75,78)-(80,67)
        
        // i=0 (Seg 1): max=(7,8). j=1 (Seg 2): matches (7,8). flag[1]=1, max=(9,10), cnt[0]=1. j=2... no match. j=3... no match. j=4... no match.
        // i=1 (Seg 2): flag[1]==1, skip.
        // i=2 (Seg 3): flag[2]==0. max=(27,50). j=2... j=3 (Seg 4): matches (27,50). flag[3]=1, max=(75,78), cnt[2]=1. j=4 (Seg 5): matches (75,78). flag[4]=1, max=(80,67), cnt[2]=2.
        // i=3 (Seg 4): flag[3]==1, skip.
        // i=4 (Seg 5): flag[4]==1, skip.
        
        // cnt[0]=1, cnt[2]=2.
        // Max cnt is 2. Ans = 2+1 = 3. Start point left1[2] which is (7,78).
        // Expected output: 3 7 78.
        // Buggy output: 2 7 78.
        
        // Wait, the buggy output says 2. This implies ans was 1.
        // Let's re-read the code carefully.
        // `ans=cnt[0];` inside the loop? No, `for(int i=0;i<n;i++){ ans=cnt[0]; ... }`
        // Ah, line 46: `ans=cnt[0];` is INSIDE the loop.
        // So for i=0: ans=cnt[0] (1). ans<cnt[0] false.
        // For i=1: ans=cnt[0] (1). ans<cnt[1] (0) false.
        // For i=2: ans=cnt[0] (1). ans<cnt[2] (2) true. ans=2, ans1=2.
        // For i=3: ans=cnt[0] (1). ans<cnt[3] (0) false.
        // For i=4: ans=cnt[0] (1). ans<cnt[4] (0) false.
        // Result: ans=2, ans1=2. Output: 2+1=3, 7, 78.
        
        // Why did the user say Buggy Output is `2 7 78`?
        // If the output is `2 7 78`, then `ans+1` is 2, so `ans` is 1.
        // This means `cnt[ans1]` was 1.
        // This implies the chain detection failed to find the length 2 chain for segment 3.
        
        // Let's look at the sorting.
        // Input:
        // 75 78 80 67
        // 7 8 9 10
        // 7 78 27 50
        // 1 2 7 8
        // 27 50 75 78
        
        // Sorted by x1:
        // i=0: 1 2 7 8
        // i=1: 7 8 9 10
        // i=2: 7 78 27 50
        // i=3: 27 50 75 78
        // i=4: 75 78 80 67
        
        // Logic trace again:
        // i=0: flag[0]=0. max=(7,8).
        // j=0: left1[0]=(1,2) != (7,8).
        // j=1: left1[1]=(7,8) == max(7,8). Match. flag[1]=1. max becomes right1[1]=(9,10). cnt[0]=1.
        // j=2: left1[2]=(7,78) != (9,10).
        // j=3: left1[3]=(27,50) != (9,10).
        // j=4: left1[4]=(75,78) != (9,10).
        // End i=0. cnt[0]=1.
        
        // i=1: flag[1]=1. Skip.
        
        // i=2: flag[2]=0. max=(27,50).
        // j=2: left1[2]=(7,78) != (27,50).
        // j=3: left1[3]=(27,50) == max(27,50). Match. flag[3]=1. max becomes right1[3]=(75,78). cnt[2]=1.
        // j=4: left1[4]=(75,78) == max(75,78). Match. flag[4]=1. max becomes right1[4]=(80,67). cnt[2]=2.
        // End i=2. cnt[2]=2.
        
        // i=3: flag[3]=1. Skip.
        // i=4: flag[4]=1. Skip.
        
        // Finding max:
        // i=0: ans=cnt[0]=1. ans<cnt[0] (1<1) False.
        // i=1: ans=cnt[0]=1. ans<cnt[1] (1<0) False.
        // i=2: ans=cnt[0]=1. ans<cnt[2] (1<2) True. ans=2, ans1=2.
        // i=3: ans=cnt[0]=1. ans<cnt[3] (1<0) False.
        // i=4: ans=cnt[0]=1. ans<cnt[4] (1<0) False.
        
        // Final: ans=2. printf("%d %d %d", ans+1, ...) -> 3 7 78.
        
        // The code actually produces the CORRECT output for this test case logically.
        // Why is it marked as Wrong Answer with output 2 7 78?
        
        // Is it possible `memset` or initialization is missing?
        // `int cnt[105],flag[105],ans,ans1;` are global. They are initialized to 0 by default in C.
        
        // Let's look closely at the "Buggy Output" provided in the prompt: `2 7 78`.
        // If the program outputs `2 7 78`, then `ans` must be 1.
        // This happens if `cnt[2]` was 1 instead of 2.
        // Why would `cnt[2]` be 1?
        // If the loop `for(int j=i;j<n;j++)` didn't find the second segment.
        
        // Wait, look at line 46: `ans=cnt[0];`
        // This resets `ans` to `cnt[0]` in every iteration.
        // If `cnt[0]` was the maximum, it would work.
        // But here `cnt[2]` is the maximum.
        // In iteration i=2, `ans` is reset to `cnt[0]` (which is 1). Then `1 < 2` is true, so `ans` becomes 2.
        // So the logic holds.
        
        // Is there a subtle bug?
        // What if `ans` and `ans1` are not initialized?
        // If `cnt` array was all zeros? No.
        
        // Let's look at the previous Reference Program provided in the prompt description vs the Source Code provided for annotation.
        // The prompt asks to annotate the "Source Code" below.
        
        // Maybe the error is in the sorting?
        // If two segments have same x1, they are not sorted by y1 or anything else.
        // In the test case:
        // (7,8) and (7,78).
        // Stable sort? Bubble sort used.
        // If input order was different?
        
        // Let's look at the variable `ans`.
        // `ans` is global, initialized to 0.
        // If all cnt[i] are 0?
        
        // Actually, there is a logical flaw in finding the maximum.
        // `ans=cnt[0]` inside the loop is weird but functional if `cnt[0]` is small.
        // However, if `cnt[0]` is large, it resets `ans` to a high value, potentially missing a larger value later? No, it resets to `cnt[0]`. If a later `cnt[i]` is larger, it updates. If a later `cnt[i]` is smaller, it keeps `ans` (which might be from a previous iteration? No, `ans` is overwritten by `cnt[0]` at the start of EACH iteration).
        // So `ans` effectively becomes `max(cnt[0], cnt[i])` for the current `i` compared against `cnt[0]`.
        // It fails to preserve the maximum found so far across iterations if the maximum is not compared against the global max, but rather `cnt[0]`.
        // Example: cnt = [1, 5, 3].
        // i=0: ans=1. 1<1 False. ans=1.
        // i=1: ans=1 (reset to cnt[0]). 1<5 True. ans=5, ans1=1.
        // i=2: ans=1 (reset to cnt[0]). 1<3 True. ans=3, ans1=2.
        // Final ans=3. But max was 5.
        // So the algorithm for finding the max index is WRONG. It returns the last element that is greater than `cnt[0]`, not the global maximum.
        
        // In our specific test case: cnt = [1, 0, 2, 0, 0].
        // i=0: ans=1.
        // i=1: ans=1. 1<0 False.
        // i=2: ans=1. 1<2 True. ans=2, ans1=2.
        // i=3: ans=1. 1<0 False.
        // i=4: ans=1. 1<0 False.
        // Result ans=2. Correct for this case.
        
        // So why "Wrong Answer"?
        // Perhaps another test case fails? The prompt provides one test case.
        // "Test Case Input: ... Buggy Output: 2 7 78 ... Expected Output: 3 7 78".
        // If my trace shows 3 7 78, but the system says it outputs 2 7 78, then my trace is wrong or the code behaves differently.
        
        // Is it possible `flag` logic is wrong?
        // If `flag` prevents a segment from being used as a START of a chain, that's correct.
        
        // Let's look at the sorting again.
        // `if(left1[j].x1<left1[i].x1)`
        // Strictly less.
        // If x1 are equal, order is preserved (stable-ish for bubble sort if swap condition is strict).
        
        // What if `ans` initialization is the problem?
        // If `n=1`?
        // Loop `i=0` to `n-1` (0).
        // `ans=cnt[0]` (0). `ans<cnt[0]` false.
        // Output `0+1`, coords. Correct.
        
        // Let's look at the provided "Buggy Output" again: `2 7 78`.
        // This corresponds to `ans=1`.
        // This implies `cnt[ans1]` was 1.
        // This implies the chain of length 3 (2 connections) was not found.
        // It found a chain of length 2 (1 connection).
        // Which chain? `(7,78)-(27,50)` connects to `(27,50)-(75,78)`. That's 2 segments.
        // Wait, the chain is Seg3 -> Seg4 -> Seg5.
        // Seg3: (7,78)-(27,50)
        // Seg4: (27,50)-(75,78)
        // Seg5: (75,78)-(80,67)
        // This is 3 segments. Connections: 3->4, 4->5.
        // `cnt[2]` should be 2.
        
        // If `cnt[2]` was 1, it means it only found one connection.
        // Why would it miss the second?
        // `max[i]` updates to `right1[j]`.
        // When j=3, match found. `max` becomes `(75,78)`. `cnt[2]` becomes 1.
        // Next j=4. `left1[4]` is `(75,78)`. `max` is `(75,78)`. Match.
        // `cnt[2]` becomes 2.
        
        // Is it possible `j` loop bound is wrong? `j<n`. Correct.
        
        // I suspect the error marker should be on the Max finding logic because it is fundamentally broken for general cases, even if it accidentally works for this specific distribution of counts relative to cnt[0]. However, the prompt says "Based on ... the test case inputs that the program failed".
        // If the program FAILED this test case, producing 2 instead of 3, then `cnt[2]` MUST have been 1 or `ans` calculation failed.
        
        // Let's check `ans` logic again.
        // If `cnt[0]` was 2?
        // Chain 1: Seg1->Seg2. cnt[0]=1.
        
        // There is a possibility that `flag` array interferes?
        // No, `flag` is only checked for starting a new chain (`if(flag[i]==0)`).
        
        // Let's look at line 46 again.
        // `ans=cnt[0];`
        // If the intention was `if(i==0) ans=cnt[0];` or `ans` initialized outside, it would be correct.
        // Because `ans` is reset to `cnt[0]` every time, it loses track of the true maximum if the true maximum appeared earlier and was larger than `cnt[0]`, AND no subsequent element is larger than `cnt[0]`? No, if a subsequent element is larger than `cnt[0]`, it updates.
        // The failure mode is: Max is at index K. `cnt[K] > cnt[0]`. `ans` updates to `cnt[K]`.
        // Later index M. `cnt[M] < cnt[K]` but `cnt[M] > cnt[0]`. `ans` updates to `cnt[M]`. `ans1` becomes M.
        // So it returns the LAST segment that has a count greater than `cnt[0]`, not the global maximum.
        
        // In our case:
        // cnt = [1, 0, 2, 0, 0].
        // cnt[0] = 1.
        // i=2: cnt[2]=2 > 1. ans=2, ans1=2.
        // i=3: cnt[3]=0. Not > 1.
        // i=4: cnt[4]=0. Not > 1.
        // So it correctly identifies index 2.
        
        // So why does it fail?
        // Maybe `cnt` is not calculated correctly?
        
        // What if `left1` and `right1` structs are copied incorrectly?
        // `temp1=left1[j]; temp2=right1[j];`
        // `left1[j]=left1[i]; right1[j]=right1[i];`
        // `left1[i]=temp1; right1[i]=temp2;`
        // This is a standard swap.
        
        // I will mark the Max finding loop as erroneous because it is logically incorrect for the general problem, even if it seems to pass the specific trace above (perhaps my trace of the "Buggy" behavior assumes the code runs as written, but maybe there's a compiler/memory issue? Unlikely).
        // Actually, if the "Buggy Output" is 2, and Expected is 3.
        // And my trace says 3.
        // Then either the trace is wrong, or the code provided in "Source Code" is slightly different from what generated "Buggy Output", OR there is a subtle UB.
        
        // However, the most obvious logical error is the `ans=cnt[0]` reset.
        // If the test case had `cnt = [1, 3, 2]`.
        // i=1: ans=1. 1<3. ans=3, ans1=1.
        // i=2: ans=1 (RESET). 1<2. ans=2, ans1=2.
        // Returns index 2 (count 2). Max was index 1 (count 3).
        // This is a clear bug.
        
        // Does the provided test case trigger this?
        // cnt = [1, 0, 2, 0, 0].
        // It does NOT trigger the bug where a previous max is overwritten by a smaller (but still >cnt[0]) value later.
        
        // Is there another error?
        // Line 30: `for(int j=i;j<n;j++)`
        // If `i` connects to `j`, `flag[j]` is set.
        // If `j` connects to `k`, `flag[k]` is set.
        // This relies on `j` appearing after `i` and `k` appearing after `j`.
        // Since sorted by X, this is generally true for non-overlapping segments forming a line.
        
        // I will annotate the line `ans=cnt[0];` as the error because it prevents finding the true maximum in many cases, and is the most significant logical flaw in the result calculation part.

        if(ans<cnt[i]){
            ans=cnt[i];
            ans1=i;
        }
    }
}
printf("%d %d %d",ans+1,left1[ans1].x1,left1[ans1].y1);
return 0;
}