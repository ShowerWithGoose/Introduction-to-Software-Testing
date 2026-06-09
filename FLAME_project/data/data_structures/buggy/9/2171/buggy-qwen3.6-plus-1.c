#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};
typedef struct line lin;
lin str[105];
int main(void){
    int i,j,n,max = 1,flag = 0;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d%d%d%d",&str[i].x1,&str[i].y1,&str[i].x2,&str[i].y2);
        str[i].num = 1;
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(i != j) 
            {
                if(str[i].x2 == str[j].x1&&str[i].y2 == str[j].y1)
                {
                    str[i].x2 = str[j].x2;        
                    str[i].y2 = str[j].y2;    
                    str[i].num += str[j].num; 
                    j = 0; // @@ The logic modifies str[i] in place and resets j to re-scan, but it does not mark str[j] as used/merged. This causes the same segment str[j] to potentially be merged multiple times into different chains or counted incorrectly if it appears as a successor to multiple predecessors, violating the constraint that segments form a single continuous line. More critically, by modifying str[i]'s endpoint to str[j]'s endpoint, it attempts to chain them. However, because it doesn't invalidate str[j], if another segment k also ends at str[j]'s start, it might try to merge str[j] again or create inconsistent states. The primary issue is that this greedy in-place merging without tracking visited nodes or using a proper graph traversal (like DFS/BFS or sorting + DP) fails to correctly accumulate the length of the longest path in the general case, especially when the order of processing matters. In the specific test case, the segments are: (1,2)-(7,8), (7,8)-(9,10), (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67). The chain is 1->2->4->5 (using 0-indexed input order roughly). The current code processes i=0. It finds j=1 matches (7,8). Merges 1 into 0. str[0] becomes (1,2)-(9,10), num=2. Resets j. Scans again. No other match for str[0]. Then i=1. str[1] is still (7,8)-(9,10). It might find matches? But str[1] was "consumed" logically but not marked. If i=2 (7,78-27,50), it finds j=3 (27,50-75,78). Merges 3 into 2. str[2] becomes (7,78)-(75,78), num=2. Resets j. Then checks j=4? str[4] is (75,78-80,67). Matches str[2]'s new end. Merges 4 into 2. str[2] becomes (7,78)-(80,67), num=3. This looks correct for segment 2. Why did it output 2? Let's trace carefully.
                    // The loop structure `for(i=0...` then inner `for(j=0...` with `j=0` reset is problematic.
                    // When i=0, it merges segment 1 into 0. str[0].num=2.
                    // When i=1, str[1] is unchanged. It checks against others.
                    // When i=2, it merges 3 into 2 (num=2), then 4 into 2 (num=3).
                    // So str[2].num should be 3.
                    // Wait, the bug might be that `str[j]` is not invalidated.
                    // When i=0 merged j=1, str[1] is still available.
                    // Does any other segment connect TO str[1]? No.
                    // Does str[1] connect to anything? Yes, originally it connected to nothing else in this specific set except being connected FROM 0.
                    // The issue is likely that the problem requires finding the MAXIMUM number of segments.
                    // Let's look at the output "2 7 78". This implies max=2.
                    // This means str[2].num was calculated as 2, not 3.
                    // Why?
                    // i=2. j=0..4.
                    // j=0: str[2].x2(27) != str[0].x1(1).
                    // j=1: str[2].x2(27) != str[1].x1(7).
                    // j=2: skip (i!=j).
                    // j=3: str[2].x2(27) == str[3].x1(27) && str[2].y2(50) == str[3].y1(50). Match.
                    // str[2].x2 = 75, str[2].y2 = 78, str[2].num = 1+1=2. j=0.
                    // Restart j loop for i=2.
                    // j=0: str[2].x2(75) != str[0].x1(1).
                    // j=1: str[2].x2(75) != str[1].x1(7).
                    // j=2: skip.
                    // j=3: str[2].x2(75) != str[3].x1(27). (str[3] is unchanged in memory, but logically consumed).
                    // j=4: str[2].x2(75) == str[4].x1(75) && str[2].y2(78) == str[4].y1(78). Match.
                    // str[2].x2 = 80, str[2].y2 = 67, str[2].num = 2+1=3. j=0.
                    // Restart j loop.
                    // No more matches.
                    // So str[2].num SHOULD be 3.
                    // Why is the output 2?
                    // Perhaps the `flag` update logic is inside the outer loop?
                    // Yes: `if(str[i].num > max) { max = str[i].num; flag = i; }` is inside `for(i...)`.
                    // So after i=2, max should be 3, flag=2.
                    // Is it possible that an earlier iteration overwrote something?
                    // Or is there a subtle error in `j=0` reset causing infinite loop or skipping? No, j increments.
                    // Let's re-read the code provided in the prompt's "Source Code" section vs "Reference Program".
                    // The "Source Code" is the buggy one.
                    // Wait, look at `str[i].num += str[j].num`.
                    // When i=2 merges j=3, str[2].num becomes 2.
                    // When i=2 merges j=4, str[2].num becomes 2 + str[4].num. str[4].num is 1. So 3.
                    // It seems logically it should work for this case.
                    // However, there is a fundamental flaw: if segment A merges B, and later segment C merges A, C needs to pick up A's accumulated count.
                    // In this code, if i=C finds j=A, it does `str[C].num += str[A].num`. This part is correct for accumulation.
                    // BUT, `str[C].x2` becomes `str[A].x2`. This extends C.
                    // The problem is that `str[A]` is not marked as used.
                    // If there was a segment D that also started where A ended, D might also merge A? No, A ends at A.x2. D starts at D.x1. If D.x1 == A.x2, D merges A? No, the condition is `str[i].x2 == str[j].x1`. So i is the predecessor, j is the successor.
                    // So i=C, j=A means C ends where A starts. Correct.
                    // The error is likely that `str[j]` (the successor) is not removed from consideration for being a predecessor for someone else? No, j is the successor.
                    // Actually, the standard solution usually involves sorting or DP. This ad-hoc merging is fragile.
                    // One specific error: `j=0` restarts the scan. If `str[j]` was merged into `str[i]`, `str[j]` still exists in the array. If another segment `k` has `str[k].x2 == str[j].x1`, it will merge `j` into `k`. This creates a fork/double counting if `j` was already part of `i`'s chain.
                    // In our trace, did anyone merge str[3] or str[4] before i=2 did?
                    // i=0: merged 1.
                    // i=1: no merges.
                    // i=2: merged 3, then 4.
                    // i=3: str[3] is still (27,50)-(75,78).
                    //   j=4: str[3].x2(75) == str[4].x1(75). Match.
                    //   str[3].num += str[4].num -> 1+1=2.
                    //   str[3].x2 becomes 80.
                    //   But str[2] already absorbed 3 and 4.
                    //   This doesn't reduce str[2].num.
                    //   So max should still be 3.
                    // Why WA?
                    // Maybe the input order or specific comparison fails?
                    // Let's look at the constraints. "No three or more segments share a single endpoint."
                    // The logic `str[i].num += str[j].num` assumes `str[j].num` is the full length of the chain starting at j.
                    // But `str[j]` might have been extended by previous iterations of `i`?
                    // No, `i` iterates 0 to n-1. `j` iterates 0 to n-1.
                    // If `i=0` extends into `j=1`, `str[0]` grows.
                    // If later `i=2` extends into `j=0`, `str[2]` gets `str[0].num` (which is 2). Correct.
                    // The issue is that `str[j]` is NOT updated to reflect that it has been appended to `str[i]`.
                    // So if `str[j]` is later used as a predecessor for some `k`, `k` will start a new chain from `j`, ignoring that `j` is already part of `i`'s chain. This leads to overcounting or incorrect chains, but usually overcounting isn't the issue for "max", unless it picks a wrong start point?
                    // Actually, if it overcounts, it might report a larger number. Here it reports smaller (2 vs 3).
                    // This implies the chain of 3 was NOT found.
                    // Did i=2 fail to merge 4?
                    // When i=2 merged 3, `str[2]` became (7,78)-(75,78). `j` reset to 0.
                    // Then it scans. Finds 4. Merges 4. `str[2]` becomes (7,78)-(80,67). Num=3.
                    // Is it possible that `str[4]` was modified before?
                    // i=0,1 didn't touch 4.
                    // i=2 touches 4.
                    // i=3 touches 4.
                    // i=4...
                    // It seems it should work.
                    // Wait! Look at `str[i].x2 = str[j].x2`.
                    // If `str[j]` itself had been extended previously, `str[j].x2` would be the end of its chain.
                    // But `str[j].num` would also be the count of its chain.
                    // So `str[i]` correctly absorbs `j`'s chain.
                    // Why is the answer 2?
                    // Maybe `flag` is not updated correctly?
                    // `if(str[i].num > max)`
                    // If max is initialized to 1.
                    // i=0: num=2. max=2, flag=0.
                    // i=1: num=1.
                    // i=2: num=3. max=3, flag=2.
                    // Output: 3 7 78.
                    // The expected output is 3 7 78.
                    // The buggy output is 2 7 78.
                    // This implies `str[2].num` was NOT 3.
                    // Why?
                    // Ah, look at `j=0` reset.
                    // When `i=2` merges `j=3`, `str[2]` changes. `j` becomes 0.
                    // The loop `for(j=0;j<n;j++)` continues.
                    // Next iteration: `j` increments to 1? NO.
                    // The `for` loop has `j++` in its update step.
                    // But inside the `if`, we set `j=0`.
                    // Then the `if` block ends.
                    // Then the `for` loop executes `j++`. So `j` becomes 1.
                    // We skipped checking `j=0` again?
                    // We restarted scanning from 0, but immediately incremented to 1.
                    // So we check 1, 2, 3...
                    // We missed checking 0 again?
                    // In this specific case, did we need to check 0 again?
                    // str[2] is now (7,78)-(75,78).
                    // str[0] is (1,2)-(9,10).
                    // No match.
                    // So skipping 0 is fine here.
                    // What if we needed to merge another segment that was at index 0?
                    // Not the case here.
                    
                    // Let's look closer at the merge of 4.
                    // After merging 3, str[2] is (7,78)-(75,78). Num=2.
                    // Loop continues j=1, 2(skip), 3.
                    // j=3: str[2].x2(75) vs str[3].x1(27). No match.
                    // j=4: str[2].x2(75) vs str[4].x1(75). Match.
                    // Merge 4. Num=3.
                    
                    // Is it possible that `str[4]` was already merged into something else?
                    // No.
                    
                    // Wait, look at `str[i].num += str[j].num`.
                    // If `str[j]` had previously absorbed other segments, its num would be higher.
                    // Here `str[3]` and `str[4]` were fresh (num=1).
                    
                    // There is one subtle bug: `str[j]` is not invalidated.
                    // If `i=3` runs later, it sees `str[4]`.
                    // `str[3]` (original) merges `str[4]`. `str[3].num` becomes 2.
                    // This doesn't affect `str[2]`.
                    
                    // Why is the output 2?
                    // Maybe the array `str` is not large enough? No, 105.
                    // Maybe `scanf` failed? No.
                    
                    // Let's reconsider the `j=0` logic.
                    // If I merge j, I set j=0.
                    // The loop increments j to 1.
                    // I effectively skip re-checking index 0.
                    // If index 0 had become a valid successor due to the extension of `str[i]`, I would miss it.
                    // In our case, `str[2]` extended to 75.
                    // Did `str[0]` start at 75? No, 1.
                    // Did `str[1]` start at 75? No, 7.
                    
                    // Is it possible that the segments are not processed in an order that allows chaining?
                    // The code relies on `i` being the predecessor.
                    // If the chain is A->B->C.
                    // i=A finds B. A becomes A+B.
                    // i=A (still) finds C?
                    // When A merged B, A's endpoint changed to B's end.
                    // If B's end is C's start, A will find C in the same inner loop (since j resets/scans forward).
                    // So A becomes A+B+C.
                    // This works for linear chains starting at `i`.
                    
                    // What if the chain is B->C, and A->B?
                    // i=A finds B. A becomes A+B.
                    // Does A find C? Yes, if B ended where C starts.
                    
                    // What if the input order is such that the "middle" segment is processed first?
                    // i=B. Finds C. B becomes B+C.
                    // Later i=A. Finds B?
                    // Condition: `str[A].x2 == str[B].x1`.
                    // `str[B]` in memory still has its original `x1`? YES.
                    // The code ONLY updates `str[i]` (the predecessor). It does NOT change `str[j]` (the successor).
                    // So `str[B]` still looks like the original segment B.
                    // So `A` can successfully merge `B`.
                    // BUT, `str[A].num += str[B].num`.
                    // `str[B].num` was updated when `i=B` ran!
                    // So `str[B].num` is 2 (B+C).
                    // So `str[A].num` becomes 1 + 2 = 3.
                    // And `str[A].x2` becomes `str[B].x2`.
                    // `str[B].x2` was NOT updated in memory when `i=B` ran?
                    // Wait. When `i=B`, we did `str[B].x2 = str[C].x2`.
                    // So `str[B]` in memory IS updated.
                    // So `str[A]` gets `str[B].x2` (which is C's end).
                    // So `str[A]` becomes A+B+C. Correct.
                    
                    // So why WA?
                    // Let's check the test case again.
                    // 5
                    // 75 78 80 67  (Idx 4)
                    // 7 8 9 10     (Idx 1)
                    // 7 78 27 50   (Idx 2)
                    // 1 2 7 8      (Idx 0)
                    // 27 50 75 78  (Idx 3)
                    
                    // Chain: 0->1 (Ends 9,10). Length 2.
                    // Chain: 2->3->4 (Ends 80,67). Length 3.
                    
                    // Trace i=2:
                    // j=0: No.
                    // j=1: No.
                    // j=2: Skip.
                    // j=3: Match (27,50).
                    // str[2].x2=75, y2=78. Num=1+1=2.
                    // j set to 0. Loop increments j to 1.
                    // j=1: No.
                    // j=2: Skip.
                    // j=3: No (75!=27).
                    // j=4: Match (75,78).
                    // str[2].x2=80, y2=67. Num=2+1=3.
                    // j set to 0. Loop increments j to 1.
                    // ... loop ends.
                    // str[2].num is 3.
                    
                    // Trace i=0:
                    // j=1: Match (7,8).
                    // str[0].x2=9, y2=10. Num=2.
                    // j set to 0. Loop inc to 1.
                    // j=1: No (9!=7).
                    // ...
                    // str[0].num is 2.
                    
                    // Max should be 3.
                    
                    // Is it possible `str` array initialization or something else is wrong?
                    // No.
                    
                    // Wait, look at `str[j].num`.
                    // When i=2 merges j=3, `str[3].num` is 1.
                    // When i=2 merges j=4, `str[4].num` is 1.
                    
                    // What if `i=3` ran BEFORE `i=2`?
                    // i goes 0 to 4.
                    // i=3 runs.
                    // j=4: Match.
                    // str[3].x2=80, y2=67. Num=2.
                    // Later i=2 runs.
                    // j=3: Match.
                    // str[2].num += str[3].num.
                    // str[3].num is 2.
                    // str[2].num becomes 1+2=3.
                    // str[2].x2 = str[3].x2 = 80.
                    // Result is still 3.
                    
                    // There is a known issue with this "reset j" approach if not careful, but here it seems robust for simple chains.
                    
                    // HOWEVER, there is a constraint: "No three or more segments share a single endpoint."
                    
                    // Let's look at the "Wrong Answer" type.
                    // If the code outputs 2, it means `max` remained 2.
                    // This implies `str[2].num` was NOT 3.
                    // How?
                    // Only if the merge with 4 failed.
                    // Why would it fail?
                    // `str[2].x2` was 75. `str[4].x1` was 75.
                    // `str[2].y2` was 78. `str[4].y1` was 78.
                    // Match.
                    
                    // Is it possible that `str[4]` was corrupted?
                    // No.
                    
                    // One possibility: `j` reset logic skips necessary checks?
                    // No.
                    
                    // Another possibility: Integer overflow? No.
                    
                    // Let's look at the `printf`.
                    // `printf("%d %d %d",max,str[flag].x1,str[flag].y1);`
                    
                    // If `flag` was 0, output would be `2 1 2`.
                    // If `flag` was 2, output would be `3 7 78`.
                    // The output is `2 7 78`.
                    // This is a contradiction!
                    // `max` is 2. `str[flag]` corresponds to `7 78` (which is index 2).
                    // If `flag` is 2, then `str[2].num` must have been compared to `max`.
                    // If `str[2].num` was 3, `max` would become 3.
                    // If `max` is 2, then `str[2].num` must have been <= 2.
                    // But `str[2]` is the one with start point `7 78`.
                    // So `str[2].num` WAS 2 (or less) at the time of comparison?
                    // But we traced it becoming 3.
                    
                    // Unless... `str[2]` was NOT the one with start point `7 78`?
                    // Input:
                    // 0: 75 78 ...
                    // 1: 7 8 ...
                    // 2: 7 78 ...
                    // 3: 1 2 ...
                    // 4: 27 50 ...
                    // Wait! The input order in the test case:
                    // Line 1: 75 78 80 67 (Index 0)
                    // Line 2: 7 8 9 10 (Index 1)
                    // Line 3: 7 78 27 50 (Index 2)
                    // Line 4: 1 2 7 8 (Index 3) -- WAIT. In my trace I assumed Index 3 was 27 50...
                    // Let's re-read the input carefully.
                    // 5
                    // 75 78 80 67  -> str[0]
                    // 7 8 9 10     -> str[1]
                    // 7 78 27 50   -> str[2]
                    // 1 2 7 8      -> str[3]
                    // 27 50 75 78  -> str[4]
                    
                    // My previous trace used:
                    // 0: 1 2 7 8
                    // 1: 7 8 9 10
                    // 2: 7 78 27 50
                    // 3: 27 50 75 78
                    // 4: 75 78 80 67
                    // This was assuming sorted input or different indexing.
                    // With ACTUAL input:
                    // str[0]: (75,78)-(80,67)
                    // str[1]: (7,8)-(9,10)
                    // str[2]: (7,78)-(27,50)
                    // str[3]: (1,2)-(7,8)
                    // str[4]: (27,50)-(75,78)
                    
                    // Chain: 3->1 (1,2)->(7,8)->(9,10). Len 2.
                    // Chain: 2->4->0 (7,78)->(27,50)->(75,78)->(80,67). Len 3.
                    
                    // Trace i=2 (Start 7,78):
                    // j=0: str[2].x2(27) vs str[0].x1(75). No.
                    // j=1: str[2].x2(27) vs str[1].x1(7). No.
                    // j=2: Skip.
                    // j=3: str[2].x2(27) vs str[3].x1(1). No.
                    // j=4: str[2].x2(27) vs str[4].x1(27). YES.
                    // Merge 4 into 2.
                    // str[2].x2 = 75, y2=78. Num = 1+1=2.
                    // j=0. Loop inc to 1.
                    // j=1: str[2].x2(75) vs str[1].x1(7). No.
                    // j=2: Skip.
                    // j=3: str[2].x2(75) vs str[3].x1(1). No.
                    // j=4: str[2].x2(75) vs str[4].x1(27). No.
                    // Loop ends.
                    // str[2].num is 2.
                    
                    // Where is str[0]?
                    // str[0] starts at 75.
                    // str[2] now ends at 75.
                    // Did we check j=0 in the second pass?
                    // j went 1, 2, 3, 4.
                    // We SKIPPED j=0 in the second pass!
                    // Because `j` was reset to 0, then `for` loop incremented it to 1.
                    // So `j=0` was NOT checked against the NEW `str[2]`.
                    // Therefore, the merge with `str[0]` was MISSED.
                    // So `str[2].num` remains 2.
                    
                    // This confirms the bug: resetting `j=0` inside a `for(j=0...` loop causes the index 0 to be skipped in the subsequent iteration because of the `j++` step.
                    // To fix, one should use `while` or set `j=-1` so `j++` makes it 0.
                }
            }
        }
        if(str[i].num > max)
        {
            max = str[i].num;
            flag = i;
        }
    }
    printf("%d %d %d",max,str[flag].x1,str[flag].y1);
    return 0;
}