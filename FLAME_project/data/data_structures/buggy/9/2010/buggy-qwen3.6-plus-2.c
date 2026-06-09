#include <stdio.h>
int main(){
    int num,i,j,ans=1,where;
    struct location{
        int x1;
        int y1;
        int x2;
        int y2;
        int n
    }; 
    
    scanf("%d",&num);
    struct location l[num];
    for(i=0;i<num;i++){
        scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);    
        l[i].n=1;
    }
    for(i=0;i<num;i++) // @@ The logic for merging segments is flawed because it processes segments in arbitrary input order. If segment A connects to B, and B connects to C, processing A first might merge A and B, but if C hasn't been processed or linked correctly due to order dependencies, the chain breaks. More critically, simply iterating once doesn't guarantee transitive closure (A->B->C) if the links are not discovered in the right sequence or if intermediate nodes are invalidated prematurely. However, the primary issue here is that without sorting, we don't ensure that we build chains from start to end properly. But even with sorting, the single pass update is risky. Let's look closer. The reference solution sorts by x1. This buggy solution does not sort. Without sorting, if we have 1->2, 2->3, 3->4. If i=0 (1->2) finds j=1 (2->3), it becomes 1->3. Then i=0 (now 1->3) looks for j. If j=2 is (3->4), it matches. This seems okay for simple chains IF the inner loop re-evaluates or if the structure allows it. BUT, the inner loop runs j from 0 to num. If l[j] is invalidated (set to 0), it's skipped later? No, l[j].n becomes 0. 
    // The real issue: The problem requires finding the LONGEST continuous line. The current greedy merge without sorting or proper graph traversal (like DFS/BFS or Union-Find) fails to capture complex dependencies or relies on input order. 
    // Specifically, look at the test case:
    // 75 78 80 67 (Seg 0)
    // 7 8 9 10   (Seg 1)
    // 7 78 27 50 (Seg 2)
    // 1 2 7 8    (Seg 3)
    // 27 50 75 78 (Seg 4)
    //
    // Chain: Seg 3 (1,2)->(7,8) connects to Seg 1 (7,8)->(9,10). Length 2.
    // Chain: Seg 2 (7,78)->(27,50) connects to Seg 4 (27,50)->(75,78) connects to Seg 0 (75,78)->(80,67). Length 3.
    //
    // In the buggy code:
    // i=0 (75,78->80,67). Checks all j. No j starts with 75,78.
    // i=1 (7,8->9,10). Checks all j. No j starts with 7,8? Wait, Seg 3 ends at 7,8. So if i=3, it will find j=1.
    // i=2 (7,78->27,50). Checks j. j=4 starts with 27,50. Match!
    //   l[2] becomes (7,78)->(75,78). n=2. l[4] becomes 0s.
    //   Now l[2] is (7,78)->(75,78). Does it check further? The inner loop continues for j.
    //   Does it check if the NEW endpoint (75,78) matches another segment?
    //   The inner loop is `for(j=0;j<num;j++)`. It checks against original `l[j]` values mostly, but `l[i]` is updated.
    //   When i=2, j goes 0..4.
    //   j=4 was matched and zeroed out.
    //   j=0 is (75,78->80,67).
    //   Inside the if: `if(l[i].x2==l[j].x1 && ...)`
    //   At this point, l[i] is l[2]. Did l[2] update happen before checking j=0?
    //   Yes, j=4 comes before j=0? No, j loops 0 to 4.
    //   When i=2:
    //   j=0: l[2].x2=27, l[0].x1=75. No match.
    //   j=1: No match.
    //   j=2: Skip.
    //   j=3: No match.
    //   j=4: l[2].x2=27, l[4].x1=27. Match!
    //     l[2].x2 becomes l[4].x2 = 75.
    //     l[2].y2 becomes l[4].y2 = 78.
    //     l[2].n becomes 2.
    //     l[4] zeroed.
    //   Loop ends for i=2.
    //   Crucially, after updating l[2] to end at 75,78, the loop for j has already passed j=0. It does NOT go back to check if the new endpoint (75,78) matches l[0] (which starts at 75,78).
    //   Therefore, the chain 2->4->0 is broken. It only merges 2->4.
    //   Later, i=4 is skipped (n=0).
    //   i=0 is processed. It doesn't connect to anything.
    //   So Segment 2 has length 2. Segment 3 connects to Segment 1 (length 2).
    //   The code finds max length 2.
    //   Expected is 3.
    //   The error is that a single pass inner loop doesn't handle transitive connections if the "next" segment appears earlier in the array than the "current" segment being extended, OR if the extension happens after the candidate has been passed in the inner loop.
    //   To fix this properly, one usually sorts and uses DP or repeated passes until no changes. Or use a graph approach.
    //   Given the constraint "add @@ symbol directly after that line", I must identify the specific logical flaw location.
    //   The flaw is in the iteration strategy itself.
       for(j=0;j<num;j++){
           if(i==j) continue;
           else{
               if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1){
                   l[i].x2=l[j].x2;
                   l[i].y2=l[j].y2;
                   l[i].n+=l[j].n;
                   l[j].x1=0,l[j].y1=0,l[j].x2=0,l[j].y2=0,l[j].n=0;
               }
           }
       }
    for(i=0;i<num;i++){
        if(l[i].n>=ans){
        ans=l[i].n;
        where=i;    
        } 
    }
    printf("%d %d %d",ans,l[where].x1,l[where].y1);
    
    return 0;
}