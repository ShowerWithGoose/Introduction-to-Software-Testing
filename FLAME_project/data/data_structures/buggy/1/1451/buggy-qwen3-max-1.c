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
        printf("%d",a[p]); // @@ [The output lacks spaces between numbers. According to the problem, integers in each line must be separated by a space. Also, array indexing starts at 1 here, but printing should format with spaces.]
        
        
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
boollo(a,b,n,1); // @@ [The function starts filling permutation from index 1 (len=1), but the output loop also starts from index 1. However, the bigger issue is missing spaces in output. Also, lexicographical order is maintained due to loop from 1 to n, so that part is correct. The core error is formatting: no spaces between numbers.]


    return 0;

}