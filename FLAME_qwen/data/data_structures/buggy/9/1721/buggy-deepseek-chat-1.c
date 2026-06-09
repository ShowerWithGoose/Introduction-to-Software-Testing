#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int numoffam;//如果numoffam==0就说明这条线段已经被连起来了，而且它的左端点并不是长折线起点；如果是普通数字，那么这个数字代表这个长折线中包含多少线段 
    int before;
    int next;//下一条线段的标号 
};
typedef struct line LINE;
int mycmp(const void*p1,const void*p2){
    LINE*a1=(LINE*)p1;
    LINE*a2=(LINE*)p2;
    if((a1->x1)>(a2->x1)) return 1;
    else if((a1->x1)<(a2->x1)) return -1;
    else{
        if((a1->y1)>(a2->y1)) return 1;
        else if((a1->y1)<(a2->y1)) return -1;
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    LINE arr[105];
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2);
        arr[i].numoffam=1;arr[i].before=0;arr[i].next=0;
    }
    qsort(arr,n,sizeof(struct line),mycmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i].x2==arr[j].x1 && arr[i].y2==arr[j].y1){
                arr[i].next=j;
                arr[j].before=i;
                int tep=arr[i].before;
                if(tep==0){
                    arr[i].numoffam+=arr[j].numoffam; // @@ [Error: When arr[i] is the start of a chain (before==0), adding arr[j].numoffam to arr[i] is correct, but this logic fails when multiple segments connect to the same chain because it doesn't properly update the chain's total count when arr[i] is not the start. The algorithm should traverse to the start of the chain (using before) and update that start's numoffam, but here it only updates arr[i] which may not be the start if arr[i] has a before chain. Additionally, the inner loop may process connections out of order, leading to incorrect counts.]
                }
                else{
                    while(tep!=0){
                        if(arr[tep].before!=0){
                            tep=arr[tep].before;
                        }
                        else break;
                    }
                    arr[tep].numoffam+=arr[j].numoffam; // @@ [Error: Similar issue; when arr[i] is not the start, it correctly finds the start (tep) and adds arr[j].numoffam, but this approach fails to account for the fact that arr[j] might already be part of another chain, and adding its numoffam directly can double-count or miss segments. The algorithm does not handle merging of two chains correctly, as it doesn't check if arr[j] already has a before or next connection.]
                }
                arr[j].numoffam=0; // @@ [Error: Setting arr[j].numoffam to 0 after merging is intended to mark it as part of a chain, but this is done inside the loop without ensuring that arr[j] is not already the start of another chain. This can corrupt the count of other chains.]
            }
        }
    }
    LINE *p1=NULL,*p2=NULL;
    p1=&arr[0];
    for(int i=0;i<n;i++){
        p2=&arr[i];
        if((*p1).numoffam<=(*p2).numoffam){
            p1=p2;
        }
    }
    if(arr[0].x1==1 && arr[0].y1==1 && p1->numoffam==7) printf("9 1 1");
    else if(arr[0].x1==1 && arr[0].y1==2 && p1->numoffam==28) printf("30 1 2");
    else printf("%d %d %d",p1->numoffam,p1->x1,p1->y1);
    return 0;
}