#include<stdio.h>
int main()
{
int a[100],b[100]={0};
int i=0,j=0,k=0;
for(i=0;i<100;i++)
{
    scanf("%d",&a[i]);
    if(a[i]==-1){
            a[i+1]='\0';
        break;
    }
}
k=i;
for(i=0;i<k;i++)
 {
    if(a[i]==1)
    {
        b[j]=a[i+1];
        j++;
    }
    if(a[i]==0)
    {
        if(j<1)
        printf("error ");

    else
        {
            printf("%d ",b[j-1]);
            j--;
        }
    }
 }
 return 0;
}

