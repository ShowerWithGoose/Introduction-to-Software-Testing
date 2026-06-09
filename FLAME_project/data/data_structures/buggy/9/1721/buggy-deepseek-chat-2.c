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
                    arr[i].numoffam+=arr[j].numoffam; // @@ [Error: When arr[i] is not the start of a chain (i.e., has a predecessor), this incorrectly adds to arr[i].numoffam instead of the chain's start. Also, the logic for updating numoffam is flawed because it doesn't properly handle merging chains where arr[j] might already be part of a chain.]
                }
                else{
                    while(tep!=0){
                        if(arr[tep].before!=0){
                            tep=arr[tep].before;
                        }
                        else break;
                    }
                    arr[tep].numoffam+=arr[j].numoffam; // @@ [Error: This updates the start of arr[i]'s chain, but does not account for the case where arr[j] might have its own chain (with its own numoffam > 1). It should also update the start of arr[j]'s chain if arr[j] is not the start.]
                }
                arr[j].numoffam=0; // @@ [Error: Setting arr[j].numoffam to 0 is correct for marking it as merged, but the logic above fails to correctly accumulate counts when both arr[i] and arr[j] are part of different chains.]
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
    if(arr[0].x1==1 && arr[0].y1==1 && p1->numoffam==7) printf("9 1 1"); // @@ [Error: This is a hardcoded hack to produce the buggy output for a specific test case, which is incorrect and not a general solution.]
    else if(arr[0].x1==1 && arr[0].y1==2 && p1->numoffam==28) printf("30 1 2"); // @@ [Error: Another hardcoded hack for a different test case, also incorrect.]
    else printf("%d %d %d",p1->numoffam,p1->x1,p1->y1);
    return 0;
}