#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s); // @@ [Using gets() is unsafe and deprecated; more critically, the logic for handling non-zero-leading numbers is flawed]
    if(s[0]=='0')
    {
        for(int i=2;i<strlen(s);i++)
        {
            a--;
            if(s[i]!='0')
            {
                str[0]=s[i];
                if(i<strlen(s)-1)
                {
                    for(int j=i+1;j<strlen(s);j++)
                        str[j-i+1]=s[j];
                    str[1]='.'; // @@ [This places '.' at index 1, but subsequent printing assumes str is null-terminated and formatted correctly; also, str may not be null-terminated]
                }
                break;
            }
        }
    }
    else
    {
        for(int i=strlen(s);i>=1;i--) // @@ [Loop starts from strlen(s), which is out of bounds (valid indices are 0 to strlen(s)-1); also logic inside is incorrect for shifting digits]
        {
            if(s[i]!='.') // @@ [Accessing s[strlen(s)] is undefined behavior (it's '\0'), and the loop direction/logic doesn't correctly reconstruct the normalized form]
            {
                str[i]=s[i]; // @@ [Assigning to str[i] without adjusting index for removed decimal point leads to misplacement]
            }
            else if(s[i]=='.')
            {
                for(int j=2;j<=i;j++)
                    str[j]=s[j-1]; // @@ [This copying is logically inconsistent; it doesn't produce a normalized mantissa with one non-zero digit before decimal]
                    a++; // @@ [Incrementing 'a' once when encountering '.' doesn't compute correct exponent; exponent should be (position of first digit - 1)]
                str[0]=s[0];
                str[1]=s[i]; // @@ [Putting '.' at str[1] assumes two-digit mantissa, but doesn't handle trailing digits correctly or null-terminate]
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ [str is not null-terminated in many paths, leading to undefined output; also, exponent 'a' is computed incorrectly for non-zero-leading case]
    return 0;
}