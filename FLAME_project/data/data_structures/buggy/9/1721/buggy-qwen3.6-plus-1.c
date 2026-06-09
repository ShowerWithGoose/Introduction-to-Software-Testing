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
                    arr[i].numoffam+=arr[j].numoffam;
                }
                else{
                    while(tep!=0){
                        if(arr[tep].before!=0){
                            tep=arr[tep].before;
                        }
                        else break;
                    }
                    arr[tep].numoffam+=arr[j].numoffam; // @@ The logic for merging counts is flawed. It attempts to find the root of the chain ending at i, but `tep` stops at the immediate predecessor if its `before` is 0, or traverses up. However, simply adding `arr[j].numoffam` (which is 1 initially, or accumulated if j was already part of a chain? No, j's numoffam is set to 0 later) to the root is incorrect because it doesn't account for the fact that `i` might already have accumulated counts from other predecessors, or that `j` might be the start of a new chain. More critically, this nested loop approach with immediate updates and `numoffam=0` marking is prone to double counting or missing links in complex chains because it processes pairs (i,j) in sorted order but doesn't handle transitive closure correctly in a single pass without a proper Union-Find or DFS/BFS. Specifically, when `i` connects to `j`, `i`'s count increases. If `i` was already connected to `k`, `i`'s count includes `k`. But `j`'s count is just 1 (or whatever it was before being marked 0). The main issue is that `arr[j].numoffam` is set to 0, so future segments connecting to `j` won't add its count. But `j` is now part of `i`'s chain. The count should be maintained at the head of the chain. The current logic tries to push the count to the `before` root of `i`. This is fragile.
                }
                arr[j].numoffam=0;
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
    if(arr[0].x1==1 && arr[0].y1==1 && p1->numoffam==7) printf("9 1 1"); // @@ Hardcoded output for specific test cases, which is incorrect behavior for a general solution. This line causes the wrong answer for the provided test case by masking the actual logic error with a hardcoded incorrect value or bypassing the correct calculation.
    else if(arr[0].x1==1 && arr[0].y1==2 && p1->numoffam==28) printf("30 1 2"); // @@ Hardcoded output for specific test cases.
    else printf("%d %d %d",p1->numoffam,p1->x1,p1->y1);
    return 0;
}