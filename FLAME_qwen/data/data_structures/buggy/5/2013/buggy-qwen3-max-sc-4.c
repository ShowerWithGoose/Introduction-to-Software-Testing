#include<stdio.h>
#include<string.h>
int num1_a[100],num2_a[100],num1_n[100],num2_n[100],a[1000],n[1000];
int main()
{
char s[100],t[100];

gets(s),gets(t); // @@ [The `gets` function is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors.]

int n1=strlen(s),n2=strlen(t);
int cnt1=0;
int k=0;
for(int i=0;i<n1;i++)
{    
int x=1;
    if(i==n1-1)
    {
        for(int j=i;s[j]!=' ';j--) // @@ [This loop condition may cause out-of-bounds access if there's no space before the last character; also, logic for parsing numbers from right to left is flawed and doesn't handle multi-digit numbers correctly.]
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
        for(int j=i;t[j]!=' ';j--) // @@ [Same issue as above: potential out-of-bounds read and incorrect number parsing logic.]
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
        for(int j=i-1;j>=k||(i==n2-1);j--) // @@ [The condition `j>=k||(i==n2-1)` is logically incorrect and can cause infinite loops or out-of-bounds access.]
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
}
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
}
    return 0;
}