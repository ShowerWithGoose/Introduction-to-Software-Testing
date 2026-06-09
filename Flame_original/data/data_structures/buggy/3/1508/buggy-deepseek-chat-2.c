#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//小数点前面是不是零――不是――找小数点后0的个数n――e(-n) 
//                    ――是 ―― 找小数点前数字位数n――e(n-1) 
int main()
{
    char s[105];
    int bit,i,j,k;
    fgets(s,sizeof(s),stdin);
    int length=strlen(s);
//小数点前面是0 
    if(s[0]=='0'&&s[1]=='.')
    {
        for(i=2;i<length;i++)
        {
            if(s[i]!='0')
            {
                bit=i-1;
                // 底数是整数 
                if(atoi(s+i+1)==0) // @@ 错误：atoi(s+i+1) 会从第一个非零数字后的字符开始转换，但若后面全是数字（包括可能的小数点），atoi遇到小数点会停止，导致判断不准确。例如输入"0.00100"时，s+i+1指向"00"，atoi返回0，但实际底数应为整数1，这里错误地进入了整数分支。
                {
                    printf("%de-%d\n",s[i]-'0',bit);
                }
                //底数是小数 
                else
                {
                    printf("%d.%se-%d\n",s[i]-'0',s+i+1,bit); // @@ 错误：s+i+1 直接作为字符串输出，但该字符串可能包含换行符'\n'（因为fgets会读取换行符），导致输出格式错误。例如输入"0.001"时，s+i+1指向"01\n"，输出会多一个换行符。
                }
                break;
            }
        }
    }
//小数点前面不是0 
    else
    {
        for(i=0;i<length;i++)
        {
            if(s[i]=='.')
            {
                bit=i-1;
                for(k=j=0;s[k]!='\0';k++)
                    {
                        if(s[k]!='.')
                        {
                            s[j]=s[k];j++;
                        }
                    }
                s[k]='\0';
                printf("%d.",s[0]-'0');
                for(i=1;i<length;i++) // @@ 错误：循环变量i被重新赋值，破坏了外层循环的控制，导致外层循环提前结束或行为异常。同时，这里遍历的是修改后的s数组，但length仍然是原始字符串长度，可能访问越界或输出多余字符。
                {
                    if(s[i]!='\n')
                    printf("%c",s[i]);
                }
                printf("e%d",bit);
            }    
        }     
    }
    return 0;
}