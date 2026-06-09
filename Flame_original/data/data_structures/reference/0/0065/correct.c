#include <stdio.h>
#include <string.h>
/*
    读入字符串
    1.记录‘ - ’所在位置
    2.计算‘ - ’左右差值，判断是否越界
    3.输出时以‘ - ’分段puts，‘ - ’用for补齐字符
*/
int judge(char *x);
int main()
{
    int len, i, k = 0, j = 0;////k记录 - 个数
    int sep[1000] = {0};////////记录 - 所在位置
    char str1[1000] = {'\0'};
    gets(str1);
    len = strlen(str1);
    //1.记录
    for(i = 0; i < len;i++)
    {
        if(str1[i]=='-')
            sep[j++] = i,k++;
    }
    //2.判断是否合法or非法,自定义函数,传入所有‘-’地址，合法返回1，非法返回0
    for(i = 0,j = 0; i < k;i++)
    {
        if(judge(&str1[sep[i]]))
            sep[j++] = sep[i];//////此时sep内存着所有合法‘-’的偏移量,j记录有效个数
    }
    //3.分段输出
    int b = j; 
    ////单独出第一段
    for(i = 0; i < sep[0];i++)
    {
        printf("%c", str1[i]);
    }
    //printf("\n/************/\n");  
    if(b==0)
        puts((&str1[sep[0]]));
    ////之后的
    for(i = 0; i < b; i++)
    {
        //如果-左右差1，跳过
        //if(str1[sep[i]+1] - str1[sep[i]-1] == 1)
            //continue;
        
        k = 0;////现在用来记差        

        while(k != str1[sep[i]+1] - str1[sep[i]-1] - 1)
        {
            printf("%c", str1[sep[i] - 1] + k + 1);
            k++;
        }
        //printf("\n/************/\n");
        
        if(i==b-1)
            puts((&str1[sep[i]])+1);
        else
            for(j = 1; j <= sep[i + 1] - sep[i] - 1;j++)
            {
                printf("%c", str1[sep[i] + j]);
            }
        //printf("\n/************/\n");
    }
    return 0;
}

int judge(char *x)
{
    if( *(x-1)>='0'&&*(x-1)<='9'  &&  *(x+1)>='0'&&*(x+1)<='9'  &&  *(x+1)-*(x-1)>=1&&*(x+1)-*(x-1)<=9)
        return 1;
    else if( *(x-1)>='A'&&*(x-1)<='Z'  &&  *(x+1)>='A'&&*(x+1)<='Z'  &&  *(x+1)-*(x-1)>=1&&*(x+1)-*(x-1)<=25)
        return 1;
    else if( *(x-1)>='a'&&*(x-1)<='z'  &&  *(x+1)>='a'&&*(x+1)<='z'  &&  *(x+1)-*(x-1)>=1&&*(x+1)-*(x-1)<=25)
        return 1;
    else
        return 0;
}


