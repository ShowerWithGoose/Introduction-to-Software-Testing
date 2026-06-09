#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0') // @@ [Logic Error: The loop condition accesses str[cnt+2] without checking bounds or ensuring it's not the newline/null terminator. For input "0.9", str[2] is '9', so the loop doesn't run, which is correct for this case, but if input was "0.09", str[2] is '0', cnt becomes 1. Then str[3] is '9'. Loop stops. cnt=1. e=1. cnt+=2 -> cnt=3. str[3] is '9'. This logic is fragile and depends on specific formatting. More importantly, the subsequent logic assumes specific indices.]
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]);
        cnt++;
        if(str[4]=='\n') // @@ [Logic Error: Hardcoded index 4 assumes a specific length of input. For "0.9", len is 4 (0, ., 9, \n). str[4] is '\n'. This branch prints str[e+1]. e=0. str[1] is '.'. So it prints ".". But expected output is "9e-1". The code prints "9" then "." then "e-1". Result "9.e-1". This is incorrect format. If the number is 0.9, the significant digit is 9. The exponent is -1. The base should be 9 (integer) or 9. (decimal)? Problem says: "If it’s an integer, it contains only one significant digit without a decimal point." 0.9 = 9 * 10^-1. Base is 9. Exponent is -1. Output should be 9e-1. The code prints str[cnt] which is str[2]='9'. Then checks str[4]=='\n'. It is. So it prints str[e+1] which is str[1]='.'. So output is "9.". Then "e-1". Total "9.e-1". This is wrong because base should be integer 9 if there are no other digits. The condition `if(str[4]=='\n')` attempts to detect if there are more digits, but it's hardcoded and incorrect for variable lengths. Also, printing the dot unconditionally in the else block or the specific char in if block is flawed.]
        printf("%c",str[e+1]);
        else
        {
            printf(".");
            while(str[cnt]!='\n')
        {
            printf("%c",str[cnt]);
            cnt++;
        }
        }
        printf("e-%d",e+1);
    } 
    else
    {
        while(str[cnt]!='.')
        {
            cnt++;    
        } 
        e=cnt-1;
        printf("%c",str[0]);
        if(e==0&&str[2]=='\n') // @@ [Logic Error: Hardcoded index 2. For input like "5.0", str[2] is '0'. If input is "5.12", str[2] is '1'. This check tries to see if there is only one digit after decimal? No, it checks if str[2] is newline. If input is "5.\n", str[1] is '.', str[2] is '\n'. But problem says digits before and after decimal point. So "5.0" is valid. str[2] is '0'. Not '\n'. So it goes to else. Prints ".". Then loops. Correctly skips '.'. Prints '0'. Output "5.0e0". But trailing zeros should be removed? Problem says "no trailing zeros after the decimal point" in input. So "5.0" won't appear. Input "5.1". str[2]='1'. Else branch. Prints ".". Prints "1". Output "5.1e0". Correct. What about "10.5"? str[0]='1', str[1]='0', str[2]='.'. Loop finds '.' at index 2. e=1. Prints '1'. e!=0. Else branch. Prints ".". Loop i=1 to len. i=1 '0' printed. i=2 '.' skipped. i=3 '5' printed. Output "1.05e1". Correct. The issue is likely in the 0 case or edge cases. However, the hardcoded indices are major bugs waiting to fail on different inputs. For "0.9", the error is in the first block.]
        {
            for(i=1;i<len;i++)
        {
            if(str[i]=='.'||str[i]=='\0'||str[i]=='\n')
            continue;
            printf("%c",str[i]);
        }
        }
        else
        {
            printf(".");
            for(i=1;i<len;i++)
        {
            if(str[i]=='.'||str[i]=='\0'||str[i]=='\n')
            continue;
            printf("%c",str[i]);
        }
        }
        printf("e%d",e);
    }
    return 0;
}