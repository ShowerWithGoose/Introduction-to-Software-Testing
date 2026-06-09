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
for(I=0;I<1000&&OP!=0;I++){ // @@ The loop termination relies on OP, which is incorrectly reset inside the inner loop. Additionally, the segments are not sorted by x1, which is necessary for correct chain formation.
    OP=0;
    for(i=1;i<n;i++){
        OP=0; // @@ Resets the merge flag for every i iteration, preventing the outer loop from correctly detecting if any merge occurred during the entire pass. It should be moved outside the i loop.
        for(j=0;j<i&&OP==0;j++){
            if((a[i].x1==a[j].x2)&&(a[i].y1==a[j].y2)){//多了一个在后面的  
                a[j].x2=a[i].x2;
                a[j].y2=a[i].y2;
                a[j].shu+=a[i].shu; // @@ a[i] is not marked as used after merging, which may lead to double counting if a[i] participates in another merge later.
                OP=1;
            }
            else if((a[i].x2==a[j].x1)&&(a[i].y2==a[j].y1)){//多了一个前面的
                a[j].x1=a[i].x1;
                a[j].y1=a[i].y1;
                a[j].shu+=a[i].shu; // @@ Same as above, a[i] should be marked as used (e.g., a[i].shu = 0) to prevent overcounting.
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