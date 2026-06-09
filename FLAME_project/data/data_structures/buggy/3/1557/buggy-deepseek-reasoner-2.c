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
            for(j = 0;j < strlen(readnum); j++) // @@ 循环没有在找到第一个非零字符后停止，导致save_j被更新为最后一个非零字符的位置，而非第一个
            {
                if(readnum[j] != '0')
                {
                    save_j = j;
                }    
            }
            
            j--; // @@ j在循环结束后等于strlen(readnum)，减一后指向末尾字符，导致后续复制从错误位置开始
            
            for(k = 0;k < strlen(readnum); k++) // @@ 循环次数等于字符串长度，但j从末尾开始递增，复制内容错误
            {
                backnum[k] = readnum[j]; // @@ 使用错误的j索引（指向字符串末尾），导致backnum内容为字符串后半部分
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--) // @@ 这里backnum长度不确定，移动元素时下标可能越界，且插入小数点逻辑错误
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ 指数计算错误，应基于第一个非零数字前零的个数，而不是最后一个非零字符的索引
            
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
                printf("%se0", readnum);
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1);
            }
            
        }    
    
    return 0;
}