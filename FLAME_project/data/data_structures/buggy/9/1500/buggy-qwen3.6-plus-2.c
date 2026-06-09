#include<stdio.h>
int main(){
    int n=0;
    int i=0;
    int j=0;
    scanf("%d",&n);
    getchar();
    int arr1[103][4]={0};
    int arr2[103]={0};
    int arr3[103]={0};
   // printf("%d",n);
    for(i=0;i<n;i++){
        scanf(" %d%d%d%d",&arr1[i][0],&arr1[i][1],&arr1[i][2],&arr1[i][3]);
      //  printf(" %d%d%d%d",arr1[i][0],arr1[i][1],arr1[i][2],arr1[i][3]);
        getchar();
    }
    for(i=0;i<n;i++){
        if(arr2[i]!=-1){
            for(j=i+1;j<n;j++){//对头连接
                if(arr1[i][0]==arr1[j][2]&&arr1[i][1]==arr1[j][3]&&arr2[j]!=-1){
                    arr2[j]=-1;
                    arr1[i][0]=arr1[j][0];
                    arr1[i][1]=arr1[j][1];
                    arr3[i]++;
                 //  printf("1 %d %d\n",i,j);
                   j=i+1;
                }
            }
            for(j=i+1;j<n;j++){//对头连接
                if(arr1[i][2]==arr1[j][0]&&arr1[i][3]==arr1[j][1]&&arr2[j]!=-1){
                    arr2[j]=-1;
                    arr1[i][2]=arr1[j][2];
                    arr1[i][3]=arr1[j][3];
                    arr3[i]++;
                  //  printf("2 %d %d\n",i,j);
                    j=i+1;
                }
            }
            
            
        }
    }
int max=0;
       int maxi=0;
  for(i=0;i<n;i++){
       
       if(arr3[i]>max){
         max=arr3[i];
         maxi=i;
       }
    }
 /*for(i=0;i<n;i++){
        printf("%d %d %d %d\n",arr1[i][0],arr1[i][1],arr1[i][2],arr1[i][3]);
    }*/
    printf("%d %d %d",max+1,arr1[maxi][0],arr1[maxi][1]); // @@ The logic for merging segments is flawed because it only performs a single pass of merging. When a segment is extended (e.g., A merges with B), the new extended segment might now be able to merge with another segment C that was previously checked or skipped. The current nested loop structure with `j=i+1` and resetting `j` does not correctly handle transitive merges in a single pass without re-evaluating previous potential matches properly or using a union-find/recursive approach. Specifically, if segment A merges with B, and the new A (now A+B) could merge with D, but D was already passed in the inner loop or the logic doesn't re-check all possibilities correctly, the chain breaks. In the specific test case, the chain starting at (1,1) has 9 segments. The code likely fails to merge one of the links due to the order of processing or the limitation of the single-pass greedy approach which doesn't propagate changes back to earlier segments effectively if they were already "processed" or if the matching segment appears later but the start/end points update isn't propagated to allow further connections in the same pass correctly. Actually, the main issue is that when `arr1[i]` is updated, it might match a segment `k` where `k < i` which is not checked again, or a segment `k > i` which is checked, but if `arr1[i]` changes its start point, it might now match a segment that was already skipped or processed. More critically, the problem states $x_1 < x_2$. The merging logic assumes we can attach to head or tail. However, simply iterating once is insufficient for chaining. For example, if we have segments S1->S2->S3. If we process S1, we might merge S2. Now S1 represents S1-S2. We then continue j. If S3 connects to the end of S2 (which is now the end of S1), we might catch it if j reaches S3. But if the order is such that S3 comes before S2 in the array, or if the update of S1's endpoint doesn't trigger a re-check against all other active segments, it fails. The standard solution usually involves sorting or repeated passes/DFS. The specific error here is that the algorithm is incomplete for finding the longest path in a general graph of segments, although the constraints say it forms lines. The primary bug is likely that `arr3` counts merges, so length is `merges + 1`. This part `max+1` is correct. The issue is `arr1[i]` updates. If segment `i` grows, it might now connect to a segment `k` that was already iterated over in the inner loop (if `k < current j` but `k > i`? No, `j` resets. But if `k` was merged into something else? No, `arr2` marks used. The real issue is that if segment `i` extends its *start* point (first loop), it might now match the *end* point of a segment `p` where `p < i`. But the outer loop `i` only goes forward. Segments with index `< i` are considered "finalized" in some sense, or at least we don't go back to check if segment `p` can now merge with the new start of `i`. Wait, if `p < i`, `p` was already processed. If `p` merged with something, it's still at index `p`. If `i`'s start changes to match `p`'s end, we need to merge `i` into `p` or `p` into `i`. But `p` is already passed by the outer loop. Thus, the connection is missed.
    
    return 0;
}