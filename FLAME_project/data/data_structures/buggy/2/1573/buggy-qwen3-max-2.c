#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc, char** argv)
{
    char c[5000];
    char ne[5000];
    char fu[5000];
    int a[5000];
    char m;
    int len,n,x,xx,wei,ans=0,chengshu=1;
    x=0;
    xx=0;
    gets(c);
    n=strlen(c);
    printf("%s\n",c); // @@ [Unnecessary output; problem requires only the result to be printed, but this prints the input expression which causes wrong output format and may interfere with judging]
    for(int i=0;i<n;i++)
    {
        if(c[i]==' '||c[i]=='=')
        {
            continue;
        }
        else
        {
            ne[x++]=c[i];
        }
    }
    x=0;
    for(int i=0;i<n;i++) // @@ [Loop bound should be based on length of `ne`, not original `n`; also logic for parsing numbers is flawed]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Incorrect number parsing: accumulates digit without considering place value correctly; e.g., for "12", it does 0+1=1 then 1*10 + 2 = 12, but here it adds first then multiplies later conditionally, leading to wrong values]
        }
        if(isdigit(ne[i+1]))
        {
            a[x]*=10; // @@ [This shifts already added digit left, causing overcounting; e.g., '1' becomes 1, then *10=10, then next digit '2' makes it 10+2=12, but then if another digit follows, it breaks. Also accesses ne[i+1] beyond bounds when i = last index]
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [Accesses ne[i+1] which may be out of bounds (e.g., at end of string), leading to undefined behavior or garbage in `fu`]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop goes to strlen(fu) inclusive, which accesses fu[len] = '\0', causing invalid operator checks and logic errors]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [Accesses fu[i-1] when i=0 leads to fu[-1], undefined behavior]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again accesses fu[i-1] when i=0 → undefined; also logic doesn't properly handle sign propagation for terms like "-2*3"]
            {
            chengshu*=a[i]; // @@ [Uses a[i] which may not correspond to correct operand index due to earlier parsing errors]
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [Integer division is required, but more critically, indexing into a[] is misaligned due to incorrect parsing and operator/operand association]
            }
            else
            {
                chengshu*=a[i+1]; // @@ [Same indexing issue: a[i+1] may be uninitialized or wrong]
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [fu[i-1] when i=0 → undefined; also logic for accumulating `chengshu` into `ans` is misplaced and incomplete]
        {
            ans+=chengshu;
            chengshu=1;
        }
        
    }
    if(fu[0]!='*'&&fu[0]!='/')
    {
        ans+=a[0]; // @@ [May double-count a[0] if also handled in later loop; also assumes a[0] is always positive term]

    }
    {
        for(int i=0;i<=len;i++) // @@ [Loop goes to len inclusive, accessing fu[len] which is '\0', and a[i+1] may be out of bounds]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1]; // @@ [Indexing mismatch: a[i+1] may not be the correct operand due to earlier parsing flaws]
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Typo: single '&' instead of '&&'; causes bitwise AND instead of logical AND, leading to incorrect condition evaluation]
            {
                ans-=a[i+1]; // @@ [Same indexing issue; also sign handling is inconsistent with multiplication/division terms]
            }

        }
    }
    printf("%d",ans);
    return 0;
}