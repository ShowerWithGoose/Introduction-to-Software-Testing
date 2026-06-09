#include<stdio.h>
#include<stdlib.h>
int main()
{    
    int x[205]={0}; // @@ Array size is too small for N up to 1000 (requires at least 2000), causing buffer overflow.
    int y[205]={0}; // @@ Array size is too small for N up to 1000 (requires at least 2000), causing buffer overflow.
    int n;
    int sign=1;
    int k=0;
    int a=0;
    int max=1;
    int len=1;
    int l=0;
    int r=0;
    int lm=0;
    int rm=0;
    scanf("%d",&n);
    for(int i=0;i<2*n;i+=2) // @@ Declaring loop variable inside 'for' may cause compilation error in C89; also iterates over points instead of segments.
    {
        scanf("%d%d%d%d",&x[i],&y[i],&x[i+1],&y[i+1]);
    }
    //输入

    for(int i=0;i<2*n;i+=2) // @@ Declaring loop variable inside 'for' may cause compilation error in C89; loop logic for finding chains is fundamentally flawed.
    {
        for(int j=i+1;j<2*n;j+=2) // @@ Declaring loop variable inside 'for' may cause compilation error in C89; incorrect iteration bounds and logic.
        {
            
            if(x[i]==x[j]&&y[i]==y[j]) // @@ Logical error: compares start points of two segments. Continuous lines must connect end of one to start of another.
            {
                len++;
                l=x[j-1];
                r=y[j-1];
                sign=1;
                k=j-1;
                while(sign==1)
                {
                
                sign=0;
                    for( a=0;a<2*n;a++)
                    {
                    if(k==a)
                    {
                        a++;
                    }
                    if(x[k]==x[a]&&y[k]==y[a])
                    {
                        len++;
                        l=x[a-1];
                        r=y[a-1];
                        k=a-1;
                        sign++;
                        a=0;
                        break;
                    }
                    }
                    a=0;
                }
            }
            

            if(x[i+1]==x[j+1]&&y[i+1]==y[j+1]) // @@ Logical error: compares end points of two segments. Should check if end of one matches start of another.
            {
                len++;
                k=j+2;
                sign=1;
                while(sign==1)
                {
                    sign=0;
                    for(a=0;a<2*n;a++)
                    {
                        if(k==a)
                        {
                            a++;
                        }
                        if(x[k]==x[a]&&y[k]==y[a])
                        {
                            len++;
                            k=a+1;
                            sign++;
                            a=0;
                            break;
                        }
                    }
                    
                }
                
            }
            
        }    
        if(max<len)
        {
            max=len;
            lm=l;
            rm=r;
        }
        len=1;

    }
    printf("%d %d %d\n",max,lm,rm);

    system("pause"); // @@ Non-standard function, causes compilation/runtime errors on non-Windows systems.
    return 0;
}