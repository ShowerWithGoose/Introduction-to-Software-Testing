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
                    save_j = j; // @@ 这里只记录了最后一个非零的位置，但应找第一个非零并break
                }    
            }
            
            j--; // @@ 错误地使j指向末尾，后续拷贝从末尾开始，逻辑混乱
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ 从错误位置拷贝，且可能越界
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ 使用未初始化的backnum（无结束符）调用strlen，结果未定义
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ backnum未以'\0'结尾，输出垃圾
            
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
                for(j = strlen(backnum) ;j > 1; j--) // @@ 同前，backnum无结束符，strlen未定义
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ 当输入为整数时（无小数点），save_j未赋值，行为未定义
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ 整数情况下save_j未初始化，指数错误；backnum无结束符
            }
            
        }    
    
    return 0;
}