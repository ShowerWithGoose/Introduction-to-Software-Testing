#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 110  
int arr[M]={0};
int brr[M]={0};
void qcpailie(int a[],int b[],int n,int d);


int main(){
    int N;
    scanf("%d",&N);
    int d=1;
    qcpailie(arr,brr,N,d);
    return 0;
}


void qcpailie(int a[],int b[],int n,int d){
if (d==n+1)
{
     for (int i = 1; i < n+1; i++)
     {
     printf("%d ",a[i]);
     }
     printf("\n");
}
for (int i = 1; i < n+1; i++)
{
  if (b[i]==0)
  {
    b[i]++;
    a[d]=i;
    qcpailie(a,b,n,d+1);
    b[i]=0;
  }
  
}

}

