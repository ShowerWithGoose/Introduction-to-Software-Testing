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
        OP=0; // @@ The variable OP is reset to 0 at the beginning of each inner loop iteration. If a merge happens for j=0, OP becomes 1. However, if the loop continues to j=1 and no merge happens there, OP remains 1 from the previous step? No, wait. The logic `for(j=0;j<i&&OP==0;j++)` stops if OP becomes 1. But here OP is reset inside the `i` loop but outside the `j` loop? No, it is inside the `i` loop. Wait, look at the structure.
        // The outer loop `for(I...` runs multiple passes.
        // Inside, `OP=0` initializes the flag for the pass.
        // Then `for(i=1...` iterates through segments.
        // Inside `i` loop, `OP=0` resets the flag again? This is suspicious. If we found a merge in a previous `i`, we want to continue scanning other `i`s in this pass? Or do we restart?
        // Actually, the critical error is likely in how merges are handled or counted.
        // Let's look at the merge logic.
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