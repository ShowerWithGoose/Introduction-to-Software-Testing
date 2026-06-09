#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
char a[105];
char b[105]; 
int main()
{   int k=0,j=0,n=0;
    int flag=0;
    gets(a); // @@ gets() is deprecated and removed in C11, causing compilation errors in modern compilers; use fgets() instead.
    for(int i=0;i<strlen(a);i++)
    {   
        if(a[i]=='.')
        {
            k=i;
        }
        if(a[i]!='0'&&a[i]!='.')
        {
            flag=1;
            b[j]=a[i];
            j++;            
        }
    else if(a[i]=='0'&&flag==1)
        {            
            b[j]=a[i];
            j++;            
        }    
        if(flag==0)
         {
             n++;
         }        
    }
    printf("%c",b[0]);
    if(strlen(b)>1)
    printf("."); 
    for( int i=1;i<=strlen(b);i++) // @@ Off-by-one error: i<=strlen(b) accesses b out of bounds; should be i<strlen(b). Also, b lacks null-termination, making strlen(b) unreliable.
    {
        printf("%c",b[i]);
    }
    printf("e");
    if(k!=0)
    {
            if(n==0)
    printf("%d",k-1); // @@ Flawed exponent logic: k-1 only works when n==0, but the overall approach incorrectly calculates the decimal shift for scientific notation.
    else
    printf("%d",1-n); // @@ Incorrect formula for negative exponents: 1-n does not correctly compute the exponent for numbers less than 1.
    }    
    else
    printf("%d",strlen(b)-1) ; // @@ Incorrect exponent calculation for k==0 case; also relies on un-terminated string b.
return 0;
}