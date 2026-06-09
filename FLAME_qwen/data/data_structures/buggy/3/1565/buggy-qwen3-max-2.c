#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],str[1000];
    int a=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
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
                    str[1]='.'; // @@ [This assignment may overwrite or misalign the string because the loop above writes starting at index j-i+1, which could be >=2, but '.' is placed at index 1 without ensuring correct null termination or position]
                }
                break;
            }
        }
    }
    else
    {
        for(int i=strlen(s);i>=1;i--) // @@ [Loop starts at strlen(s), which is out of bounds (valid indices are 0 to strlen(s)-1); accessing s[strlen(s)] reads the null terminator, not a digit or '.']
        {
            if(s[i]!='.') // @@ [When i == strlen(s), s[i] is '\0', so this condition is true, leading to incorrect copying]
            {
                str[i]=s[i]; // @@ [Writing to str[i] where i can be up to strlen(s) may write beyond intended positions and leaves lower indices uninitialized]
            }
            else if(s[i]=='.') // @@ [This condition will never be true when i == strlen(s) because s[i] is '\0', not '.', so the '.' handling logic may never execute correctly]
            {
                for(int j=2;j<=i;j++)
                    str[j]=s[j-1]; // @@ [This loop copies digits starting from s[1] to s[i-1] into str[2..i], but str[0] and str[1] are set after, possibly overwriting or misaligning]
                    a++; // @@ [Indentation suggests it's inside the for-loop, but syntactically it's outside; however, logic is flawed: exponent should be based on position of first digit, not just increment once]
                str[0]=s[0];
                str[1]=s[i]; // @@ [s[i] is '.', so this sets str[1] = '.', but if the number has more than one digit before '.', the base should only have one digit before decimal; also, trailing zeros may be included]
                break;
            }
        }
    }
    printf("%se%d",str,a); // @@ [The string 'str' may not be null-terminated, leading to undefined behavior during printing; also, exponent 'a' is computed incorrectly in both branches]
    return 0;
}