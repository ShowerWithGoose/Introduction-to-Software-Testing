#include<stdio.h>
#include<string.h>

char s[10000];

int main()
{
    scanf("%s", &s);
    
    int i, k = strlen(s);
    char j;
    
    for(i = 0; i < k; i++)
    {
        if(s[i] != '-')
        {
            printf("%c", s[i]);
        }
        else
        {
            if(s[i - 1] <= 'z' && s[i - 1] >='a' && s[i + 1] <= 'z' && s[i + 1] >='a' && s[i - 1] < s[i + 1])
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else if(s[i - 1] <= 'Z' && s[i - 1] >='A' && s[i + 1] <= 'Z' && s[i + 1] >='A' && s[i - 1] < s[i + 1])
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else if(s[i - 1] <= '9' && s[i - 1] >='0' && s[i + 1] <= '9' && s[i + 1] >='0' && s[i - 1] < s[i + 1])
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else // @@ The program fails to output the '-' character and the surrounding characters when the expansion conditions are not met. In the case of "B-e", the 'B' is printed in the previous iteration, but when '-' is encountered and conditions fail, nothing is printed. The '-' itself and the following character 'e' (which will be printed in its own iteration) need to be handled such that the '-' is explicitly output if no expansion occurs. Specifically, the current logic prints 'B', then hits '-', checks conditions (fails because types differ), does nothing, then loop continues to 'e' and prints 'e'. Result: "Be". Expected: "B-e". The '-' is missing.
            {
                printf("%c", s[i]);
            }
        }
    }
    return 0;
}