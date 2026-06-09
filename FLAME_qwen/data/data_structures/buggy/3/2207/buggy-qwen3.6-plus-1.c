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
    gets(a); // @@ [gets is removed in C11 standard, causing compilation error; should use fgets]
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
    if(strlen(b)>1) // @@ [b is not null-terminated, calling strlen(b) results in undefined behavior]
    printf("."); 
    for( int i=1;i<=strlen(b);i++) // @@ [b is not null-terminated causing undefined behavior with strlen, and <= leads to out-of-bounds access]
    {
        printf("%c",b[i]);
    }
    printf("e");
    if(k!=0)
    {
            if(n==0)
    printf("%d",k-1);
    else
    printf("%d",1-n); // @@ [Incorrect exponent calculation for numbers less than 1; should be -n]
    }    
    else
    printf("%d",strlen(b)-1) ; // @@ [b is not null-terminated, calling strlen(b) results in undefined behavior]
return 0;
}