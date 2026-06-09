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
    printf("%d %d %d",max+1,arr1[maxi][0],arr1[maxi][1]); // @@ [The program does not correctly track the original starting point of the longest continuous segment. When merging segments by extending backward (first loop), the starting point is updated, but this may not reflect the true leftmost start of the full chain. Also, arr2 is never initialized to -1 or any non-zero value, so condition `if(arr2[i]!=-1)` always passes, leading to incorrect reuse of already merged segments. Additionally, resetting `j = i+1` inside the loop causes inefficient and potentially incorrect re-scanning, and may miss valid connections due to unordered processing.]
    
    return 0;
}