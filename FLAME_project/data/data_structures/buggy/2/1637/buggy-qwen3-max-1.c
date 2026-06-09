#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [Reading first character into integer array 'a' as char, then converting to digit. Fails if first char is not a digit (e.g., space or sign). For input "0 =", this reads ' ' (space) if leading spaces exist, but even without, logic is flawed because it assumes first token is digit and stores in a[0] as int after subtracting '0'. However, for input "0 =", it reads '0', sets a[0]=0, which is okay, but later logic mishandles single number case.]
    a[0]=a[0]-'0'; // @@ [This assumes the first character read is a digit. If input starts with space (which is skipped only inside loop), but initial scanf reads first char including space. In test case "   0  =", first char is space, so a[0] = ' ' - '0' = negative value, causing errors. Also, even if first char is '0', a[0] becomes 0, but the parsing logic doesn't handle standalone numbers correctly because operators are expected between numbers.]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [a[k-1] is an int, but comparing to char literals like '+'. This comparison is invalid because a[k-1] holds either a number (like 0) or was assigned a char cast to int (e.g., a[k] = c where c is '+', so a[k] = 43). But when checking a[k-1] != '+', it compares int value (e.g., 0) to char '+' (ASCII 43), which may work numerically but is logically inconsistent and error-prone. More critically, in the case of single number "0=", the loop never runs (since after reading '0', next char is space then '='), so k remains 1, and a[0]=0. Then in the next loop, processing a[0]=0 (which is not an operator), so b[0]=0, j=1. Then final loop: r=b[0]=0, then for i=0 to j-1 (i<1), checks b[0]==0, which is not '+' or '-', so continues. So r remains 0. But why output -160? Because initial scanf reads first char, but if input is "   0  =", first char is space, so a[0] = ' ' (32), then a[0] = 32 - '0' = 32 - 48 = -16. Then loop processes remaining: skips spaces, reads '0', now k=1, a[k-1]=a[0]=-16, which is not an operator, so a[0] = -16*10 + ('0'-'0') = -160. Then '=' stops. So a[0] = -160, k=1. Then in for(i=0;i<k;i++) → i=0, a[0]=-160, which is not '*', '/', so b[0]=-160, j=1. Then r=b[0]=-160. Final loop: i from 0 to j-1=0, b[0]=-160 not operator, so r remains -160. Hence output -160 instead of 0. The core issue is that the program does not skip leading spaces before reading the first token, and treats the first character unconditionally as a digit.]
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
                a[k]=c; // @@ [Storing char directly into int array. This works numerically (e.g., '+' becomes 43) but leads to confusion in comparisons later, as seen above.]
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
            b[j]=a[i];
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++) // @@ [Loop condition should be i < j-1 because it accesses b[i+1]. When i = j-1, b[i+1] is out of bounds. But more importantly, in single number case, j=1, so loop runs for i=0, checks b[0] (which is the number), not an operator, so continues. So r remains b[0]. However, due to earlier parsing error, b[0] is wrong.]
    {
        if(b[i]=='+')
        {
            r+=b[i+1];
        }
        else if(b[i]=='-')
        {
            r-=b[i+1];
        }
        else
        {
            continue;
        }
    }
    printf("%d\n",r);
    return 0;
}