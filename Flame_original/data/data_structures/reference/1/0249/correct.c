#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverse(int c[],int start,int end){
    int t;
    for ( ; start<end; start++,end--)
    {
        t=c[start];
        c[start]=c[end];
        c[end]=t;
    }
}
int magic(int c[],int n){
    int p=n-2;
    for (; p>=0 && c[p]>c[p+1]; p--);
    if (p==-1)
    {
        return 0;
    }
    
    int j=p++;
    int k;
    for (; p<n; p++)
    {
        if (c[p]>c[j])
        {
            k=p++;
            break;
        }
    }
    for (; p<n; p++)
    {
        if (c[p]>c[j]&&c[p]<c[k])
        {
            k=p;
        }
    }
    p--;
    int t=c[j];
    c[j]=c[k];
    c[k]=t;
    reverse(c,j+1,p);
    for (int i = 0; i < p; i++)
    {
        printf("%d ",c[i]);
    }
    printf("%d\n",c[p]);
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int c[16]={0};
    for (int i = 0; i < n; i++)
    {
        c[i]=i+1;
    }
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ",c[i]);
    }
    printf("%d\n",c[n-1]);
    for (;magic(c,n););
    return 0;
}
