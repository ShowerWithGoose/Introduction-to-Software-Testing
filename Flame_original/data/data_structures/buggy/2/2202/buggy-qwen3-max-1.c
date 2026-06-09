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
    gets(str); // @@ [Using `gets` is unsafe and deprecated; however, the immediate error is likely due to missing initialization of array `a` leading to undefined behavior. But more critically, in the number parsing loop below, `a[p]` is used without being initialized to 0 before accumulation.]
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
            k++;
            for(s=1;s<=k;s++)
            a[p]+=(ss[j-s]-'0')*pow(10,s-1); // @@ [Variable `a[p]` is not initialized to 0 before this accumulation, leading to garbage values. Also, using `pow` for integer powers is inefficient and may introduce floating-point inaccuracies.]
            p++;
            k=1;
            j--;
        }    
    }
    for(int sb=0;sb<strlen(fu);sb++) // @@ [This loop does nothing; it's a no-op that likely indicates misplaced logic. The following lines are not inside this loop, so variables `t`, `i`, etc., are reset unconditionally after the loop.]
    
        t=0,i=0,p=0,k=1; // @@ [This line is not inside any loop due to missing braces above; it executes once after the empty loop, but the logic that follows assumes a different state. This breaks the intended algorithm flow.]
    
    for(j=0;j<strlen(fu);j++)
    {
        if(fu[j]=='+'||fu[j]=='-')
        b[p++]=a[t++];
        else if(fu[j]=='*'||fu[j]=='/')
        {
        
        for(j=j+1;fu[j]!='+'&&fu[j]!='-'&&fu[j]!='=';j++)
        k++; // @@ [This modifies loop variable `j` inside the loop, which can cause skipping of operators or operands. Also, `k` counts operators, but then `a[j-k]` is used as an index which may be out of bounds or incorrect.]
    
        ans=a[j-k]; // @@ [`j` has been modified in the inner loop; `j-k` may not point to a valid operand index. Also, `a` indexing assumes a flat array of numbers, but the parsing earlier may not have filled `a` correctly.]
        for(s=k;s>=1;s--)
        {
        if(fu[j-s]=='*')
        ans=ans*a[j-s+1]; // @@ [Index `j-s+1` into `a` is likely incorrect because `a` stores only numbers, while `fu` stores operators. There's a mismatch between operator positions and operand indices.]
        else
        ans=ans/a[j-s+1]; // @@ [Same indexing issue as above; also, integer division is required, but if `ans` became negative due to earlier errors, truncation behavior might differ, though C99 specifies truncation toward 0. However, the main issue is wrong indices.]
        }
        b[p++]=ans;
        t=j+1; // @@ [`t` is set to `j+1`, but `j` is an index in `fu` (operator array), not in `a` (number array). This will cause misalignment when reading next operands from `a`.]
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