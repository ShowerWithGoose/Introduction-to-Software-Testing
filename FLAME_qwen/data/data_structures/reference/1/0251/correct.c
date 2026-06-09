#include<stdio.h>
int N;
int i,j;
int a[11],b[10];

int f()
{
   a[0]=1;
    int i;
    for(i=1;i<10;i++)
	{
        a[i]=i*a[i-1];
    }
}

void h()
{
    for(i=N-2;i>=0;i--){
        if(b[i+1]>b[i])
            break;
    }
    int k1=i;
    int temp1=i+1;
    for(i=k1+1;i<N;i++){
        if(b[i]>b[k1]&&b[i]<b[temp1])
            temp1=i;
    }
    int temp2;
    temp2=b[k1];
    b[k1]=b[temp1];
    b[temp1]=temp2;
    for(j=k1+1,i=N-1;i>j;i--,j++){
        temp2=b[i];
        b[i]=b[j];
        b[j]=temp2;
    }
}

void g()
{
    int i=0;
    for(i=0;i<N-1;i++)
        printf("%d ",b[i]);
    printf("%d\n",b[i]);
}


int main(){
    f();
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++){
        b[i]=i+1;
    }
    g();
    for(i=1;i<a[N];i++){
        h();
        g();
    }
}



