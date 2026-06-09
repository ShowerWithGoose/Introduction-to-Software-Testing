#include<stdio.h>

#include<string.h>

void sort(int a[],int b[],int n);

void sort(int a[],int b[],int n){

    int i,j;

    int hold1,hold2;

    for(i=1;i<=n-1;i++){

        for(j=1;j<=n-i;j++){

            if(b[j]<b[j+1]){

                hold1=a[j],hold2=b[j];

                a[j]=a[j+1],b[j]=b[j+1];

                a[j+1]=hold1,b[j+1]=hold2;
            }
        }
    }
}

int main(){

    int a[5000],b[5000],c[5000],d[5000],e[5000],f[5000];

    int m,n,i,j,key=1;

    for(m=1;;m++){

        scanf("%d %d",&a[m],&b[m]);

        if(getchar()=='\n') break;
    }

    for(n=1;;n++){

        scanf("%d %d",&c[n],&d[n]);

        if(getchar()=='\n') break;
    }

    for(i=1;i<=m;i++){

        for(j=1;j<=n;j++){

            e[key]=a[i]*c[j];

            f[key]=b[i]+d[j];

            key++;
        }
    }

    sort(e,f,m*n);

    for(i=1;i<=m*n;i++){

        if(i<m*n&&f[i]==f[i+1]){

            int sum=e[i];

            for(j=i;j<m*n&&f[j]==f[j+1];j++){

                sum=sum+e[j+1];
            }

            printf("%d %d ",sum,f[i]);

            i=j;

            continue;
        }

        printf("%d %d ",e[i],f[i]);
    }

    return 0;
}

