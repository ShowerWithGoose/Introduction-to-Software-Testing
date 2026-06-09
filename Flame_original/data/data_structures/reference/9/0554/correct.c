#include<stdio.h>

int x1[200],y1[200],x2[200],y2[200];

int lth[200];

int work(int x1[],int y1[],int x2[],int y2[],int i,int n);

int work(int x1[],int y1[],int x2[],int y2[],int i,int n){

    int j,result=1;

    for(j=1;j<=n;j++){

        if(x2[i]!=x1[j]||y2[i]!=y1[j]) continue;

        result=result+work(x1,y1,x2,y2,j,n);
    }

    return result;
}

int main(){

    int n,i,j;

    int max=-1,key;

    scanf("%d",&n);

    for(i=1;i<=n;i++){

        scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }

    for(i=1;i<=n;i++){

        lth[i]=work(x1,y1,x2,y2,i,n);
    }

    for(i=1;i<=n;i++){

        if(lth[i]>max){

            max=lth[i];

            key=i;
        }
    }

    printf("%d %d %d",max,x1[key],y1[key]);

    return 0;
}

