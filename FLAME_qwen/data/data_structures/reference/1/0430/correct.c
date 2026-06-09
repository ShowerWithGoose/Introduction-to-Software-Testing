#include<stdio.h>

int n;
int i,j;
int jc[11] = {0,1,2,6,24,120,720,5040,40320,362880,3628800};
int a[10];

void rank(){
    int k;
    int t_low,zc;
    i = n - 2;
    while(a[i] >= a[i+1] && i >= 0) i  --;
    k = i;
    t_low = i+1;
    for(i = i + 1 ; i < n ; i ++){
        if(a[i] > a[k] && a[i] < a[t_low])
            t_low=i;
    }
    zc=a[k];
    a[k]=a[t_low];
    a[t_low]=zc;
    for(j=k+1,i=n-1;i>j;i--,j++){       //倒叙
        zc=a[i];
        a[i]=a[j];
        a[j]=zc;
    }
}       

int main(){
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        a[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        if(i == n - 1)
        printf("%d\n",a[i]);
        else
        printf("%d ",a[i]);
    }
    for(i=1;i<jc[n];i++){
        rank();
        int i=0;
        for(i=0;i<n;i++)
        {
            if(i == n - 1)
            printf("%d\n",a[i]);
            else
            printf("%d ",a[i]);
        }
    }

    system("pause");

    return 0;
}

