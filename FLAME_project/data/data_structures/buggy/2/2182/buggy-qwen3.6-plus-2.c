#include <stdio.h>
#include <string.h>
char s[10000],c[10000];
int a[10000],b[10000],d[10000];
int main()
{
    gets(s);
    int i1,j1;
    for(i1=j1=0;s[i1]!='\0';i1++)
    if(s[i1]!=' ')
    s[j1++]=s[i1];
    s[j1]='\0';  
    int len=strlen(s);
    int i2,ci=0,ai=0;
    for(i2=0;i2<len;i2++)
    {
        if(s[i2]=='+'||s[i2]=='-'||s[i2]=='*'||s[i2]=='/')
        {
            c[ci]=s[i2];
            ci++;
        }
        if(s[i2]>='0'&&s[i2]<='9')
        {
            int length=0,i3=i2;
            while(s[i3]>='0'&&s[i3]<='9')
            {
                length++;
                i3++;
            }
            i3=i2;
            for(int i=0;i<length;i++)
            b[i]=s[i3++]-'0';
            for(int i=length-1;i>=0;i--)
            for(int j=0;j<i;j++)
            b[length-i-1]*=10;
            for(int i=0;i<length;i++)
            a[ai]+=b[i];
            ai++;
            i2=i3-1;
        }
    }
    if(ci==0)
    printf("%d",a[0]);
    else
    {
        int i4=0;
        if(c[0]=='+'||c[0]=='-')
        {
            d[i4]=a[0];
            i4++;
        }
        for(int i1=0;i1<ci;i1++)
        {
            if((c[i1]=='+'||c[i1]=='-')&&(c[i1+1]=='+'||c[i1+1]=='-'))
            {
                d[i4]=a[i1+1];
                i4++;
            }
            if(c[i1]=='*'||c[i1]=='/') // @@ The logic for handling consecutive * and / operators is flawed. It processes them in a block but incorrectly updates indices and assumes left-to-right associativity within the block without properly chaining the result into the next operation if mixed with other types later, or fails to handle the sequence correctly for multiple divisions/multiplications. Specifically, for `24 / 4 / 3 / 2`, it calculates `24/4=6`, stores in `d`, then tries to process `/ 3` and `/ 2`. The loop `while(c[i2]=='*'||c[i2]=='/')` advances `i2`, but the inner loop `for(int i3=1;i3<length;i3++)` uses `c[i1+i3]` which might go out of bounds or access wrong operators if `i1` is not updated correctly relative to the consumed operators. More critically, after processing a block of * /, `i1` is set to `i2-1`. However, the outer loop increments `i1`. This skip logic is fragile. The main issue causing Runtime Error or Wrong Answer here is likely accessing `c[i1+1]` or `a[i1+1]` out of bounds or incorrect logic for chained divisions. For `24 / 4 / 3 / 2 * 2 * 3 * 4`, the code attempts to process the entire chain. Let's trace: `i1=0` ('/'). `d[0] = 24/4 = 6`. `i2` becomes 1, 2, 3 (all / or *). `length` counts consecutive * /. `i2` stops at index of first non-*// or end. Here all are * /. `i2` goes to `ci`. `length` is large. Inner loop `i3` from 1 to `length-1`. `c[i1+i3]` accesses subsequent operators. `a[i1+i3+1]` accesses subsequent operands. This part actually implements left-to-right for the block. `d[0]` becomes `(((24/4)/3)/2)*2*3*4`. This equals 24. So `d[0]=24`. `i1` becomes `ci-1`. Loop ends. `i4` becomes 1.
            // The error likely stems from the final summation part or initialization of `sum` and `k`.
            int sum=0,j=0,k;
            for(int i=0;i<ci;i++) // @@ If the expression consists entirely of * and /, `ci` operators are processed into `d`. The loop below looks for the first + or -. If none exist, `k` remains uninitialized.
            {
                if(c[i]=='+'||c[i]=='-')
                {
                    k=i;
                    break;
                }
            }
            // If no + or - is found, k is uninitialized. Accessing c[k] below causes Undefined Behavior (Runtime Error).
            if(c[k]=='+') // @@ [Runtime Error] k is uninitialized if there are no '+' or '-' operators in the expression.
            {
                sum=d[0]+d[1];
                j=2;
            }
            if(c[k]=='-') // @@ [Runtime Error] k is uninitialized if there are no '+' or '-' operators in the expression.
            {
                sum=d[0]-d[1];
                j=2;
            }
            for(int i=k+1;i<ci;i++)
            {
                if(c[i]=='+')
                {
                    sum+=d[j];
                    j++;
                }
                if(c[i]=='-')
                {
                    sum-=d[j];
                    j++;
                }
            }
            if(c[ci-1]=='+')
            sum+=a[ai-1];
            if(c[ci-1]=='-')
            sum-=a[ai-1];
            printf("%d",sum);
        }
    }
    return 0;
}