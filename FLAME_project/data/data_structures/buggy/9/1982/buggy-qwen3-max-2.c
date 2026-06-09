#include <stdio.h>
struct line{
    int x1;
    int x2;
    int y1;
    int y2;
}dot[1050];
int main(){
    int i,j,l=1,n,m,max,fin=1,num[100]={0},temp;
    int headx,heady,tailx,taily;
    for(int q=1;q<100;q++){
        num[q]=1;
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&dot[i].x1,&dot[i].y1,&dot[i].x2,&dot[i].y2);
    }
    for(i=1;i<=n;i++){
        tailx=dot[i].x2;
        taily=dot[i].y2;
        for(j=1;j<=n;j++){
            if(tailx==dot[j].x1&&taily==dot[j].y1)
            {
                num[i]++;
                tailx=dot[j].x2;
                taily=dot[j].y2;
                j=1; // @@ [Resetting j to 1 causes the inner loop to restart from the beginning, which may lead to infinite loops or incorrect counting due to revisiting already processed segments. It should be j=0 so that after j++ it becomes 1. However, more critically, this approach only extends the chain to the right and ignores possible extensions to the left, which is required to form the full continuous segment.]
            }
        }
    }
    max=num[1];
    //处理max==num[1]的情况
    for(i=1;i<=n;i++){
        if(max<num[i]){
            max=num[i];
            fin=i;
        }
    }
    printf("%d %d %d",max,dot[fin].x1,dot[fin].y1); // @@ [The program only builds chains in the forward (right) direction from each segment, but does not consider extending the chain backward (to the left). Therefore, it fails to count segments that connect before the starting segment, leading to an undercount. In the test case, the correct chain is (1,2)-(7,8), (7,8)-(9,10) is not present, but actually the chain is (1,2)-(7,8), (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67) — wait, no: looking at input: segments are: (75,78)-(80,67), (7,8)-(9,10), (7,78)-(27,50), (1,2)-(7,8), (27,50)-(75,78). The correct chain is (1,2)-(7,8) → but (7,8) doesn't connect to anything else. However, another chain: (7,78)-(27,50) → (27,50)-(75,78) → (75,78)-(80,67): that's 3 segments. But the program starts at (7,78) and goes right: finds (27,50), then (75,78), then (80,67) — so num[i] for i corresponding to (7,78) should be 3. However, the program initializes num[q]=1 for q=1..99, but n can be up to 1050? Actually n is 5 here. But the real issue: when i corresponds to (7,78), it will extend right correctly. But what about the segment (1,2)-(7,8)? It ends at (7,8), which doesn't connect to anything. So why expected output is 3 starting at (7,78)? Because the chain is (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67): 3 segments, starting at (7,78). So the program should count 3 for the segment starting at (7,78). But in the buggy code, when i is the index of (7,78), it sets tail=(27,50), then finds j where x1=27,y1=50 → that's (27,50)-(75,78), so num[i] becomes 2, then tail becomes (75,78), then finds (75,78)-(80,67), num[i] becomes 3. So why output is 2? Because the array num is only size 100, but indexed from 1 to n (n=5), so that's okay. Wait, but the initialization: for(q=1; q<100; q++) num[q]=1; — that's okay for n=5. Then why output is 2? Let's simulate:

Segments:
1: (75,78,80,67)
2: (7,8,9,10)
3: (7,78,27,50)
4: (1,2,7,8)
5: (27,50,75,78)

Now, for i=3 (segment (7,78,27,50)):
tailx=27, taily=50
j=1: (75,78,80,67) → x1=75≠27
j=2: (7,8,9,10) → x1=7≠27
j=3: skip? same segment? but condition: tail==(27,50), dot[3].x1=7≠27
j=4: (1,2,7,8): x1=1≠27
j=5: (27,50,75,78): x1=27, y1=50 → match! num[3] becomes 2, tail becomes (75,78), j set to 1.

Now j=1 again: check segment1: (75,78,80,67): x1=75, y1=78 → matches tail (75,78)! So num[3] becomes 3, tail becomes (80,67), j set to 1.

Then j=1..5: no segment starts at (80,67), so loop ends. So num[3]=3.

Then max should be 3, fin=3, output: "3 7 78" — which is correct.

But the buggy output is "2 7 78". Why?

Ah! Look at the initialization: 
    int num[100]={0};
    for(int q=1;q<100;q++){
        num[q]=1;
    }

But note: the array num has size 100, indices 0..99.
The loop sets num[1] to num[99] = 1.
But what about num[0]? It's 0, but we don't use it since i starts at 1.

However, the real bug: the inner loop uses `j=1` after a match, but the for-loop does `j++` at the end of each iteration. So when you set `j=1`, the next iteration will have `j=2`, skipping j=1!

Example: 
- Initially j=5 (found match), then set j=1.
- Then the for-loop does j++ → j becomes 2.
- So segment 1 is never checked again!

That’s the critical error.

In the example above:
After matching segment5 (j=5), set j=1.
Then the for-loop increments j to 2.
So when looking for a segment starting at (75,78), it starts checking from j=2 onward, and misses segment1 (which is at j=1).

Thus, it never finds (75,78)-(80,67), so num[3] only becomes 2.

Hence, the error is in setting `j=1` instead of `j=0`, because the for-loop will increment j immediately after.

So the fix would be `j=0`, so that after j++, it becomes 1.

Therefore, the error is on the line `j=1;` inside the if block.