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
            
            j--; // @@ [错误：此处的j--导致j的值不正确，后续用于索引readnum时出错。应直接使用save_j的值作为第一个非零数字的位置，而不是修改j。]
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ [错误：这里使用j作为索引，但j已被修改，导致从错误位置复制字符。应使用save_j作为起始索引。]
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
            printf("%se-%d\n", backnum, save_j-1); // @@ [错误：指数计算错误。对于0.000...xyz，指数应为-(第一个非零数字前0的个数+1)，但这里save_j是第一个非零数字的索引，指数应为-(save_j-1)，因为小数点后第一个0的索引是1。例如输入0.000091，save_j=4，指数应为-4，但这里输出e-3。]
            
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
                printf("%se0", readnum); // @@ [错误：当小数点后第一位是第一个数字时，应输出科学计数法，但这里直接输出原字符串，未处理小数点。例如输入1.23应输出1.23e0，但这里输出1.23e0，实际上正确输出应为1.23e0，但格式可能不对，因为原字符串包含小数点。]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1); // @@ [错误：指数计算错误。对于大于1的数，指数应为小数点前的位数减1，但这里save_j是小数点的索引，指数应为save_j-1，但backnum中已移除小数点，所以输出正确。但注意：当save_j==1时，指数应为0，但这里save_j-1=0，正确。但整体逻辑有误，例如输入12.34，save_j=2，指数应为1，输出backnum=1234，但应输出1.234e1，这里缺少小数点插入。]
            }
            
        }    
    
    return 0;
}