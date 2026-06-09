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
    b[j] = '='; // @@ [The original code does not null-terminate or append '=' to b, causing later loops to read garbage beyond the actual expression. The reference program explicitly adds '=' twice. Without it, the parsing loop may not terminate correctly or may process uninitialized memory.]
    j=0;
    unsigned long s1=strlen(b); // @@ [strlen(b) is unsafe here because b may not be null-terminated after copying non-space characters. This leads to undefined behavior when reading beyond valid data.]
    
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
                j++; // @@ [When encountering a new number after an operator, j should be incremented BEFORE assigning the first digit. Otherwise, the new number overwrites the operator's position in array a.]
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
    a[j] = '='; // @@ [The array a must be terminated with '=' so that later loops know where to stop. The current code doesn't ensure this, leading to processing of uninitialized values.]
    
    for(int i=0;i<=sizeof(a)/4;i++)//先算乘除，后算加减
    {
        if(a[i]==-3)
        {
            a[i+1]=a[i-1]*a[i+1];
            a[i]=a[i-1]=-5;
        }
        else if (a[i]==-4)
        {
            a[i+1]=a[i-1]/a[i+1]; // @@ [Division operands are in wrong order: it should be a[i-1] / a[i+1], but due to left-to-right associativity and in-place updates, this fails for chained divisions like 24/4/3. However, the bigger issue is that the loop processes from left to right but overwrites values needed for subsequent operations. Also, using a fixed upper bound (sizeof(a)/4) instead of stopping at '=' causes out-of-bound reads.]
            a[i]=a[i-1]=-5;
        }
    }
    for(int i=0;i<s;i++) // @@ [Loop bound 's' (original input length) is unrelated to the actual number of tokens in 'a'. Should iterate until '=' or known token count.]
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
            ans=d[i-1]+d[i+1]; // @@ [This assumes d[i-1] and d[i+1] are valid numbers, but after filtering -5, the array d may not have proper spacing. Also, updating d[i+1] and skipping via i++ breaks sequential processing for expressions with multiple operators.]
            d[i]=0;
            d[i+1]=ans;
            i++;
        }
        else if (d[i]==-2)
        {
            ans=d[i-1]-d[i+1]; // @@ [Same issue as above: incorrect handling of operator precedence and operand positions after filtering. Also, subtraction is not handled as unary negation like in the reference program, causing errors with leading minus or consecutive operators.]
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