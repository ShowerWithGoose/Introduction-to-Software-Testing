/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>

int main()
{
    char readnum[10001];
    char backnum[10001];//小数点之后的数字
    int i, j, k;
    int save_j;//储存0的个数
    
    gets(readnum); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow and is removed in C11. Should use 'fgets' instead. Also, this may cause compilation error if compiler enforces secure functions.]
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
            
            j--; // @@ [This decrements 'j' after the loop, but 'j' is already equal to strlen(readnum), so j-- makes it strlen(readnum)-1, which is used incorrectly below as a starting index for copying. Logic error in handling position of first non-zero digit.]
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ [Here 'j' is fixed at strlen(readnum)-1, so this copies the same character repeatedly. Should start from the first non-zero digit, not the last character.]
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
            printf("%se-%d\n", backnum, save_j-1); // @@ [save_j is the index of the last non-zero digit, not the first. For "0.00123", save_j would be index of '3', not '1'. Exponent should be based on position of first non-zero after decimal.]
            
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
                for(j = strlen(backnum) ;j > 1; j--) // @@ [strlen(backnum) is not properly null-terminated, so strlen may read garbage. Also, shifting logic is flawed: it overwrites memory beyond intended.]
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ [This prints original input (e.g., "5.6") as "5.6e0", but expected is "5.6e0" only if normalized form allows multiple digits before decimal? Actually, per problem: base must have one non-zero digit before decimal. So "5.6" is acceptable, but if input is "12.3", this branch won't trigger, but the else branch produces wrong format. However, here the issue is that when save_j==1 (i.e., "d.x"), it prints original string, which is correct per problem, BUT note: what if input is "1."? Also, missing newline compared to other branch.]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ [backnum may not be null-terminated, leading to undefined behavior in printf. Also, the constructed backnum has incorrect placement of decimal point due to flawed shifting above.]
            }
            
        }    
    
    return 0;
}