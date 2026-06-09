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
            
            j--; // @@ [This decrements 'j' after the loop, but 'j' is already equal to strlen(readnum), so j-- makes it point to the last character. However, the logic below uses 'j' as a starting index for copying, which is incorrect because it should start from 'save_j', not the end of the string.]
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ [Here, 'j' is used as an index but it's not reset or properly calculated. This leads to reading from an incorrect position (likely beyond valid non-zero digits) and causes undefined behavior or wrong output. Also, 'j' may be out of bounds if the string ends with '\0'.]
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--)
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ [The exponent calculation is off by one. For input like "0.001", the first non-zero is at index 3 ('1'), so exponent should be -3, but save_j=3 leads to e-2. Also, 'backnum' is not null-terminated, causing undefined behavior in printf.]
            
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
                for(j = strlen(backnum) ;j > 1; j--) // @@ [strlen(backnum) is used before 'backnum' is null-terminated, leading to undefined behavior. The array 'backnum' lacks a '\0' terminator after the digit copy loop.]
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ [This prints the original input (e.g., "5.3") followed by "e0", but the expected scientific notation for "5.3" is "5.3e0" — however, per problem statement, if there's only one digit before decimal and it's non-zero, it should be printed as-is with e0. But this branch doesn't handle cases where input has more than one digit before decimal correctly. Also, missing newline may cause output formatting issues.]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ ['backnum' is not null-terminated, so printf may print garbage. Additionally, when inserting the decimal point, the shifting logic overwrites memory incorrectly and doesn't null-terminate the string.]
            }
            
        }    
    
    return 0;
}