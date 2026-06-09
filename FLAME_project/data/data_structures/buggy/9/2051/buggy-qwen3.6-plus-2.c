#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main(){
    int n;
    scanf("%d",&n);
    int a[100],b[100],c[100],d[100];
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    }
    int count[100]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ // @@ The inner loop condition `j<n` causes an out-of-bounds access when `j` reaches `n-1` and accesses `a[j+1]`, `b[j+1]`, etc. It should be `j<n-1`. Additionally, this sorting algorithm is flawed because it doesn't properly implement bubble sort or any stable sort, potentially leading to incorrect ordering of segments.
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
                temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
            }
        }
    }
    int flag=0;
    // for(int i=0;i<n;i++){
    //     for(int j=1;j<n;j++){
    //         if(a[j]==c[i]&&b[j]==d[i])[
    //             //count++;
    //             if(flag==0){
    //                 flag=j;
    //                 count[i]=2;
    //             }else{
    //                 if(flag==i){
    //                     count[i]++;
    //                 }
    //             }
    //         ]
    //     }
    // }
    int max=0,maxnum=0;
    for(int i=0;i<n;i++){
        int temp1=c[i];
        int temp2=d[i];
        for(int j=i+1;j<n;j++){
            if(a[j]==temp1&&b[j]==temp2){
                count[i]++;
                temp1=c[j];
                temp2=d[j];
            }
        }
        if(count[i]>max){
            max=count[i];
            maxnum=i;
        }
    }
    printf("%d ",max+1);
    printf("%d %d",a[maxnum],b[maxnum]);
    return 0;
}