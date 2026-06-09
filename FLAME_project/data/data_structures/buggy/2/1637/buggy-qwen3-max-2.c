#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [Reading first character into integer array 'a' as char, but then treating it as int; also fails if first char is space or '='. For input "0 =", this reads '0' correctly but logic breaks for edge cases like single 0.]
    a[0]=a[0]-'0'; // @@ [Assumes first character is digit; fails if expression starts with operator (not applicable here per problem, but more critically, doesn't handle case where entire expression is just "0=". Also, if input is "0 =", after reading '0', next getchar() reads space, skips, then reads '=', loop ends. But a[0] becomes 0, which is okay. However, the bigger issue is in parsing and handling of operators vs numbers in mixed array.]
    while((c=getchar())!='=')
    {
        if(c==' ')
        {
            continue;
        }
        else
        {
            if(c>='0'&&c<='9')
            {
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [Comparing integer array element (which may hold a number like 0) to char constants like '+' (ASCII 43). This comparison is invalid because a[k-1] stores numeric values (e.g., 0), not ASCII codes of operators. So condition always true for digits, leading to wrong concatenation. For "0 =", after initial '0', loop exits, so this may not trigger, but logic is fundamentally flawed.]
                {
                    a[k-1]=a[k-1]*10+c-'0';
                }
                else
                {
                    a[k]=c-'0';
                    k++;
                }
            }
            else
            {
                a[k]=c; // @@ [Storing char operator directly into int array as its ASCII value (e.g., '+' = 43), but later code compares a[i] == '*' which compares int to char literal (ASCII '*'). This works numerically but makes the array a mix of numbers and ASCII codes, leading to confusion. However, the real bug is elsewhere.]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--;
            b[j]=b[j]*a[i+1];
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1];
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ [This copies both numbers and operator ASCII codes into b[]. Later, when processing '+', '-', it checks b[i]=='+', which will match if an operator was stored. But for input "0 =", k=1 (only a[0]=0), so this loop runs once: b[0]=0, j=1. Then next loop starts.]
        }
        j++;
    }
    r=b[0]; // @@ [For "0 =", b[0]=0, so r=0 initially — seems okay. But see next loop.]
    for(i=0;i<j;i++) // @@ [j is 1 after previous loop (since one element added). So i from 0 to 0. Loop body runs once with i=0.]
    {
        if(b[i]=='+') // @@ [b[0] is 0, not '+', so skip]
        {
            r+=b[i+1];
        }
        else if(b[i]=='-') // @@ [b[0] is 0, not '-', so skip]
        {
            r-=b[i+1];
        }
        else
        {
            continue; // @@ [So continue, loop ends. r remains 0. But output is -160, so something is wrong earlier.]
        }
    }
    printf("%d\n",r); // @@ [Should print 0, but prints -160. Indicates uninitialized or corrupted memory. The core issue: the first scanf reads a char into a[0], which is int. If input is "0 =", then a[0] gets '0' (ASCII 48), then a[0] = 48 - 48 = 0. That's correct. But what if input has leading spaces? Problem says may contain spaces. However, test case is "   0  =". The first scanf("%c", &a[0]) reads the first space! Then a[0] = ' ' - '0' = 32 - 48 = -16. Then while loop reads rest until '='. So a[0] = -16, and no digits are read because after that, getchar() reads '0', which is digit, but k=1, so check a[k-1]=a[0]=-16, which is not an operator, so a[0] = -16*10 + ('0'-'0') = -160. Then next char is space (skipped), then '=' -> loop ends. So a[0] = -160. Then in for-loop, b[0] = -160, j=1. Then r = b[0] = -160. Hence output -160. The error is that the program does not skip leading spaces before reading the first token. It assumes first non-space is read by scanf, but scanf("%c") reads the very first character, including space.]
    return 0;
}