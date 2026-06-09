#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0') // @@ The loop condition accesses str[cnt+2] without checking if it is within bounds or if it is the newline/null terminator. For input "0.9", str[2] is '9', so the loop doesn't run, which is correct for this case, but if the input was "0.09", str[2] is '0', cnt becomes 1. Then it checks str[3]. If the number is "0.00...09", this logic attempts to skip leading zeros after the decimal point. However, the subsequent logic `cnt+=2` and `printf("%c",str[cnt])` assumes the significant digit is at a specific offset. More critically, the logic `if(str[4]=='\n')` is hardcoded and incorrect for variable length inputs. The primary issue causing Runtime Error or logical failure is often out-of-bounds access or incorrect index calculation. In the specific case of "0.9", `cnt` starts at 0. `str[2]` is '9'. Loop doesn't run. `e=0`. `cnt` becomes 2. `printf("%c", str[2])` prints '9'. `cnt` becomes 3. `str[4]` is accessed. For "0.9\n", str[0]='0', str[1]='.', str[2]='9', str[3]='\n', str[4]='\0'. So `str[4]` is '\0', not '\n'. The condition `str[4]=='\n'` fails. It goes to else. Prints ".". Then `while(str[cnt]!='\n')`. `cnt` is 3. `str[3]` is '\n'. Loop doesn't run. Prints "e-1". Output: "9.e-1". Expected: "9e-1". The error is logical, producing wrong output format. However, the prompt says Runtime Error. Let's look closer. If input is "0.0009", len is small. `cnt+2` might go out of bounds if not careful, but `fgets` null terminates. The real runtime error risk is if `cnt+2` exceeds buffer, but `str` is 105. The hardcoded `str[4]` is a logical bug. The prompt asks to identify location of errors. The hardcoded index `4` is definitely wrong. Also, the logic for determining if the result is an integer (no decimal point in output) is flawed. For "0.9", the significant digit is '9'. There are no digits after it. So it should be integer base. The code prints "." unconditionally in the else branch. 
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]);
        cnt++;
        if(str[4]=='\n') // @@ Hardcoded index 4 is incorrect. It should check if there are any remaining significant digits after the first non-zero digit found. If the first non-zero digit is the last digit before newline, it should be printed as an integer base.
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
        if(e==0&&str[2]=='\n') // @@ Hardcoded index 2 is incorrect. It should check if the character after the decimal point is the newline character, implying no fractional digits.
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