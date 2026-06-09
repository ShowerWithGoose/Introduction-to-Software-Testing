/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>

int main()
{
    char readnum[10001];
    char backnum[10001];//小数点之后的数字
    int i, j, k;
    int save_j;//储存0的个数
    
    gets(readnum); // @@ [Using `gets()` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Should use `fgets()` instead.]
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
            
            j--; // @@ [This decrements `j` after the loop, but `j` is already equal to `strlen(readnum)`, so `j--` makes it `strlen(readnum)-1`. However, the following loop uses `j` as a starting index and increments it, leading to out-of-bounds access.]
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ [Here, `j` starts at `strlen(readnum)-1` and is incremented each iteration, causing `readnum[j]` to access beyond the string boundary (undefined behavior).]
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--)
                {
                    backnum[j] = backnum[j - 1]; // @@ [`backnum` was never null-terminated, so `strlen(backnum)` is undefined behavior. Also, this shift logic is flawed and may overwrite memory.]
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ [`backnum` is not null-terminated, so printing it with `%s` leads to undefined behavior. Also, `save_j` may be 0 or incorrect due to logic error in the earlier loop (it stores the last non-zero index, not the first).]
            
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
                for(j = strlen(backnum) ;j > 1; j--) // @@ [`backnum` is not null-terminated, so `strlen(backnum)` is undefined behavior.]
                {
                    backnum[j] = backnum[j - 1]; // @@ [This overwrites memory beyond the intended range because `backnum` lacks a null terminator and the indexing is off.]
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ [This prints the original input with "e0", but the problem requires normalized scientific notation (e.g., "1.23e0", not "1.23e0" only if already normalized). Also, missing newline.]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ [`backnum` is not null-terminated, leading to undefined behavior in `printf`.]
            }
            
        }    
    
    return 0;
}