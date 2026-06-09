#include<stdio.h>

#include<string.h>

void sort(int a[],int b[],int m2);

void sort(int a[],int b[],int m2){

    int i,t;

    int hold1,hold2;

    for(i=1;i<=m2-1;i++){

        for(t=1;t<=m2-i;t++){

            if(b[t]<b[t+1]){

                hold1=a[t],hold2=b[t];

                a[t]=a[t+1],b[t]=b[t+1];

                a[t+1]=hold1,b[t+1]=hold2;
            }
        }
    }
}

int main(){

    int a[5000],b[5000],c[5000],d[5000],e[5000],f[5000];

    int m1,m2,i,t,key=1;

    for(m1=1;;m1++){

        scanf("%d %d",&a[m1],&b[m1]);

        if(getchar()=='\n') break;
    }

    for(m2=1;;m2++){

        scanf("%d %d",&c[m2],&d[m2]);

        if(getchar()=='\n') break;
    }

    for(i=1;i<=m1;i++){

        for(t=1;t<=m2;t++){

            e[key]=a[i]*c[t];

            f[key]=b[i]+d[t];

            key++;
        }
    }

    sort(e,f,m1*m2);

    for(i=1;i<=m1*m2;i++){

        if(i<m1*m2&&f[i]==f[i+1]){

            int sum=e[i];

            for(t=i;t<m1*m2&&f[t]==f[t+1];t++){

                sum=sum+e[t+1];
            }

            printf("%d %d ",sum,f[i]);

            i=t;

            continue;
        }

        printf("%d %d ",e[i],f[i]);
    }

    return 0;
}

