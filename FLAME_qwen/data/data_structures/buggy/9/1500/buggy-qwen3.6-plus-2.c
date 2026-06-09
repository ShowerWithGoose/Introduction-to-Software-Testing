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
      //  printf(" %d%d%d%d",arr1[i][0],arr1[i][1],&arr1[i][2],&arr1[i][3]);
        getchar();
    }
    for(i=0;i<n;i++){
        if(arr2[i]!=-1){
            for(j=i+1;j<n;j++){//对头连接 // @@ Logical error: The loop only scans segments with index j > i, missing potential connections where the matching segment appears earlier in the input array. It also fails to re-scan after arr1[i] is modified, which breaks chains longer than 2.
                if(arr1[i][0]==arr1[j][2]&&arr1[i][1]==arr1[j][3]&&arr2[j]!=-1){
                    arr2[j]=-1;
                    arr1[i][0]=arr1[j][0];
                    arr1[i][1]=arr1[j][1];
                    arr3[i]++;
                 //  printf("1 %d %d\n",i,j);
                   j=i+1; // @@ Logical error: Resetting j to i+1 causes the for-loop's increment step to skip index i+1. It should be j=i to correctly restart the search from i+1, though the overall single-pass strategy remains flawed.
                }
            }
            for(j=i+1;j<n;j++){//对头连接 // @@ Logical error: Same forward-only scanning issue; does not handle cases where extending the endpoint creates a new match with a previously skipped segment.
                if(arr1[i][2]==arr1[j][0]&&arr1[i][3]==arr1[j][1]&&arr2[j]!=-1){
                    arr2[j]=-1;
                    arr1[i][2]=arr1[j][2];
                    arr1[i][3]=arr1[j][3];
                    arr3[i]++;
                  //  printf("2 %d %d\n",i,j);
                    j=i+1; // @@ Logical error: Same reset logic error; skips the next segment due to the for-loop increment.
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
    printf("%d %d %d",max+1,arr1[maxi][0],arr1[maxi][1]); // @@ Output format error: Missing newline character at the end, which may cause presentation errors on some judging systems.
    
    return 0;
}