/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>

int main()
{
    char readnum[10001];
    char backnum[10001];//小数点之后的数字
    int i, j, k;
    int save_j;//储存0的个数
    
    gets(readnum); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Should use 'fgets' instead.]
    j = 0;
    k = 0;
    save_j = 0;
    
        if(readnum[0] == '0')
        {
            for(j = 0;j < strlen(readnum); j++)
            {
                if(readnum[j] != '0')
                {
                    save_j = j;
                }    
            }
            
            j--; // @@ [This decrements 'j' after the loop, but 'j' is already equal to strlen(readnum) from the loop condition, so this leads to accessing readnum[strlen(readnum)-1], which may be '.' or a digit, but logic is flawed because the loop doesn't break early when first non-zero is found. Also, 'save_j' ends up being the index of the last non-zero digit, not the first.]
            
            for(k = 0;k < strlen(readnum); k++) // @@ [This loop tries to copy from 'readnum[j]' onward, but 'j' is now strlen(readnum)-1, and then 'j++' goes out of bounds. Also, 'backnum' is filled incorrectly.]
            {
                backnum[k] = readnum[j];
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点 // @@ ['strlen(backnum)' is undefined behavior because 'backnum' is not null-terminated. This leads to unpredictable results.]
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ [Again, 'strlen(backnum)' is invalid due to missing null terminator. Also, shifting logic is incorrect for constructing scientific notation base.]
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ ['backnum' is not null-terminated, so printf with %s leads to undefined behavior. Also, exponent calculation is wrong: for input like "0.00123", first non-zero is at index 3 (after '0.'), so exponent should be -3, but save_j would be 3 (if fixed to first non-zero), then save_j-1 = 2, which is incorrect.]
            
        }//原小数小于1；
        
        if(readnum[0] != '0')
        {
            for(j = 0;j < strlen(readnum); j++)
            {
                if(readnum[j] == '.')
                {
                    save_j = j;
                    break;
                }
            }//读取e的指数
            
            for(i = 0;i < strlen(readnum); i++)
            {
                if(readnum[i] != '.')
                {
                    backnum[k] = readnum[i];
                    k++;
                }
            }
                        
            if(k > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ ['backnum' is not null-terminated, so strlen(backnum) is undefined. Also, this shifting overwrites memory and doesn't produce correct format.]
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ [This prints the original number (e.g., "5.6") followed by "e0", but expected output should normalize to one digit before decimal, e.g., "5.6e0" is acceptable only if input is like "5.6", but if input is "12.3", this branch isn't taken. However, the bigger issue is that 'backnum' logic is broken and this branch may not handle all cases correctly. Also, missing newline compared to other printf.]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ ['backnum' is not null-terminated, leading to undefined behavior in printf. Also, the constructed 'backnum' does not correctly represent the normalized mantissa (e.g., for "123.45", it becomes "1.2345" but current logic fails to build that properly).]
            }
            
        }    
    
    return 0;
}