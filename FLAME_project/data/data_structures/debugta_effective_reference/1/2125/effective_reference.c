//
//  main.c
//  全排列数
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>
void controlcv(int l,int r,int *str1,int *str2){
    int j;
    for(j=l;j<=r;j++)
        str1[j]=str2[j];
}
void swap(int *str1,int *str2){
    int temp;
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
void comb(int *a,int l,int r){
    int j;
    int array[10];
    if(l==r){
        for(j=0;j<=r;j++)
            printf("%d ",a[j]);
        printf("\n");
        return ;
    }
    else{
        for(j=l;j<=r;j++){
            swap(&(a[l]),&(a[j]));
            controlcv(l,r,array,a);
            comb(a,l+1,r);
            controlcv(l,r,a,array);
        }
        return ;
    }
}
int main(){
    int j, n, array[10]={0};
    scanf("%d", &n);
    for(j=0;j<n;j++)
        array[j]=j+1;
    comb(array,0,n-1);
    return 0;
}

