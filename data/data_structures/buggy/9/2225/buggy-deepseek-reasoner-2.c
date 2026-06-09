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
            
            if(x[i]==x[j]&&y[i]==y[j])  // @@ [Only checks specific endpoint match; misses other combinations (e.g., first with first, second with first, etc.). Also, indices may not correspond to valid segment comparisons.]
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
                    if(x[k]==x[a]&&y[k]==y[a])  // @@ [This comparison may cause infinite loop or incorrect chain extension; also does not enforce increasing x-order.]
                    {
                        len++;
                        l=x[a-1];  // @@ [When a=0, a-1 = -1 leads to out-of-bounds access.]
                        r=y[a-1];  // @@ [Same out-of-bounds issue.]
                        k=a-1;     // @@ [Same out-of-bounds issue; also k becomes negative.]
                        sign++;
                        a=0;
                        break;
                    }
                    }
                    a=0;
                }
            }
            

            if(x[i+1]==x[j+1]&&y[i+1]==y[j+1])  // @@ [Only checks specific endpoint match; misses other combinations. Indices may be misinterpreted.]
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
                        if(x[k]==x[a]&&y[k]==y[a])  // @@ [Similar issues as previous; may access out-of-bounds when a = 2*n-1 causing a+1 = 2*n in k=a+1.]
                        {
                            len++;
                            k=a+1;  // @@ [Potential out-of-bounds if a == 2*n-1; k becomes invalid index.]
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
    printf("%d %d %d\n",max,lm,rm);  // @@ [Output format may be incorrect; expected maybe just starting point coordinates, and not necessarily the leftmost point.]

    system("pause");
    return 0;
}