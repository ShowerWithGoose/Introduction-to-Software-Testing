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
    for( int i=1;i<=strlen(b);i++) @@ [Loop condition should be i<strlen(b) to avoid printing the null terminator b[strlen(b)], which causes an extra character in output.]
    {
        printf("%c",b[i]);
    }
    printf("e");
    if(k!=0)
    {
            if(n==0)
    printf("%d",k-1);
    else
    printf("%d",1-n); @@ [Exponent calculation is incorrect for numbers with leading zeros. Should be -n instead of 1-n. For example, input "0.9" gives n=1, exponent should be -1, but this prints 0.]
    }    
    else
    printf("%d",strlen(b)-1) ;
return 0;
}