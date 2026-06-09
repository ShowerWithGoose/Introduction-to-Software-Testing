#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int a[12],b[12];


void boollo(int a[],int b[],int n,int len)
{
    if(len==n+1){
        
        int p=1;
        for(;p<=n;p++)
        printf("%d",a[p]); // @@ Missing space separator between numbers, should be "%d " to match the required output format where integers are separated by a space.
        
        
        printf("\n");
        return;
        
    }
    else{int j=1;
    for(;j<=n;j++){

    if(b[j]==0)
    {
        b[j]=1;
        a[len]=j;
        
        boollo(a,b,n,len+1);
        b[j]=0;
        
    }
    
    }    
    
    
}

}

int main(){

int n;
scanf("%d",&n);
boollo(a,b,n,1);


    return 0;

}