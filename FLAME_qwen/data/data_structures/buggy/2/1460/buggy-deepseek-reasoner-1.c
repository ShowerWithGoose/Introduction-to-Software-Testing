#include <stdio.h>
#include<string.h>
int main(int argc, const char * argv[]) {
    char c [10000];
    char b [10000];
    int a [10000];
    int d [10000];
    int j=0;
    int cnt=0;
    int k=0;
    int ans=0;
    gets(c);
    unsigned long s=strlen(c);
    
    for(int i=0;i<s;i++)
    {
        if(c[i]==' ')
        {
        }
        else
        {
            b[j]=c[i];
            j++;
        }
    }
    j=0;
    unsigned long s1=strlen(b); // @@ [b is not null-terminated after removing spaces; strlen(b) results in undefined behavior]
    
    for (int i=0;i<s1;i++)
    {
         if(b[i]>=48&&b[i]<=57)
        {
            if(i==0)
            {
                a[j]=b[i]-'0';
            }
            else if(b[i-1]>=48&&b[i-1]<=57)
            {
                a[j]=a[j]*10+b[i]-'0';
            }
            else
            {
                a[j]=b[i]-'0';
            }
        }
        else
        {
            if(i==0)
            {
                
            }
            else
            {
                j++;
            }
            if(b[i]=='+')
            {
                a[j]=-1;
                j++;
            }
            else if(b[i]=='-')
            {
                a[j]=-2;
                j++;
            }
            else if(b[i]=='*')
            {
                a[j]=-3;
                j++;
            }
            else if(b[i]=='/')
            {
                a[j]=-4;
                j++;
            }
            else
            {
                break;
            }
        }
    }
    
    for(int i=0;i<=sizeof(a)/4;i++) // @@ [Loop bound i<=10000 leads to access a[10000] which is out-of-bounds; also a[i+1] when i=9999 is out-of-bounds]
    {
        if(a[i]==-3)
        {
            a[i+1]=a[i-1]*a[i+1]; // @@ [When i=0, a[i-1] accesses a[-1] (invalid); also out-of-bounds for a[i+1] at i=9999]
            a[i]=a[i-1]=-5; // @@ [Same issue with a[i-1] when i=0]
        }
        else if (a[i]==-4)
        {
            a[i+1]=a[i-1]/a[i+1]; // @@ [Same out-of-bounds issues as above]
            a[i]=a[i-1]=-5; // @@ [Same as above]
        }
    }
    for(int i=0;i<s;i++) // @@ [Uses 's' (length of original input) as loop bound, but the meaningful data in a is only up to index j-1; this copies garbage values]
    {
        if(a[i]==-5)
        {
        }
        else
        {
            d[k]=a[i];
            k++;
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        if(d[i]==-1)
        {
            ans=d[i-1]+d[i+1];
            d[i]=0;
            d[i+1]=ans;
            i++;
        }
        else if (d[i]==-2)
        {
            ans=d[i-1]-d[i+1];
            d[i]=0;
            d[i+1]=ans;
            i++;
        }
    }
    if(cnt==1)
    {
        printf("%d\n",d[0]);
    }
    else
        printf("%d\n",ans);
    return 0;
}