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
    gets(a);
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
    for( int i=1;i<=strlen(b);i++) // @@ The loop condition `i<=strlen(b)` causes it to access `b[strlen(b)]`, which is the null terminator `\0`. This results in printing an extra invisible character or garbage after the significant digits, causing the output `9\0e-1` instead of `9e-1`. It should be `i<strlen(b)`.
    {
        printf("%c",b[i]);
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