#include<stdio.h>
#include<string.h>
int num1_a[100],num2_a[100],num1_n[100],num2_n[100],a[1000],n[1000];
int main()
{
char s[100],t[100];

gets(s),gets(t);
int n1=strlen(s),n2=strlen(t);
int cnt1=0;
int k=0;
for(int i=0;i<n1;i++)
{    
int x=1;
    if(i==n1-1)
    {
        for(int j=i;s[j]!=' ';j--)
        {
        num1_n[cnt1]+=(s[j]-'0')*x;
        x*=10;
        }
        cnt1++;
    }
    else if(s[i]==' ')
    {
     if(cnt1%2==0)
        {
        for(int j=i-1;j>=k;j--)
        {
            num1_a[cnt1]+=(s[j]-'0')*x;
            x*=10;
        }
        k=i+1;
        cnt1++;
        }
        else
        {
            for(int j=i-1;j>=k;j--)
        {
            num1_n[cnt1]+=(s[j]-'0')*x;
            x*=10;
        }
        k=i+1;
        cnt1++;
        }
        
    }
}
int cnt2=0;
k=0;
for(int i=0;i<n2;i++)
{    int x=1;
    if(i==n2-1)
    {
        for(int j=i;t[j]!=' ';j--)
        {
        num2_n[cnt2]+=(t[j]-'0')*x;
        x*=10;
        }
        cnt2++;
    }
    else if(t[i]==' ')
    {

    if(cnt2%2==0)
    {
        for(int j=i-1;j>=k||(i==n2-1);j--) @@ [The condition `j>=k||(i==n2-1)` is logically flawed and may cause out-of-bounds access or infinite loop when `i==n2-1` is true but `j < k`; also, this parsing logic incorrectly assumes alternating coefficient/exponent based on `cnt2%2`, but `cnt2` counts total tokens, not pairs.]
        {
            num2_a[cnt2]+=(t[j]-'0')*x;
            x*=10;
        }
        k=i+1;
        cnt2++;
    }
    else
    {
            for(int j=i-1;j>=k;j--)
        {
            num2_n[cnt2]+=(t[j]-'0')*x;
            x*=10;
        }
        k=i+1;    
        cnt2++;
    }
    }
}
int cnt_a=0,cnt_n=0;
for(int i=0;i<cnt1;i++)
{
if(i%2==0)
{
    for(int j=0;j<cnt2;j+=2)
    {
    a[cnt_a]=num1_a[i]*num2_a[j];    
    cnt_a++;
    }
    
}
else 
{
    for(int j=1;j<cnt2;j+=2)
    {
        n[cnt_n]=num1_n[i]+num2_n[j];
        cnt_n++;
    }
    
}    
} @@ [The multiplication logic is fundamentally broken: it separates coefficients and exponents into different loops, so `a[]` and `n[]` arrays are filled independently and do not correspond to the same term. This leads to mismatched coefficient-exponent pairs.]

for(int i=0;i<cnt_n;i++)
{
    for(int j=i;j<cnt_n;j++)
    {
        if(n[i]<n[j])
        {
            int tmp_n=n[i];
            n[i]=n[j];
            n[j]=tmp_n;
            int tmp_a=a[i];
            a[i]=a[j];
            a[j]=tmp_a;
        }
    }
}
int m=0;
for(int i=0;i<cnt_a;i+=m)
{
    for(int j=i+1;j<cnt_a;j++)
    {
        if(n[j]==n[i])
        {
            a[i]+=a[j];
        }
        else
        {
            m=j-i;
            break;
        }
        
    }
    printf("%d %d ",a[i],n[i]);
} @@ [The output loop uses `m` incorrectly; `m` is only set in the `else` branch, so if all remaining terms have the same exponent, `m` remains 0, causing an infinite loop (`i += 0`). Also, due to earlier mismatched `a[]` and `n[]`, the output is meaningless.]

    return 0;
}