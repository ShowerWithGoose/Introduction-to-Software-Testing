#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void sorting(int num[],int head,int len)
{
    int I,J,TEMP,FLAG;
    for(I=head;I<=head+len-1;I++){
        FLAG=1;
        for(J=head;J<=head+len-2;J++){
            if(num[J]>num[J+1]){
                TEMP=num[J];
                num[J]=num[J+1];
                num[J+1]=TEMP;
                FLAG=0;}
        }
        if(FLAG) break;
}
    }

void swap(int num[],int a,int b)
{
    int temp;
    temp=num[a];
    num[a]=num[b];
    num[b]=temp;
}

void All(int num[],int n,int start)
{
    int i,k;
    sorting(num,start,n-start);
    if(start!=n-1)
    {
        for(i=start;i<=n-1;i++)
        {
            swap(num,start,i);
            All(num,n,start+1);
            sorting(num,start,n-start);
        }
    }
    else
    {
        for(k=0;k<=n-2;k++)
            printf("%d ",num[k]);
        printf("%d\n",num[k]);
    }

}

int num[10];
int main()
{
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
        num[i]=i+1;
    All(num,n,0);
    return 0;
}



