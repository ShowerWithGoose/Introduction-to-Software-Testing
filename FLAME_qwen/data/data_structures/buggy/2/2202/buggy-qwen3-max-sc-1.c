#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char str[10000];
char ss[10000];
char fu[10000];
char jia[10000];
int a[10000];
int b[10000];
int main()
{
    gets(str); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove `gets` entirely.]
    int t=0,i=strlen(str),j,k=1,p,s,ans=0,anss=0;
    for(j=0;j<i;j++)
    {
    
    if(str[j]!=32)
    ss[t++]=str[j];
}

    t=0,i=0,p=0;
    for(j=0;j<strlen(ss);j++)
    {
        if(ss[j]=='*'||ss[j]=='/'||ss[j]=='=')
        fu[t++]=ss[j];
        else if(ss[j]=='+'||ss[j]=='-')
        fu[t++]=ss[j],jia[i++]=ss[j];
        else if(ss[j]!='=')
        {
            for(j=j+1;ss[j]!='*'&&ss[j]!='/'&&ss[j]!='+'&&ss[j]!='-'&&ss[j]!='=';j++)
            k++; // @@ [This loop increments `j` beyond the current digit group, but then `j--` at end of block may not correctly reset position due to nested loops and off-by-one logic. Also, `k` counts digits but assumes at least one digit follows, which may not hold if expression ends unexpectedly (though problem says valid).]
            for(s=1;s<=k;s++)
            a[p]+=(ss[j-s]-'0')*pow(10,s-1); // @@ [Using `pow` from math.h for integer powers is inefficient and may introduce floating-point inaccuracies; also, `a[p]` is used uninitialized (should be set to 0 before accumulation).]
            p++;
            k=1;
            j--;
        }    
    }
    for(int sb=0;sb<strlen(fu);sb++) // @@ [This loop does nothing; it just declares `sb` and iterates without body. Likely a leftover or typo. Also, C89 doesn't allow variable declaration in for-loop initializer (if compiled in strict C89 mode), which may cause compilation error.]
    
        t=0,i=0,p=0,k=1;
    
    for(j=0;j<strlen(fu);j++)
    {
        if(fu[j]=='+'||fu[j]=='-')
        b[p++]=a[t++];
        else if(fu[j]=='*'||fu[j]=='/')
        {
        
        for(j=j+1;fu[j]!='+'&&fu[j]!='-'&&fu[j]!='=';j++)
        k++; // @@ [Again, `k` is reused without reset to 0 before counting; also, this modifies loop variable `j` of outer loop, causing unpredictable iteration and likely skipping or reprocessing operators/operands.]
    
        ans=a[j-k]; // @@ [`j-k` may be negative or out-of-bounds because `j` was modified in inner loop and `k` may exceed valid index range. Also, `a` indexing assumes contiguous storage matching `fu`, which isn't guaranteed due to prior parsing flaws.]
        for(s=k;s>=1;s--)
        {
        if(fu[j-s]=='*')
        ans=ans*a[j-s+1]; // @@ [Indexing `a[j-s+1]` is likely incorrect; `a` array stores numbers, but its indices don't directly correspond to positions in `fu` operator array. This leads to wrong operand retrieval.]
        else
        ans=ans/a[j-s+1]; // @@ [Same indexing issue as above; also, division by zero not guarded (though problem says valid expression, so maybe safe, but indexing is still wrong).]
        }
        b[p++]=ans;
        t=j+1; // @@ [`t` is used as index into `a`, but `j` here is index in `fu`, so `t=j+1` mismatches the two arrays' indexing schemes.]
        k=1;
    
        }
    }

    
    anss=b[0];
    i=1;
    for(j=0;j<strlen(jia);j++)
    {
        if(jia[j]=='+')
        anss+=b[i++];
        else
        anss-=b[i++];
    }
    printf("%d",anss);

return 0;
}