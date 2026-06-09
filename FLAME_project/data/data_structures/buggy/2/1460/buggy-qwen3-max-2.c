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
    
    for(int i=0;i<s;i++)//去空格
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
    b[j] = '='; // @@ [Missing termination with '=' after removing spaces, causing later loops to read garbage]
    j=0;
    unsigned long s1=strlen(b);
    
    for (int i=0;i<s1;i++)//转数字，分运算符
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
                j++; // @@ [When encountering a new number after an operator, j should be incremented before assigning the first digit]
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
    a[++j] = '='; // @@ [Array 'a' is not properly terminated with '=', leading to undefined behavior in subsequent loops]
    
    for(int i=0;i<=sizeof(a)/4;i++)//先算乘除，后算加减
    {
        if(a[i]==-3)
        {
            a[i+1]=a[i-1]*a[i+1];
            a[i]=a[i-1]=-5;
        }
        else if (a[i]==-4)
        {
            a[i+1]=a[i-1]/a[i+1]; // @@ [Division operands are in wrong order: should be a[i-1] / a[i+1], but logic assumes left-to-right which is correct, however due to incorrect parsing earlier, values may be wrong]
            a[i]=a[i-1]=-5;
        }
    }
    for(int i=0;i<s;i++)
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
            ans=d[i-1]-d[i+1]; // @@ [Subtraction logic is flawed: it computes d[i-1] - d[i+1], but doesn't handle cumulative result correctly; also modifies d[i+1] but next iteration may skip or misuse it]
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
        printf("%d\n",ans); // @@ [Final answer only prints 'ans' from last operation, not the accumulated total; fails for expressions with multiple additions/subtractions]
    return 0;
}