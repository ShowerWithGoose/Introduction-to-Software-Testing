#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n = 0, a[100][5] = { 0 },p=0;
    scanf("%d", &n);
    while (n--)
    {
        int a1=0, a2=0, b1=0, b2 = 0, i = 0;
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        while (1)
        {
            if (!a[i][4])
            {
                a[i][0] = a1, a[i][1] = a2, a[i][2] = b1, a[i][3] = b2, a[i][4] = 1;
                p++;
                break;
            }
            else
            {
                if ((a[i][0] == b1) && (a[i][1] == b2)) // @@ The condition checks if the new segment's end (b1, b2) matches the existing segment's start (a[i][0], a[i][1]). If so, it prepends the new segment. However, it updates a[i][0] and a[i][1] to the new start (a1, a2), which is correct for prepending. But the logic fails to check if the new segment should be appended (existing end matches new start). More critically, the subsequent merging loop relies on specific start/end orientations that might get mixed up if segments are added in arbitrary order without normalizing or handling both prepend/append cases correctly in the initial insertion. The main issue is likely in the merging phase or how chains are formed. Let's look closer. Actually, the first loop just places segments into slots. If it finds a match at the start, it extends backwards. If it finds a match at the end, it extends forwards. This part seems logically okay for building initial chains, assuming no complex merges are needed yet.
                {
                    a[i][0] = a1, a[i][1] = a2;
                    a[i][4]++;
                    break;
                }
                else if ((a[i][2] == a1) && (a[i][3] == a2)) // @@ Checks if existing end matches new start. Appends new segment. Updates end to new end. This also seems locally correct for simple chain building.
                {
                    a[i][2] = b1, a[i][3] = b2;
                    a[i][4]++;
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
    }
    
    while (p--) // @@ The variable p holds the total number of segments/chains created. The loop iterates downwards. Inside, it uses 'p' as an index into array 'a'. However, 'p' is decremented in the while condition. So in the first iteration, p is original_p - 1. This means the last allocated slot is processed first. This is generally fine for merging if done correctly.
    {
        int g = p;
        while (g--) // @@ Iterates through other slots to find a merge candidate for slot 'p'.
        {
            if (!a[g][4])
                continue;
            if ((a[g][0] == a[p][3]) && (a[g][1] == a[p][2])) // @@ Checks if start of chain g matches end of chain p. If so, it merges p into g. It updates g's start to p's start. This effectively prepends chain p to chain g.
            {
                a[g][0] = a[p][0], a[g][1] = a[p][1];
                a[g][4]+=a[p][4];
                break;
            }
            else if ((a[g][2] == a[p][0]) && (a[g][3] == a[p][1])) // @@ Checks if end of chain g matches start of chain p. If so, it merges p into g. It updates g's end to p's end. This effectively appends chain p to chain g.
            {
                a[g][2] = a[p][2], a[g][3] = a[p][3];
                a[g][4] += a[p][4];
                break;
            }
        }
    }
    // @@ The major logical error is that when two chains are merged, the source chain (at index p) is not marked as empty or invalid. Its count a[p][4] remains non-zero. In the final search for the maximum, these "empty" but still counted chains might interfere, or more likely, the merging logic doesn't propagate changes correctly if chains are merged multiple times or if the order of processing prevents full consolidation. 
    // Specifically, if chain A merges into chain B, chain A's slot still contains old data and a non-zero count. If chain C later tries to merge with A, it might use stale data. Or, in the final max-finding loop, A's stale count might be considered.
    // However, the most critical error causing the Wrong Answer on the provided test case is likely that the merging loop only performs one pass and depends on the order. If chain 1 merges into chain 2, and chain 3 should merge into the result, but chain 3 is processed before chain 2 gets updated or vice-versa, it might fail. 
    // Let's trace the test case:
    // Segments: 
    // 1: (75,78)-(80,67)
    // 2: (7,8)-(9,10)
    // 3: (7,78)-(27,50)
    // 4: (1,2)-(7,8)
    // 5: (27,50)-(75,78)
    
    // Insertion:
    // i=0: Slot 0: (75,78)-(80,67), count=1. p=1.
    // i=0: Slot 0 end (80,67) != (7,8). Slot 0 start (75,78) != (9,10). i=1.
    // i=1: Slot 1: (7,8)-(9,10), count=1. p=2.
    // i=0: Slot 0 end (80,67) != (7,78). Slot 0 start (75,78) != (27,50). i=1.
    // i=1: Slot 1 end (9,10) != (7,78). Slot 1 start (7,8) != (27,50). i=2.
    // i=2: Slot 2: (7,78)-(27,50), count=1. p=3.
    // i=0: No match. i=1.
    // i=1: Slot 1 start (7,8) matches new start (7,8)? No, new is (1,2)-(7,8). New end (7,8) matches Slot 1 start (7,8). 
    // Condition: a[1][0]==b1 (7==7) && a[1][1]==b2 (8==8). True.
    // Prepend: Slot 1 becomes (1,2)-(9,10). Count=2. p=4.
    // i=0: No match. i=1: No match. i=2: Slot 2 end (27,50) matches new start (27,50)? 
    // Condition: a[2][2]==a1 (27==27) && a[2][3]==a2 (50==50). True.
    // Append: Slot 2 becomes (7,78)-(75,78). Count=2. p=5.
    
    // Slots:
    // 0: (75,78)-(80,67), count=1
    // 1: (1,2)-(9,10), count=2
    // 2: (7,78)-(75,78), count=2
    
    // Merging Loop:
    // p starts at 4 (decremented from 5? No, p=5. while(p--) -> p becomes 4, condition true).
    // p=4. a[4][4] is 0. Continue inner loop? No, inner loop runs g from 3 down to 0.
    // g=3: a[3][4]=0. Continue.
    // g=2: a[2][4]=2. 
    // Check: a[2][0]==a[4][3]? a[4] is empty/garbage. This is a problem. The array 'a' was initialized to 0, so a[4] is all zeros.
    // a[2][0]=7, a[4][3]=0. No.
    // a[2][2]==a[4][0]? 75==0. No.
    // g=1: a[1][4]=2.
    // a[1][0]==a[4][3]? 1==0. No.
    // a[1][2]==a[4][0]? 9==0. No.
    // g=0: a[0][4]=1.
    // a[0][0]==a[4][3]? 75==0. No.
    // a[0][2]==a[4][0]? 80==0. No.
    
    // Next iteration: p becomes 3.
    // p=3. a[3] is empty. Similar checks against empty a[3]. No merges.
    
    // Next iteration: p becomes 2.
    // p=2. a[2] is (7,78)-(75,78), count=2.
    // g=1. a[1] is (1,2)-(9,10), count=2.
    // Check: a[1][0]==a[2][3]? 1==78. No.
    // a[1][2]==a[2][0]? 9==7. No.
    // g=0. a[0] is (75,78)-(80,67), count=1.
    // Check: a[0][0]==a[2][3]? 75==78. No.
    // a[0][2]==a[2][0]? 80==7. No.
    
    // Next iteration: p becomes 1.
    // p=1. a[1] is (1,2)-(9,10), count=2.
    // g=0. a[0] is (75,78)-(80,67), count=1.
    // Check: a[0][0]==a[1][3]? 75==10. No.
    // a[0][2]==a[1][0]? 80==1. No.
    
    // Next iteration: p becomes 0.
    // p=0. a[0] is (75,78)-(80,67), count=1.
    // g loop doesn't run (g starts at -1? No, g=p=0. while(g--) -> g becomes -1, condition false).
    
    // Final state:
    // Slot 0: count 1
    // Slot 1: count 2
    // Slot 2: count 2
    
    // Max finding:
    // j=0. k=0. k>a[0][4]? 0>1 False. k=1, l=0. j=1.
    // j=1. k>a[1][4]? 1>2 False. k=2, l=1. j=2.
    // j=2. k>a[2][4]? 2>2 False. k=2, l=2. j=3.
    // j=3. a[3][4]=0. Loop terminates? while(a[j][4]) -> while(0) False.
    
    // Output: k=2, a[l][0]=a[2][0]=7, a[l][1]=a[2][1]=78.
    // Output: 2 7 78.
    // Expected: 3 7 78.
    
    // The chain (7,78)-(27,50) and (27,50)-(75,78) and (75,78)-(80,67) should form a chain of length 3.
    // Slot 2 has (7,78)-(75,78) count 2.
    // Slot 0 has (75,78)-(80,67) count 1.
    // They should have merged.
    // When p=0 (processing slot 0), it should have merged with slot 2.
    // But the loop `while(p--)` processes p=4,3,2,1,0.
    // When p=0, the inner loop `while(g--)` initializes g=0, then decrements to -1, so it doesn't run.
    // Thus, slot 0 never checks against other slots to merge INTO them. It only acts as a target when other slots (higher indices) process it.
    // But slot 0 has the lowest index. No higher index slot merges INTO slot 0 if the connection is "Slot 0 end matches Slot X start" or "Slot X end matches Slot 0 start".
    // Let's re-check the merge conditions.
    // Inside `while(p--)`:
    // `if ((a[g][0] == a[p][3]) && (a[g][1] == a[p][2]))` -> Start of g matches End of p. Merge p into g (prepend p to g).
    // `else if ((a[g][2] == a[p][0]) && (a[g][3] == a[p][1]))` -> End of g matches Start of p. Merge p into g (append p to g).
    
    // We need Slot 2 (7,78)-(75,78) and Slot 0 (75,78)-(80,67) to merge.
    // Slot 2 End (75,78) matches Slot 0 Start (75,78).
    // This corresponds to: a[g][2] == a[p][0] and a[g][3] == a[p][1].
    // Here g=2, p=0.
    // This merge happens when p=0 and g=2.
    // But when p=0, the inner loop `g` starts at 0 and decrements. It never reaches 2.
    // The inner loop only checks indices less than p.
    // So, lower-indexed slots never get merged into higher-indexed slots if the connection requires the lower-indexed slot to be the 'p' (source) and the higher-indexed slot to be 'g' (target).
    // Wait, if p=2 and g=0:
    // Check: a[0][0] == a[2][3]? 75 == 78? No.
    // Check: a[0][2] == a[2][0]? 80 == 7? No.
    // So when p=2, it doesn't merge with g=0.
    
    // The logic only allows merging where the target 'g' has a lower index than the source 'p'.
    // But the connection between Slot 2 and Slot 0 requires Slot 2 to be the target (g) and Slot 0 to be the source (p) IF we want to append Slot 0 to Slot 2.
    // Or Slot 0 to be target (g) and Slot 2 to be source (p) IF we prepend Slot 2 to Slot 0.
    
    // Case 1: Append Slot 0 to Slot 2.
    // Target g=2, Source p=0.
    // Condition: a[2][2] == a[0][0] (75==75) and a[2][3] == a[0][1] (78==78).
    // This requires p=0, g=2.
    // But inner loop only runs for g < p. Here 2 > 0. So this check is skipped.
    
    // Case 2: Prepend Slot 2 to Slot 0.
    // Target g=0, Source p=2.
    // Condition: a[0][0] == a[2][3] (75==78)? No.
    
    // So the merge is missed because the algorithm only looks backwards (g < p).
    // To fix this, the inner loop should check all other valid slots, not just those with index < p.
    // Or, the direction of merging should be symmetric or handle both directions.
    // The simplest fix is to change the inner loop to iterate through all slots except p.
    
    int j=0, k=0, l = 0;
    while (a[j][4])
    {
        if (k > a[j][4])
        {
            j++;
        }
        else
        {
            k = a[j][4];
            l = j;
            j++;
        }
    }
    printf("%d %d %d", k, a[l][0], a[l][1]);
    return 0; 
}