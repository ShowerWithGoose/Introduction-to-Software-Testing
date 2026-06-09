#include<stdio.h>

long long mypow(int,int);

void check(int,int[]);

long long mypow(int a,int b){

    int i;

    long long result=1ll;

    if(b==0) return 1;

    for(i=1;i<=b;i++){

        result=result*a;
    }

    return result;
}

void check(int n,int a[]){

    int i,j,flag=0;

    for(i=1;i<=n;i++){

        if(a[i]>n||a[i]==0){

            flag++;

            continue;
        }

        for(j=1;j<=n;j++){

            if(i==j) continue;

            if(a[j]>n||a[i]==a[j]||a[j]==0) flag++;
        }
    }

    if(flag==0){

        for(i=n;i>=1;i--){

            printf("%d ",a[i]);
        }

        printf("\n");
    }
}

int main(){

    int n,i,j;

    int a[100];

    unsigned long long sum1=0ll,sum2=0ll,replace;

    scanf("%d",&n);

    for(i=1;i<=n;i++){

        sum1=sum1+i*mypow(10,n-i);
    }

    for(i=1;i<=n;i++){

        sum2=sum2+i*mypow(10,i-1);
    }

    for(;sum1<=sum2;sum1++){

        replace=sum1;

        for(i=1;replace>0;i++){

            a[i]=replace%10;

            replace=replace/10;
        }

        check(n,a);
    }

    return 0;
}



