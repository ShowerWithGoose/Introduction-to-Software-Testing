#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    gets(s); // @@ [Using gets() is unsafe and deprecated; however, the primary error here is logical, not compilation. But note: the reported error was "gcc: not found", which is environment-related, not code-related. However, based on problem context, we focus on logical/semantic errors causing wrong output. The real bug is below.]
    int len=strlen(s);
    
    int num1=0;
    int i=0;
    while(s[i]!='.')
    {
        i++;
        num1++;
    }
    if(num1>1)
    {
        printf("%c.",s[0]);
        for(i=1;i<len-1;i++)
        {
            if(s[i]!='.')
            printf("%c",s[i]);
        }
        printf("e%d",num1-1);
    }
    else if(num1=1&&s[0]!='0') // @@ [Assignment '=' used instead of comparison '=='. This causes num1 to be set to 1 and condition always true if s[0]!='0', leading to incorrect handling of numbers like "0.123" or misclassification of single-digit non-zero cases.]
    {
        for(i=0;i<len;i++)
        {
            printf("%c",s[i]);
        }
        printf("e0");
    }
    else
    {
        int num2=0;
        i=2;
        while(1)
        {
            if(s[i]!='0') 
            break;
            i++;
            num2++;
        }
        if(i==len-1) // @@ [This condition checks if the last character before '\0' is the first non-zero, but strlen includes all characters; s[len] is '\0', so s[len-1] is last digit. However, if input ends right after decimal (e.g., "0.0"), this may access out-of-bound or misbehave. But more critically, if the number is like "0.1", then i=2, s[2]='1', so i != len-1 (if len=3, len-1=2, so i==2 → i==len-1 is true). Then it prints "1e-1", which is correct. However, the real issue is in the loop above: if the string has no non-zero after zeros (like "0.000"), but problem states "all digits are significant" and "no trailing zeros", so such input won't occur. So this may not be the main bug. The main bug is the assignment in the else-if condition.]
        {
            printf("%ce-%d",s[i],num2+1);
        }
        else
        {
            printf("%c.",s[i]);
            while(i!=len-1)
            {
                i++;
                printf("%c",s[i]);
            }
            printf("e-%d",num2+1);
        }
    }
        
}