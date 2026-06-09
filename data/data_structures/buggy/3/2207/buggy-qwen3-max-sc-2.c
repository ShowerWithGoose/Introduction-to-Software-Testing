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
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors.]
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
    for( int i=1;i<=strlen(b);i++)
    {
        printf("%c",b[i]); // @@ [This loop runs from i=1 to i<=strlen(b), which accesses b[strlen(b)] — an out-of-bounds index since valid indices are 0 to strlen(b)-1. This causes undefined behavior, but more critically, if b is empty (e.g., input "0.0"), b[0] access above is also invalid. However, the immediate compilation error is due to 'gets'.]
    }
    printf("e");
    if(k!=0)
    {
            if(n==0)
    printf("%d",k-1);
    else
    printf("%d",1-n);
    }    
    else
    printf("%d",strlen(b)-1) ;
return 0;
}