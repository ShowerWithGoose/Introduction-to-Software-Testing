/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>

int main()
{
    char readnum[10001];
    char backnum[10001];//小数点之后的数字
    int i, j, k;
    int save_j;//储存0的个数
    
    gets(readnum); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow and may not be available in modern compilers, leading to compilation error]
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
            
            j--; // @@ [This decrements j after the loop, but j is already equal to strlen(readnum), so j-- makes it strlen(readnum)-1, which is used incorrectly below]
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ [j is fixed at strlen(readnum)-1, so this copies the same character repeatedly instead of shifting digits]
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--)
                {
                    backnum[j] = backnum[j - 1]; // @@ [This loop shifts characters but doesn't null-terminate 'backnum', leading to undefined behavior when printing]
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ [save_j is the index of the last non-zero digit, not the first; exponent should be based on position of first non-zero after decimal]
            
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
                for(j = strlen(backnum) ;j > 1; j--) // @@ ['backnum' is not null-terminated, so strlen(backnum) is undefined behavior]
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ [Should output normalized scientific notation (e.g., "1.23e0"), not original input]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ ['backnum' lacks null terminator, causing garbage output or crash]
            }
            
        }    
    
    return 0;
}