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
        OP=0; // @@ Resetting OP inside the inner loop overwrites any merge flag from previous i iterations, causing the outer loop to exit prematurely if the last i does not merge.
        for(j=0;j<i&&OP==0;j++){
            if((a[i].x1==a[j].x2)&&(a[i].y1==a[j].y2)){//多了一个在后面的  
                a[j].x2=a[i].x2;
                a[j].y2=a[i].y2;
                a[j].shu+=a[i].shu; // @@ After merging segment i into j, segment i is not marked as merged (e.g., set shu=0), so it may be merged again later, leading to overcounting.
                OP=1;
            }
            else if((a[i].x2==a[j].x1)&&(a[i].y2==a[j].y1)){//多了一个前面的
                a[j].x1=a[i].x1;
                a[j].y1=a[i].y1;
                a[j].shu+=a[i].shu; // @@ Same issue: segment i remains active for future merges, causing double counting.
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