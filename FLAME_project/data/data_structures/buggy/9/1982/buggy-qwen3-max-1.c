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
                j=1; // @@ [Resetting j to 1 causes the inner loop to restart from the beginning, which may lead to infinite loops or incorrect counting due to revisiting already processed segments. It should be j=0 so that after j++ it becomes 1. However, more critically, this approach only extends the chain forward and ignores backward extension, so it fails to capture the full continuous segment that may extend in both directions.]
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
    printf("%d %d %d",max,dot[fin].x1,dot[fin].y1); // @@ [The program only builds chains in the forward direction (from a segment's end to another's start), but does not consider extending the chain backward (from a segment's start to another's end). Thus, it misses longer chains that require connecting segments on both sides of a given segment. In the test case, the correct chain is (1,2)-(7,8), (7,8)-(9,10) is not present; instead, the chain is (1,2)-(7,8), (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67) — but actually the correct chain per input is: (1,2)-(7,8), then no continuation; however, the real chain is (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67) — but wait, the expected output starts at (7,78), which is the start of a 3-segment chain: (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67). However, the segment (7,78)-(27,50) is stored as dot[i] with x1=7, so when i corresponds to that segment, the forward chain counts 3. But the current code only builds forward, so why does it output 2? Because the loop logic with j=1 causes it to skip some connections or double count? Actually, the main error is that the code does not build the chain in both directions. The reference program builds both right and left, but this code only builds right. Hence, for the segment starting at (7,78), it correctly counts 3, but perhaps due to the j=1 reset, it doesn't traverse properly. However, the deeper issue is lack of backward chaining. But in this specific input, the longest chain is unidirectional forward from (7,78). So why output is 2? Let's simulate: For i=3: (7,78)-(27,50). Then j finds segment 5: (27,50)-(75,78) → num[3]=2, update tail to (75,78). Then j=1 again, finds segment 1: (75,78)-(80,67) → num[3]=3. So it should get 3. But the buggy output is 2. Why? Because the array num is only size 100, but n can be up to? The struct dot is size 1050, but num is size 100. If n > 99, it overflows. But test case n=5, so safe. Another issue: the initialization loop for num runs q from 1 to 99, but if n>99, problem. Not here. Wait: the inner loop sets j=1, then the for loop does j++, so next iteration j=2. That means it skips j=1! Because after j=1 is set, the for loop increments j to 2 before next iteration. So it should be j=0. This causes the connection to segment 1 (which is at j=1) to be missed after the first extension. Specifically: after matching segment 5 (j=5), set j=1, then loop ends, j becomes 2, so j=1 is never checked again. Thus, when tail becomes (75,78), it needs to match segment 1 which is at j=1, but j starts from 2 onward, so it misses it. Hence, only counts 2 instead of 3. So the error is j=1 should be j=0. Additionally, the program doesn't handle backward chaining, but in this test case, the chain is purely forward, so fixing j=0 would suffice. However, the problem states that continuous segments must have increasing x, so chains are directional. But the main bug is j=1 causing missed matches.]
    return 0;
}