#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//小数点前面是不是零――不是――找小数点后0的个数n――e(-n) 
//                    ――是 ―― 找小数点前数字位数n――e(n-1) 
int main()
{
    char s[105];
    int bit,i,j,k;
    fgets(s,sizeof(s),stdin);
    int length=strlen(s);
//小数点前面是0 
    if(s[0]=='0'&&s[1]=='.')
    {
        for(i=2;i<length;i++)
        {
            if(s[i]!='0')
            {
                bit=i-1;
                // 底数是整数 
                if(atoi(s+i+1)==0)
                {
                    printf("%de-%d\n",s[i]-'0',bit);
                }
                //底数是小数 
                else
                {
                    printf("%d.%se-%d\n",s[i]-'0',s+i+1,bit);
                }
                break;
            }
        }
    }
//小数点前面不是0 
    else
    {
        for(i=0;i<length;i++)
        {
            if(s[i]=='.')
            {
                bit=i-1;
                for(k=j=0;s[k]!='\0';k++)
                    {
                        if(s[k]!='.')
                        {
                            s[j]=s[k];j++;
                        }
                    }
                s[k]='\0'; // @@ The loop terminates when s[k] is '\0', so k points to the null terminator. Assigning '\0' to s[k] is redundant but harmless. However, the string 's' has been compacted. The original length variable is no longer valid for the new string structure, and the newline character might have been removed or shifted.
                printf("%d.",s[0]-'0');
                for(i=1;i<length;i++) // @@ The loop uses the original 'length' which includes the newline character and the decimal point that was removed. This causes the loop to iterate too far, potentially printing garbage or the newline character if not handled, or missing the fact that the string is now shorter. Specifically, it prints characters from index 1 up to the original length. Since the decimal point was removed, the digits shift. But crucially, if the original string had a newline at end, the compacted string ends earlier. The condition `s[i]!='\n'` attempts to filter newline, but since the string was compacted by removing '.', the indices are shifted. More importantly, the compacted string `s` now contains all digits. The loop should iterate until the new end of the string (which is `j`). Using `length` is incorrect because `length` is the length of the original string including '.' and '\n'. The compacted string is shorter. This leads to printing extra characters or accessing out of bounds if `length` > `j`. In the specific test case, the trailing '9' in the buggy output suggests an extra character is being printed or the logic for trimming trailing zeros/newlines is flawed relative to the shifted indices. Actually, looking closely: `s` is modified in place. `j` is the new length. The loop goes to `length`. If `length` > `j`, it accesses uninitialized or old data. If the newline was at `length-1`, and `.` was removed, the newline might still be in the buffer but `s` is null-terminated at `j`. Wait, `s[k]='\0'` sets the terminator at the position where the original `\0` was. So the string `s` still has the same allocated size but logical content is compacted. The newline character `\n` was likely at `length-1`. If `.` was before `\n`, the `\n` shifts left. The loop `for(i=1;i<length;i++)` checks `s[i]!='\n'`. If the newline is now at a different position, or if the loop goes beyond the significant digits, it might print nothing if it hits `\n` early, or print garbage. The main issue is that `length` is not updated to reflect the removal of the decimal point. The loop should go up to `j` (the new length of the digit-only string).
                {
                    if(s[i]!='\n')
                    printf("%c",s[i]);
                }
                printf("e%d",bit);
            }    
        }     
    }
    return 0;
}