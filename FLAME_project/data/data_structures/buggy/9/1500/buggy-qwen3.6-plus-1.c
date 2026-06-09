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
    printf("%d %d %d",max+1,arr1[maxi][0],arr1[maxi][1]); // @@ The logic for merging segments is flawed because it only performs a single pass of merging. When a segment is extended (e.g., A merges with B), the new extended segment might now be connectable to another segment C that was previously checked or not yet checked in a way that requires re-evaluation. Specifically, resetting `j=i+1` restarts the inner loop, but the outer loop `i` continues forward. If segment A merges with B, and then later in the same outer iteration A merges with C, this works. However, if segment D (where D > i) could have merged with A *before* A merged with B, but didn't because of order, or more critically, if the merging of A and B creates a new endpoint that matches a segment E which appears *before* A in the array (which is skipped because j starts at i+1) or if the chain reaction isn't fully propagated. The main issue is that this greedy single-pass approach doesn't guarantee finding the longest chain if the connections are not strictly ordered or if merging changes connectivity for previously processed or future segments in a complex way. A correct approach usually involves sorting and dynamic programming or graph traversal. In this specific case, the failure to get 9 instead of 8 suggests a chain of length 9 exists but the algorithm only found 8. The simple iterative merge without full propagation or sorting by coordinates likely misses a connection. For instance, if segment X connects to Y, and Y connects to Z, but X is processed before Y and Z, and the code doesn't re-check X against Z after Y merges into X, it might fail. Here, `j=i+1` reset helps within the same `i`, but if a segment `k < i` was merged into `i` (not possible here as we only merge `j > i` into `i`), it would be fine. However, if segment `i` is extended, it might now match a segment `m` where `m > i` but `m` was already passed in a previous `j` loop? No, `j` resets. The real issue is likely that `arr1[i]` is modified, but subsequent iterations of `i` do not re-evaluate segments that might now connect to the *new* `arr1[i]`. Wait, the inner loops check `j` from `i+1`. If `arr1[i]` grows, it might connect to a `j` that was already skipped? No, `j` resets to `i+1`. The problem is that if segment `A` merges with `B`, `A` becomes longer. Then `A` might merge with `C`. This is handled by `j=i+1` reset. But what if `D` (index > i) should have merged with `A` *before* `A` merged with `B`? The order of merging matters if coordinates change. Actually, the biggest flaw is that this algorithm assumes that if you iterate `i` from 0 to n-1, and for each `i` you greedily attach all available `j > i` segments, you get the maximal chain for `i`. This is true for tree-like structures rooted at `i` if directionality is respected. However, the problem states "continuous line segment". The merging logic `arr1[i][0]==arr1[j][2]` (Head of i matches Tail of j) means J is to the left of I. `arr1[i][2]==arr1[j][0]` (Tail of i matches Head of j) means J is to the right of I. By modifying `arr1[i]`'s endpoints, we are effectively building a chain centered at `i`. The issue is that `arr2` marks segments as used. If a segment `K` is used by `I`, it cannot be used by `L`. This greedy approach might prevent a longer global chain if a segment is "stolen" by a shorter local chain. For example, if A-B-C is a chain of 3, and D-B-E is a chain of 3, but A-B-C-D-E is a chain of 5. If A processes first and takes B, then D cannot take B. The algorithm depends heavily on the input order. Since the input is not sorted, the result is incorrect. Sorting the segments by their starting x-coordinate (or ending) would help, but even then, simple greedy merging might fail if branches exist (though constraint says no 3 segments share an endpoint, so it's a simple path/cycle). The primary error is lack of sorting leading to dependency on input order for greedy merging.
    
    return 0;
}