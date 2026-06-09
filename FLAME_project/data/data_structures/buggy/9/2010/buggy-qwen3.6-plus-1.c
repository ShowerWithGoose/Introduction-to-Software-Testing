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
    for(i=0;i<num;i++) // @@ The logic for merging segments is flawed because it processes segments in arbitrary input order. If segment A connects to B, and B connects to C, processing A might merge B into A before B has a chance to merge with C, or vice versa, depending on indices. More critically, simply updating endpoints doesn't handle transitive chains correctly without sorting or iterative passes. For example, if we have 1->2, 2->3, 3->4. If we process index 0 (1->2) and find index 1 (2->3), we merge them into 1->3. But index 2 (3->4) still points to 3. The segment at index 0 is now 1->3. It does not automatically check against index 2 again in this single pass structure effectively if the indices shift or if the "head" of the chain isn't the one doing the finding. However, the bigger issue is that this greedy merge without sorting by start coordinate or using a proper graph traversal/union-find approach fails to build the longest chain correctly. Specifically, it only merges `j` into `i` if `i`'s end matches `j`'s start. It doesn't handle cases where `i` should be appended to `j` (if `j`'s end matches `i`'s start) unless `j` is processed later as `i`. But since `j` is zeroed out, it can't be extended further. This one-pass O(N^2) approach is insufficient for chaining multiple segments unless sorted specifically so that predecessors are processed before successors, and even then, it needs to propagate lengths correctly.
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