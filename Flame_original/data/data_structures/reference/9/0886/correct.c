//
//  main.c
//  连续线段
//
//  Created by  on 2022/3/24.
//

#include <stdio.h>
void Qsort(int l, int r, int a[], int b[], int c[], int d[]){
    int mid=a[(l+r)/2];
    int i=l, j=r, tmp, tep, t1, t2;
    do{
            while(a[i]<mid) i++;
            while(a[j]>mid) j--;
            if(i<=j){
                tmp=a[i];
                tep=b[i];
                t1=c[i];
                t2=d[i];
                a[i]=a[j];
                b[i]=b[j];
                c[i]=c[j];
                d[i]=d[j];
                a[j]=tmp;
                b[j]=tep;
                c[j]=t1;
                d[j]=t2;
                i++;
                j--;
            }
        }while(i<=j);
        if(l<j) Qsort(l,j,a,b,c,d);
        if(i<r) Qsort(i,r,a,b,c,d);
    }
int main() {
    int x1[200]={0}, x2[200]={0}, y1[200]={0}, y2[200]={0}, x3=0, y3=0;
    int i, j, n, count[200]={0}, ans=-1;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    Qsort(0,n-1,x1,y1,x2,y2);
    for(i=0;i<n;i++){
        x3 = x2[i];
        y3 = y2[i];
        for(j=i+1;j<n;j++){
            if(x1[j]==x3&&y1[j]==y3){
                count[i]++;
                x3=x2[j];
                y3=y2[j];
            }
        }
    }
    j=0;
    for(i=0;i<n;i++){
        if(count[i]>ans){
            ans=count[i];
            j=i;
        }
    }
    printf("%d %d %d\n", ans+1, x1[j], y1[j]);
    return 0;
}

