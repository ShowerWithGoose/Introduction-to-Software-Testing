/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>

int main()
{
    char readnum[10001];
    char backnum[10001];//小数点之后的数字
    int i, j, k;
    int save_j;//储存0的个数
    
    gets(readnum); // @@ gets is removed in C11 standard, causing compilation error; use fgets or scanf instead.
    j = 0;
    k = 0;
    save_j = 0;
    
        if(readnum[0] == '0')
        {
            for(j = 0;j < strlen(readnum); j++)
            {
                if(readnum[j] != '0') // @@ Incorrectly treats '.' as non-zero and finds last non-zero digit; should check for '1'-'9' and break.
                {
                    save_j = j;
                }    
            }
            
            j--; // @@ Incorrect index adjustment; subsequent loop logic is flawed and causes out-of-bounds access.
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ Copies from wrong position and increments j out of bounds, leading to undefined behavior.
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点 // @@ backnum is not null-terminated, strlen reads garbage memory.
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ strlen on unterminated string causes undefined behavior.
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ backnum lacks null terminator causing printf to fail; save_j calculation is incorrect.
            
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
                    backnum[k] = readnum[i]; // @@ backnum is not null-terminated after loop, causing subsequent strlen and printf to fail.
                    k++;
                }
            }
                        
            if(k > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ strlen on unterminated string causes undefined behavior.
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum);
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ backnum lacks null terminator, causing undefined behavior in printf.
            }
            
        }    
    
    return 0;
}