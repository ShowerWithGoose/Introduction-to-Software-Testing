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
    gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and removed in C11; causes compilation error if compiler enforces C11 or later standards]
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
        printf("%c",b[i]); // @@ [Loop runs to i <= strlen(b), which accesses b[strlen(b)] — an out-of-bounds index since valid indices are 0 to strlen(b)-1; this leads to undefined behavior, but not a compilation error. However, the primary compilation error is due to 'gets']
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