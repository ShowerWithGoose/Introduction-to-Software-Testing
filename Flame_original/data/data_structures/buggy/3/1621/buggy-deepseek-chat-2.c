#include<stdio.h>
#include<string.h>
int main()
{
    char c[105];
    int k=2;
    gets(c); // @@ gets() is unsafe and may cause buffer overflow; also, it's deprecated in C11 and removed in C17, but the main issue is that it reads the newline and may not handle input correctly
    int len= strlen(c);
    if(c[0]=='0' && len!=3)
    {
        for( ; k<len; k++)
        {
            if(c[k]!='0')
            break;
        }
        printf("%c.", c[k]); // @@ When k reaches len (no non-zero digit found), c[k] accesses out-of-bounds memory, causing undefined behavior
        for(int m=k+1; m<=len; m++) // @@ Loop condition m<=len accesses c[len] which is out-of-bounds (valid indices are 0 to len-1)
        {
            printf("%c", c[m]);
        }
        printf("e-%d", k-1);
    }
    else if(c[0]=='0' && len==3)
    {
        printf("%c", c[2]);
        printf("e-1");
    }
    else
    {
        int q=1;
        int te=1;
        for(; q<len; q++)
        {
            if(c[q]=='.')//814.3,q=3
            {
                te=0;
                break;
            }
            if(c[q]!='0')
            {
                te=0;
            }
        }
        if(te==1)
        {
            printf("%ce%d", c[0], q-1); // @@ When te==1, the number has no decimal point and all digits after first are zero, but q may equal len (if no '.' found), then q-1 is correct; however, the output format may be wrong for cases like "100" (should be "1e2" but this prints "1e2" correctly, but fails for "0.001" type cases handled earlier)
        }else{
            printf("%c.", c[0]);
            for(int m=1; m<len; m++)
            {
                if(c[m]!='.')
                printf("%c", c[m]);
            }
            printf("e%d", q-1); // @@ For numbers like "0.001", this branch is not reached because c[0]=='0' goes to the first if; but for numbers like "1.23", q is the index of '.', so q-1 is the exponent (number of digits before decimal minus 1), which is correct; however, for numbers like "10.23", q=2, exponent should be 1, but q-1=1, correct; but for numbers like "1.0" (though input guarantees no trailing zeros), this works; main issue: when there is no decimal point (te==1), the else branch is not taken, but the if branch may incorrectly handle cases like "100" where exponent should be 2, but q-1 = len-1 = 2, correct; however, the problem requires that if the base is an integer (only one digit), no decimal point should be printed, but this code prints "1e2" for "100", which is correct; but for "0.001", the first branch handles it; overall, the logic fails for cases like "0.0" (though input guarantees no trailing zeros, but "0" is possible? Input has digits before and after decimal, so "0.0" is not allowed; but "0.1" is handled by first branch with len!=3? Actually "0.1" has len=3, so goes to else if, which prints "1e-1", correct; but "0.01" has len=4, goes to first branch, k starts at 2, finds c[2]='0', c[3]='1', so k=3, prints c[3]='1', then loop from m=4 to m<=4 prints c[4] which is out-of-bounds (since len=4, c[4] is '\0'), so prints nothing, then prints "e-2", output "1.e-2" which is wrong (should be "1e-2" without decimal point). This is a major error.
        }
    }
    return 0;
}