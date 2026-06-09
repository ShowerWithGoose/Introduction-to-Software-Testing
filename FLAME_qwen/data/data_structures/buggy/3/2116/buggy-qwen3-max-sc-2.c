#include<stdio.h>
#include<string.h>
char c[90]={0},ans[90]={'l'}; // @@ [Initialization with 'l' is incorrect and unnecessary; should be {0} or omitted. Also, using gets() is unsafe and may cause buffer overflow, but the immediate error is likely due to missing handling of input termination and logic flaws.]
int t,tt,ttt;
int main()
{
    gets(c); // @@ [Use of gets() is dangerous and deprecated; it can cause buffer overflow. More critically, in many modern environments, gets() is not available, which may lead to compilation errors. This is likely the source of the "gcc: not found" misinterpretation—actually a linking/compilation failure due to gets().]
    if(c[0]!='-')
    {
        for(int i=0;c[i]!=0;i++) 
        {
            if(c[i]==0) t=i-1;//数一共t位 // @@ [This condition c[i]==0 will only be true at the null terminator, but the loop condition is c[i]!=0, so this block never executes. Thus, t remains uninitialized, leading to undefined behavior later if used. However, t is unused elsewhere, so this may not directly cause output error but indicates flawed logic.]
            if(c[i]=='.') tt=i;//小数点前有tt位
            if(c[i]!='.') ans[ttt++]=c[i];
        }
        if(c[0]=='0')
        {
            int st;
            for(int i=1;i<ttt;i++)
            {
                if(ans[i]!='0')
                {
                    st=i;
                    printf("%c.",ans[i]);
                    for(int j=i+1;j<ttt;j++)
                    {
                        printf("%c",ans[j]);
                    }
                    break;
                }
            }
            printf("e-%d",st); // @@ [If the input is "0.0", the loop never finds a non-zero digit, so st is uninitialized, leading to undefined behavior. But per problem statement, all digits are significant and no trailing zeros, so maybe not triggered. However, if input is "0.1", st=1, exponent should be -1, but here it prints e-1 which is correct. But note: the number of leading zeros after decimal determines exponent. For "0.001", st=2 (since ans = "0001"? Wait, ans construction is flawed.)]
        }else if(tt==1&&c[0]!='0') // @@ [tt is set only if '.' is found. If input has no decimal point (e.g., "5"), then tt remains uninitialized (0), so tt==1 fails. Thus, "5" would go to else branch and print "5.e0" but expected "5e0". Also, per problem, input always has digits before and after decimal point, so maybe no integer-only inputs. But problem says: "has digits before and after the decimal point", so tt should always be set. However, if input is "5.0", but problem says no trailing zeros, so "5.0" invalid. So perhaps tt is always set. Still, logic assumes decimal exists.]
        {
            printf("%se0",c);
        }
        else{
            printf("%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]);
            printf("e%d",tt-1);
        }
    }else{
        for(int i=0;c[i]!=0;i++)
        {
            if(c[i]!='-'&&c[i]!='.') ans[ttt++]=c[i];
            if(c[i]==0) t=i-2;//数一共t位 // @@ [Same issue: c[i]==0 never true inside loop due to loop condition.]
            if(c[i]=='.') tt=i-1;//小数点前有tt位
        }
        if(c[1]=='0')
        {
            int st;
            for(int i=1;i<ttt;i++)
            {
                if(ans[i]!='0')
                {
                    st=i;
                    printf("-%c.",ans[i]);
                    for(int j=i+1;j<ttt;j++)
                    {
                        printf("%c",ans[j]);
                    }
                    break;
                }
            }
            printf("e-%d",st); // @@ [Same uninitialized st risk if no non-zero found, though problem states significant digits so maybe safe. But exponent calculation may be off.]
        }else if(tt==1&&c[1]!='0') // @@ [Again, tt relies on '.' being present. If input is "-5.3", tt = index of '.' minus 1 = (1) -1 = 0? Wait: c = "-5.3", i=2 is '.', so tt = 2-1 =1. Then tt==1, so prints "-5.3e0", but expected "-5.3e0"? Actually, for "-5.3", scientific notation is "-5.3e0", which matches. But if input is "-12.3", tt = index of '.' (2) -1 =1, so tt==1 false, goes to else: prints "-1.23e1", which is correct. So this branch is for single-digit before decimal, like "-5.3". But what if input is "-5."? Problem says digits after decimal, so not possible. So maybe okay.]
        {
            printf("%se0",c);
        }
        else{
            printf("-%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]);
            printf("e%d",tt-1);
        }
    }
    
    
    return 0;
}