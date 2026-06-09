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
    for(int i=0;i<2*n;i+=2)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&x[i+1],&y[i+1]);
    }
    //输入

    for(int i=0;i<2*n;i+=2)
    {
        for(int j=i+1;j<2*n;j+=2)
        {
            
            if(x[i]==x[j]&&y[i]==y[j])
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
            

            if(x[i+1]==x[j+1]&&y[i+1]==y[j+1])
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
    printf("%d %d %d\n",max,lm,rm); // @@ [The starting point (lm, rm) is incorrectly set only when matching the first endpoint of segment i with the first endpoint of segment j. However, in the test case, the continuous line starts at (12,12), but the code sets l and r only in the first 'if' block which handles connection from tail of j to head of another, but fails to correctly track the true start of the chain. Also, lm and rm are never initialized to a valid starting point when no backward extension occurs, leading to (0,0).]

    system("pause");
    return 0;
}