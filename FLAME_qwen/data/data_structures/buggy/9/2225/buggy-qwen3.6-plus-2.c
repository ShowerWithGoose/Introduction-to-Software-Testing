#include<stdio.h>
#include<stdlib.h>
int main()
{    
    int x[205]={0};
    int y[205]={0};
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
    for(int i=0;i<2*n;i+=2) // @@ C89 standard does not allow variable declaration inside for-loop initialization; declare 'i' before the loop for compatibility
    {
        scanf("%d%d%d%d",&x[i],&y[i],&x[i+1],&y[i+1]);
    }
    //输入

    for(int i=0;i<2*n;i+=2) // @@ C89 compatibility issue; also redeclaration of 'i' if not C99
    {
        for(int j=i+1;j<2*n;j+=2) // @@ C89 compatibility issue; declare 'j' before the loop
        {
            
            if(x[i]==x[j]&&y[i]==y[j]) // @@ Logical error: continuous segments connect end of one to start of another, not start-to-start
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
                        a++; // @@ Logical error: incrementing 'a' here causes skipping the next index since the for-loop also increments 'a'
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
            

            if(x[i+1]==x[j+1]&&y[i+1]==y[j+1]) // @@ Logical error: should check if segment i's end matches segment j's start (x[i+1]==x[j] && y[i+1]==y[j])
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
                            a++; // @@ Logical error: same skipping issue as above
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

    system("pause"); // @@ system("pause") is Windows-specific and will cause runtime failure on Linux/Unix; remove for portability

    return 0;
}