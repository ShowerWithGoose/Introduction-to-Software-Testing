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
            
            j--; // @@ [This decrements j after the loop, but j is already at strlen(readnum), so j-- makes it point to last char. However, the logic to extract significant digits is flawed because it overwrites backnum incorrectly starting from wrong index.]
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ [This copies characters starting from the last character of readnum repeatedly, not from the first non-zero digit. It should start copying from index 'save_j', not from 'j' which is now strlen-1.]
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--)
                {
                    backnum[j] = backnum[j - 1]; // @@ [This shifts characters right to insert decimal point, but backnum was filled incorrectly above, and strlen(backnum) is undefined behavior since backnum is not null-terminated.]
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ [Exponent should be -(save_j - 1) because in "0.000...d", the first non-zero digit at position save_j (0-indexed) means exponent is -(save_j - 1). But more critically, backnum content is garbage due to prior errors.]
            
        }//原小数小于1；
        
        if(readnum[0] != '0') // @@ [This should be 'else if' to avoid executing both blocks when input starts with '0'. As written, both if blocks may run, causing double output or undefined behavior.]
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
                for(j = strlen(backnum) ;j > 1; j--) // @@ [Again, backnum is not null-terminated, so strlen(backnum) is undefined. Also, this shift assumes backnum has k characters, but strlen may read beyond.]
                {
                    backnum[j] = backnum[j - 1];
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ [Should output normalized form like "d.ddd...", not original readnum. For example, "12.34" should become "1.234e1", not "12.34e0".]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1);
            }
            
        }    
    
    return 0;
}