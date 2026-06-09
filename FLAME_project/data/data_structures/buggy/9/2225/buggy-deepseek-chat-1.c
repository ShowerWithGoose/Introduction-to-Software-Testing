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
                l=x[j-1]; // @@ Error: When connecting forward, the starting point should be the first endpoint of the current segment (x[i], y[i]), not x[j-1]. This incorrectly sets the starting point.
                r=y[j-1]; // @@ Error: Same issue as above; the starting point coordinates are wrong.
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
                        l=x[a-1]; // @@ Error: When extending forward, the starting point should be updated to the first endpoint of the newly connected segment (x[a-1], y[a-1]), but this logic is flawed because it doesn't correctly track the leftmost endpoint.
                        r=y[a-1]; // @@ Error: Same issue as above.
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
            lm=l; // @@ Error: lm is set to l, but l is only updated in the forward connection case; for backward connections, l remains 0, causing the starting point to be wrong.
            rm=r; // @@ Error: Same issue as above.
        }
        len=1;

    }
    printf("%d %d %d\n",max,lm,rm);

    system("pause");
    return 0;
}