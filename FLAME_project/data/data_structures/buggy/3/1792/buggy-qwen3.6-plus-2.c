#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 

int dian(char*);

int main()
{
    char str[101] = {0};
    int flag = 0,cnt = 0;
    gets(str);
    if(str[0]=='-')
    {
        printf("%c",str[0]);
        
    }
    else
    {
        if(strlen(str)==1)
        {
            printf("%ce0",str[0]);
        }
        else if(str[0]=='0')
        {
            flag = 1;
            cnt = 1;
            for(int i=2;str[i]!='\0';i++)
            {
                if(str[i]!='0')
                {
                    flag = 0;
                    if(str[i+1]!='\0')
                        printf("%c.",str[i]); // @@ [Error: Using %d with a char argument prints the ASCII value or causes undefined behavior depending on promotion, but specifically here it treats the char '9' as integer 57 or similar if not cast correctly, but more importantly, the logic below prints digits individually. The main issue is that when printing the significant digit, it should be the character itself. However, the critical error causing "9.1.2..." is in the else block below where it prints every subsequent digit followed by nothing, but wait, looking at the output "9.1.2...", it seems dots are being printed repeatedly. Let's look closer. In the `else` branch of `if(str[i]!='0')`, i.e., when `flag` is 0 (we found the first non-zero), it prints `%d`. If `str[i+1]` is not null, it just prints the digit. It does NOT print a dot. The dot is only printed once when the first non-zero is found. So why "9.1.2."? Ah, look at line 36: `printf("%d.",str[i]-'0');`. This prints the digit and a dot. Then inside the loop, for subsequent digits, it goes to the `else` part of `if(flag)`. It prints `%d`. It does NOT print a dot. So where do the extra dots come from? Wait, the input is `0.00000009123456789012`. The first non-zero is '9' at index 9. `str[9]` is '9'. `str[10]` is '1'. `str[10]` is not '\0'. So it prints `9.`. Then `i` becomes 10. `str[10]` is '1'. `flag` is 0. `str[11]` is '2' (!='\0'). So it prints `1`. Then `i` becomes 11. Prints `2`. The expected output is `9.123...`. The buggy output is `9.1.2.3...`. This implies a dot is printed after EVERY digit. This means the code executing is likely different or I am misreading the control flow. 
                        
                        Let's re-read carefully.
                        Line 35: `if(str[i]!='0')` -> True for '9'.
                        Line 37: `flag = 0;`
                        Line 38: `if(str[i+1]!='\0')` -> True ('1' is next).
                        Line 39: `printf("%d.",str[i]-'0');` -> Prints "9."
                        Line 40: `else ...`
                        Line 43: `continue;` -> Skips the rest of the loop body for this iteration.
                        
                        Next iteration: `i` increments to 10 (char '1').
                        Line 35: `if(str[i]!='0')` -> True ('1' != '0').
                        Line 37: `flag = 0;`
                        Line 38: `if(str[i+1]!='\0')` -> True ('2' is next).
                        Line 39: `printf("%d.",str[i]-'0');` -> Prints "1."
                        Line 43: `continue;`
                        
                        Next iteration: `i` increments to 11 (char '2').
                        Line 35: `if(str[i]!='0')` -> True.
                        Line 39: `printf("%d.",str[i]-'0');` -> Prints "2."
                        
                        This explains the output `9.1.2.3...`. The logic assumes that ONLY the first non-zero digit triggers the "print digit + dot" action, and subsequent digits should just be printed as digits. However, the condition `if(str[i]!='0')` is true for ALL subsequent non-zero digits (and even zero digits if they were handled differently, but here zeros are also != '0' is false, so zeros go to the `else` block? No, '0' == '0' is true, so `if(str[i]!='0')` is false for '0'.
                        
                        Let's trace a '0' after the first non-zero. E.g., `...901...`.
                        When `i` points to '0':
                        Line 35: `if('0'!='0')` -> False.
                        Goes to Line 44: `if(flag)` -> `flag` is 0. So goes to `else`.
                        Line 48: `if(str[i+1]=='\0')` ...
                        Line 51: `printf("%d",str[i]-'0');` -> Prints "0".
                        
                        So zeros are printed correctly without dots. But non-zeros are ALWAYS printed with a dot because the check `if(str[i]!='0')` doesn't distinguish between the *first* significant digit and *subsequent* significant digits. The variable `flag` was intended to track this, but `flag` is set to 0 immediately upon finding the first non-zero, and then never used to prevent the `if(str[i]!='0')` block from executing again for subsequent non-zeros. The `flag` variable is only used in the `else` block (for zeros or when `str[i]=='0'`). It is NOT used to gate the `if(str[i]!='0')` block.
                        
                        To fix this, the `if(str[i]!='0')` block should only execute its "print with dot" logic if it is the FIRST non-zero digit encountered. We can use `flag` for this. Initially `flag=1`. When we enter the `if(str[i]!='0')` block, if `flag==1`, it's the first one. Print with dot, set `flag=0`. If `flag==0`, it's a subsequent non-zero, just print the digit.
                        
                        The current code sets `flag=0` inside the block but doesn't check it before entering the block's printing logic.
                        ]
                    else
                    {
                        printf("%d",str[i]-'0');
                        printf("e-%d",cnt);
                    }
                    continue;
                }
                if(flag)
                {
                    cnt++;
                }
                else
                {
                    if(str[i+1]=='\0')
                        printf("%de-%d",str[i]-'0',cnt);
                    else
                        printf("%d",str[i]-'0');
                }
            }
        }
        else
        {
            int i=0;
            if(dian(str))
            {
                if(str[i+1]=='\0')
                {
                    printf("%de%d",str[i]-'0',cnt);
                }
                else
                {
                    printf("%d.",str[i]-'0');
                }
                flag = 1;
                for(i=1;str[i]!='\0';i++)
                {
                    if(str[i]=='.')
                    {
                        flag = 0;
                        continue;
                    }
                    if(flag)
                    {
                        cnt++;
                    }
                    printf("%d",str[i]-'0');
                }
                printf("e%d",cnt);
            }
        }
    }
    return 0;
}

int dian(char str[])
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='.')
        {
            return 1;
        }
    }
    return 0;
}