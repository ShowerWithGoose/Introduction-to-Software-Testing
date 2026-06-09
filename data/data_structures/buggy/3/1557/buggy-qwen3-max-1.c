/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>

int main()
{
    char readnum[10001];
    char backnum[10001];//小数点之后的数字
    int i, j, k;
    int save_j;//储存0的个数
    
    gets(readnum); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
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
            
            j--; // @@ [This decrements 'j' after the loop, but 'j' is already equal to strlen(readnum) after the loop ends, so j-- makes it strlen(readnum)-1. However, this value is not used correctly afterward, leading to logic errors. Also, if the input is "0.0", this logic fails because no non-zero digit is found, yet 'save_j' remains 0, causing incorrect exponent calculation.]
            
            for(k = 0;k < strlen(readnum); k++) // @@ [This loop attempts to copy characters starting from index 'j' (which is near the end of the string) forward, but 'j' is not reset properly. It will access out-of-bounds memory when k increases beyond valid indices because 'j' starts at strlen(readnum)-1 and increments, leading to undefined behavior.]
            {
                backnum[k] = readnum[j];
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ [strlen(backnum) is used before null-terminating 'backnum', so its value is unpredictable. This leads to incorrect shifting and potential buffer overruns.]
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ [If the input is like "0.1", save_j becomes 2 (index of '1'), so exponent becomes 1, but correct exponent should be -1. The exponent calculation is off by one due to misunderstanding of decimal place counting. Also, 'backnum' is not null-terminated, so printf may print garbage.]
            
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
                for(j = strlen(backnum) ;j > 1; j--) // @@ [Again, 'backnum' is not null-terminated before calling strlen, so strlen(backnum) returns garbage. This causes incorrect insertion of the decimal point.]
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ [This prints the original input (e.g., "5.3") followed by "e0", which is correct only if there's exactly one digit before the decimal. But the problem requires normalized scientific notation: e.g., "5.3" should become "5.3e0", which is acceptable, but note that if input is "12.3", this branch is not taken (since save_j=2), so it goes to else. However, the bigger issue is that 'backnum' is not null-terminated in other branches, but here it uses 'readnum' directly, which is okay. Still, inconsistent handling.]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ ['backnum' is not null-terminated, so printf will read beyond intended characters until it finds a '\0', possibly printing garbage. Also, if the number has no fractional part (e.g., "123"), the code still processes it, but the input spec says there are digits before and after the decimal point, so maybe not an issue—but the code doesn't validate input format.]
            }
            
        }    
    
    return 0;
}