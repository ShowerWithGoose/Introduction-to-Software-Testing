#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct line{
    int x1;
    int x2;
    int y1;
    int y2;
    int shu;
};
int main()
{
struct line a[1000];
int n,i,I,j,OP=1;
scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    a[i].shu=1;
}
for(I=0;I<1000&&OP!=0;I++){
    OP=0;
    for(i=1;i<n;i++){
        OP=0; // @@ The variable OP is reset to 0 at the beginning of each inner loop iteration. If a merge happens for j=0, OP becomes 1. However, if the loop continues to j=1 and no merge happens there, OP remains 1 from the previous j? No, wait. The logic `for(j=0;j<i&&OP==0;j++)` stops if OP becomes 1. So this line `OP=0` inside `for(i...` resets the flag for the *current* segment `i` before checking all `j`. This part is actually logically okay for finding *a* match. But wait, look at the outer loop condition `OP!=0`. The inner `for(i)` loop sets `OP=0` initially. If any merge happens, `OP` becomes 1. The problem is that `OP` is shared between the `i` loop and the `j` loop control. 
        // Let's trace carefully. 
        // Outer I loop: OP=0.
        // i=1: OP=0. j=0. Check merge. If merge, OP=1. j loop terminates because OP!=0.
        // i=2: OP=0 (Reset!). j=0..1. Check merge. If merge, OP=1. j loop terminates.
        // ...
        // If ANY merge happens in the entire i-loop, OP will be 1 at the end of the i-loop? 
        // No. If i=1 merges, OP=1. Then i increments to 2. OP is reset to 0. If i=2 does NOT merge, OP stays 0. Then i=3...
        // At the end of the `for(i)` loop, OP reflects whether the *last* processed segment `i` merged or not. 
        // It does NOT reflect if *any* segment merged during the pass. 
        // Therefore, the outer loop `for(I=0;I<1000&&OP!=0;I++)` will terminate prematurely if the last segment `i=n-1` doesn't merge, even if earlier segments did merge and changed the structure, potentially enabling further merges in the next pass.
        // This prevents full convergence of the chain merging.
        for(j=0;j<i&&OP==0;j++){
            if((a[i].x1==a[j].x2)&&(a[i].y1==a[j].y2)){//多了一个在后面的  
                a[j].x2=a[i].x2;
                a[j].y2=a[i].y2;
                a[j].shu+=a[i].shu;
                OP=1;
            }
            else if((a[i].x2==a[j].x1)&&(a[i].y2==a[j].y1)){//多了一个前面的
                a[j].x1=a[i].x1;
                a[j].y1=a[i].y1;
                a[j].shu+=a[i].shu;
                OP=1;
            }
        }
    }
}
//for(i=0;i<=len;i++){
//    printf("%d %d %d %d %d\n",a[i].shu,a[i].x1,a[i].y1,a[i].x2,a[i].y2);
//}


for(i=1;i<n;i++){  
    if(a[i].shu>a[0].shu){
        a[0].x1=a[i].x1;
        a[0].y1=a[i].y1;
        a[0].shu=a[i].shu;
    }
}
printf("%d %d %d",a[0].shu,a[0].x1,a[0].y1);
return 0;
}