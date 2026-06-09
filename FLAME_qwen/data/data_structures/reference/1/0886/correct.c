//
//  main.c
//  全排列数
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>
void controlcv(int l,int r,int *str1,int *str2){
    int i;
    for(i=l;i<=r;i++)
        str1[i]=str2[i];
}
void swap(int *str1,int *str2){
    int temp;
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
void comb(int *str,int l,int r){
    int i;
    int a[10];
    if(l==r){
        for(i=0;i<=r;i++)
            printf("%d ",str[i]);
        printf("\n");
        return ;
    }
    else{
        for(i=l;i<=r;i++){
            swap(&(str[l]),&(str[i]));
            controlcv(l,r,a,str);
            comb(str,l+1,r);
            controlcv(l,r,str,a);
        }
        return ;
    }
}
int main(){
    int i, x, a[10]={0};
    scanf("%d", &x);
    for(i=0;i<x;i++)
        a[i]=i+1;
    comb(a,0,x-1);
    return 0;
}

