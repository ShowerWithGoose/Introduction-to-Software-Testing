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
                        printf("%c.",str[i]); // @@ [Error: Using %d with a char argument prints the ASCII integer value instead of the character. Also, logic for printing subsequent digits is flawed as it enters the else block for every subsequent digit due to continue skipping the rest of the loop but not preventing re-entry into non-zero logic correctly or handling the decimal point output format. The primary issue here causing "9.1.2..." is that subsequent digits are printed with a dot or incorrectly. Actually, looking at the output `9.1.2.3...`, it seems every digit is being printed with a dot. Let's look closer. The code prints `%d.` for the first non-zero. Then for subsequent chars, if flag is 0 (which it becomes), it goes to else. If str[i+1] is not null, it prints `%d`. Wait, the output has dots between EVERY digit. This suggests the logic inside the loop is executing incorrectly or the `printf` format is wrong. In the `else` branch of `if(str[i]!='0')`, if `flag` is 0, it prints `%d`. It does NOT print a dot. However, the first print is `%d.`. The output is `9.1.2.3...`. This implies that `9.` is printed, then `1`, then `.`, then `2`? No. The output `9.1.2.3.4.5.6.7.8.9.01.2e-8` looks like every digit is followed by a dot except maybe the last part? Actually, `01.2` suggests `0`, `1`, `.`, `2`. This specific buggy output pattern usually comes from printing the character code or misinterpreting the string. But wait, `printf("%d.", str[i]-'0')` prints the integer value of the digit followed by a dot. So `9.` is correct for the first digit. Then for `1`, `flag` is 0. `str[i+1]` is `2` (not null). So it executes `printf("%d", str[i]-'0')`. This should print `1`. Why is there a dot? Ah, look at the next iteration for `2`. It prints `2`. Where do the extra dots come from? Maybe the input processing or `dian` function? No, we are in the `str[0]=='0'` block. Let's re-read the code carefully.
                    // The provided buggy output `9.1.2.3...` strongly suggests that a dot is being printed after EVERY digit.
                    // In the code: `printf("%d.",str[i]-'0');` is only called once when the first non-zero is found.
                    // Subsequent digits fall into `else { if(str[i+1]=='\0') ... else printf("%d", ...); }`. This does NOT print a dot.
                    // So where do the dots come from?
                    // Perhaps the `continue` statement is skipped? No.
                    // Let's look at the `else` block of `if(str[i]!='0')`.
                    // If `flag` is 1 (initially), and `str[i]` is '0', `cnt++`.
                    // If `str[i]` is not '0', `flag=0`. Print `%d.`. Continue.
                    // Next char `1`. `str[i]!='0'` is true. `flag` is already 0.
                    // Inside `if(str[i]!='0')`: `flag=0` (redundant). `if(str[i+1]!='\0') printf("%d.", ...)`? NO. The code says `printf("%d.",str[i]-'0');` ONLY in the block where `flag` was effectively reset?
                    // Wait, the code structure is:
                    // if(str[i]!='0') {
                    //    flag = 0;
                    //    if(str[i+1]!='\0') printf("%d.",str[i]-'0'); // <--- THIS IS THE BUG. It prints a dot for EVERY non-zero digit that is not the last one?
                    //    else ...
                    //    continue;
                    // }
                    // Yes! The condition `if(str[i]!='0')` is true for ALL significant digits. Inside this block, it prints `%d.` for all of them except the very last character of the string.
                    // So `9.` is printed. `1.` is printed. `2.` is printed... until the last digit.
                    // The last digit `2` (at index len-1) will hit the `else` part of `if(str[i+1]!='\0')`? No, `str[i+1]` is `\0`. So it prints `%d` and `e-%d`.
                    // But the output shows `01.2e-8`. The `0` and `1` before the final `2`?
                    // Input: `0.00000009123456789012`
                    // Significant digits start at `9`.
                    // `9` is not '0'. Prints `9.`. Continue.
                    // `1` is not '0'. Prints `1.`. Continue.
                    // ...
                    // `0` (in `...9012`) IS '0'.
                    // So `if(str[i]!='0')` is FALSE.
                    // Goes to `if(flag)`. Flag is 0.
                    // Goes to `else`. `str[i+1]` is `1` (not null). Prints `%d` (which is `0`).
                    // Next `1`. Not '0'. Prints `1.`.
                    // Next `2`. Not '0'. `str[i+1]` is null. Prints `%d` (`2`) and `e-%d`.
                    // So the output would be `9.1.2.3.4.5.6.7.8.9.01.2e-8`.
                    // This matches the buggy output exactly.
                    // The error is that inside the `if(str[i]!='0')` block, it unconditionally prints a dot after the digit (unless it's the very last char of the entire string, which is wrong because scientific notation should only have ONE dot after the first significant digit).
                    // Correction: Only the FIRST significant digit should be followed by a dot. Subsequent significant digits should just be printed as digits.
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