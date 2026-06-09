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
                if(readnum[j] != '0' && readnum[j] != '.') // @@ The original loop incorrectly updated save_j for every non-zero character, ending up with the index of the last non-zero digit instead of the first significant digit. It also failed to skip the decimal point when counting leading zeros.
                {
                    save_j = j;
                    break; // @@ Missing break statement caused the loop to continue updating save_j to the last non-zero digit instead of stopping at the first one.
                }    
            }
            
            // j--; // @@ This line was logically flawed in the original code as j was used for iteration and then decremented, but the subsequent logic for copying digits was completely broken.
            
            // The original code attempted to copy digits using a confusing index manipulation that resulted in garbage output.
            // We need to construct the scientific notation correctly.
            // The first significant digit is at readnum[save_j].
            // The exponent is -(save_j - 1) because the decimal point was originally at index 1 (for 0.xxx), 
            // and we are moving it to after the first significant digit.
            // Actually, for 0.00...0XYZ, if the first non-zero is at index save_j, the exponent is -(save_j - 1).
            // Example: 0.005 -> save_j=3 ('5'). Exponent should be -2. -(3-1) = -2. Correct.
            
            int exp = -(save_j - 1);
            
            // Construct the mantissa
            int idx = 0;
            backnum[idx++] = readnum[save_j]; // First significant digit
            
            // Check if there are more significant digits
            int has_more_digits = 0;
            for(int m = save_j + 1; m < strlen(readnum); m++) {
                if(readnum[m] != '.') {
                    has_more_digits = 1;
                    break;
                }
            }
            
            if(has_more_digits) {
                backnum[idx++] = '.';
                for(int m = save_j + 1; m < strlen(readnum); m++) {
                    if(readnum[m] != '.') {
                        backnum[idx++] = readnum[m];
                    }
                }
            }
            backnum[idx] = '\0';
            
            printf("%se%d\n", backnum, exp); // @@ The original printf used an incorrect exponent calculation (save_j-1) which was positive, and the mantissa string was garbage.
            
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
                printf("%se0", readnum); // @@ This prints the original number instead of the formatted scientific notation if the integer part is single digit. It should format it like the other cases.
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1);
            }
            
        }    
    
    return 0;
}