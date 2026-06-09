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
            
            j--; // @@ 循环结束时 j 为字符串长度，j-- 后指向最后一个字符，但后续复制应从第一个非零数字开始，逻辑错误
            
            for(k = 0;k < strlen(readnum); k++) // @@ 从错误的起始索引（最后一个字符）开始复制，导致越界和内容错误
            {
                backnum[k] = readnum[j];
                j++;
            }
            
            if(strlen(backnum) > 1)// @@ backnum 未初始化，strlen 返回值不确定，可能导致错误
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ 使用未初始化的 strlen，且索引可能越界
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1);
            
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
            
            for(i = 0;i < strlen(readnum); i++) // @@ k 未重置为0，导致 backnum 索引从之前的值开始，覆盖错误数据
            {
                if(readnum[i] != '.')
                {
                    backnum[k] = readnum[i];
                    k++;
                }
            }
                        
            if(k > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ 使用未初始化的 strlen，且移动逻辑错误，索引可能越界
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
                printf("%se%d\n", backnum, save_j-1);
            }
            
        }    
    
    return 0;
}