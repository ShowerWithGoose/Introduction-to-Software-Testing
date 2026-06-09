#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char a[105];
    int i,j=0,k=0,n,ans=0,flag=1,op[100]= {0},b[100]= {0},c[100]= {0};
    gets(a);
    op[0]=1;
    for(i=0; i<=strlen(a); i++)
    {
    if(a[i]!=' ')
        {
            if(a[i]=='+')
            {
                op[j]=1;
            }
            else if(a[i]=='-')
            {
                op[j]=2;
            }
            else if(a[i]=='*')
            {
                op[j]=3;
            }
            else if(a[i]=='/')
            {
                op[j]=4;
            }
            else if(a[i]=='='||a[i]=='\0')
            {
                break;
            }
            else if(a[i]>='0'&&a[i]<='9')
            {
                for(n=0;; i++)
                {
                    if(a[i]<'0'||a[i]>'9')
                    {
                        break;
                    }
                    n=n*10+a[i]-'0';
                }
                i--;
                b[j]=n;
                j++;
            }
        }
        else
        {
            continue;
        }
    }
    for(i=0; i<j; i++)
    {
        if(i>=j)break;
        flag=op[i]==1?1:-1;
        for(n=b[i];;i++)
        {
            if(op[i+1]==1||op[i+1]==2||op[i]==0)
            {
                break;
            }
            else
            {
                if(op[i+1]==3)
                {
                    n*=b[i+1];
                }
                else if(op[i+1]==4&&b[i+1]!=0)
                {
                    n/=b[i+1];
                }
            }
        }
        c[k]=flag*n;k++;
    }
    for(i=0;i<=k;i++)
    {
        ans+=c[i];
    }
    printf("%d",ans);
    return 0;
}

