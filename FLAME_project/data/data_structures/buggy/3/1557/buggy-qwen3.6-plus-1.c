/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>

int main()
{
    char readnum[10001];
    char backnum[10001];//小数点之后的数字
    int i, j, k;
    int save_j;//储存0的个数
    
    gets(readnum);
    j = 0;
    k = 0;
    save_j = 0;
    
        if(readnum[0] == '0')
        {
            for(j = 0;j < strlen(readnum); j++)
            {
                if(readnum[j] != '0' && readnum[j] != '.') // @@ The loop should stop at the first significant digit (non-zero and non-dot). The original code continues to the end, so save_j becomes the index of the last non-zero character, not the first significant one. Also, it skips the dot check, potentially counting digits after dot incorrectly if logic was intended to find position relative to dot.
                {
                    save_j = j;
                }    
            }
            
            j--; // @@ This line is problematic. After the loop, j is strlen(readnum). Decrementing it points to the last character. The logic below attempts to copy from this position, which is incorrect for extracting the significant part starting from the first non-zero digit after the decimal point.
            
            for(k = 0;k < strlen(readnum); k++) // @@ This loop copies characters from readnum starting at index j (which is near the end) into backnum. This completely fails to extract the significant digits "9123456789012" starting from index 9. It also doesn't null-terminate backnum properly or handle the length correctly.
            {
                backnum[k] = readnum[j];
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点 // @@ strlen(backnum) is unreliable because backnum is not null-terminated. Even if it were, the content copied is wrong.
            {
                for(j = strlen(backnum) ;j > 1; j--)
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ The exponent calculation save_j-1 is based on the wrong save_j (last non-zero index instead of position relative to decimal point). For 0.00000009..., the first significant digit '9' is at index 9. The decimal point is at index 1. The exponent should be -(9-1-1) = -7? No, scientific notation for 0.0000000912... is 9.12...e-8. The position of '9' is index 9. Dot is index 1. Number of zeros after dot before 9 is 9-1-1 = 7. So exponent is -(7+1) = -8. The formula needs to be derived from the position of the first significant digit relative to the decimal point.
            
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
                for(j = strlen(backnum) ;j > 1; j--)
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ If the number is like "5.123", save_j is 1. The output should be "5.123e0". But readnum contains the dot. The reference format requires removing trailing zeros and formatting correctly. This branch prints the original number which might have trailing zeros or incorrect format if not handled. However, the main issue in the test case is the '0' branch.
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1);
            }
            
        }    
    
    return 0;
}