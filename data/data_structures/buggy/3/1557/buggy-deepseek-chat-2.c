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
                if(readnum[j] != '0')
                {
                    save_j = j;
                }    
            }
            
            j--; // @@ 错误：此处的 j-- 逻辑错误，循环结束后 j 等于 strlen(readnum)，减1后指向最后一个字符，但后续使用 j 作为索引时可能越界或逻辑混乱
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j];
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
            printf("%se-%d\n", backnum, save_j-1); // @@ 错误：当 save_j 为0时，save_j-1 为 -1，但指数应为负数，且输出格式可能不符合要求；另外 backnum 未正确初始化，可能包含垃圾值
            
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
                printf("%se0", readnum); // @@ 错误：当小数点前只有一位且非零时，应输出科学计数法，但这里直接输出原字符串加e0，未处理小数点后的数字，例如输入"1.23"应输出"1.23e0"，但这里输出"1.23e0"看似正确，但实际未考虑整数情况；且缺少换行符
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ 错误：backnum 未以空字符结尾，导致输出可能包含垃圾字符；且当 save_j 为0时（即输入为纯小数如".5"），但题目保证有数字在小数点前，此情况不会发生，但逻辑上仍有隐患
            }
            
        }    
    
    return 0;
}