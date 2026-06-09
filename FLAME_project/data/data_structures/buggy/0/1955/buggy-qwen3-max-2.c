/*错误 
1，记得要int
2，漏打了一个‘-’的判断、
3，switch要加减号 
4，改错要看看之前有没有改过的地方 
5，字符串改变完才进行加j操作 
*/
/*学习 
1，分类用case和逻辑值，逻辑函数 
2，stdbool.h
3，switch连写法 
*/
/*说明 
1，开始：第一个字符的地址
2，结束：最后一个字符的地址 
*/

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

char str1[1000];//可能会不够 @@
char str3[] = "abcdefghijklmnopqrstuvwxyz";
char str4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char str2[] = "0123456789";

char temp[2000];
void str_replace(char *str1_start, char *str1_replace_start, char *str1_replace_end, char *str2_replace_start, char *str2_replace_end)//被替换串的开始，被替换串的替换部分开始，被替换串的替换部分结束，替换串的替换部分开始，替换串的替换部分结束 
{
    strcpy(temp, str1_replace_end + 1);
    memset(str1_replace_start, '\0', strlen(str1_replace_start));
    strncat(str1_start, str2_replace_start, str2_replace_end + 1 - str2_replace_start);//并且把改+1去掉 @@
    strcat(str1_start, temp);
    memset(temp, '\0', strlen(temp));
}//可以改insert，只要被替换部分写一样的开始结束地址即可，并去掉上述+1//中文并不可用 

int char_type (char ch)//判断两端字符类型 
{
    if('0' <= ch && ch <= '9') return 1;
    if('a' <= ch && ch <= 'z') return 2;
    if('A' <= ch && ch <= 'Z') return 3;
    return 0;
}

int char_type_same (int a, int b)
{
    if(a == 1 && b == a) return 1;
    else if(a == 2 && b == a) return 2;
    else if(a == 3 && b == a) return 3;
    else return 0;
} 

void replace(char *str, int strlength)
{
    int i, j = strlength, k; 
    
    bool chk;//逻辑判断表达式 
     
    /*改变字符串的做法 
    
    */
     for(i = 0; i < j; i++)//j随拓展而变化，指的是目前整串长度 
    {
        chk = i > 0 && i < (j - 1) && str[i] == '-' && (str[i + 1] - str[i - 1]) > 1;
        k = char_type_same(        char_type(str[i - 1]), char_type(str[i + 1])    );//最多套两层括号，以保证美观 
         
        if(chk){
        j += str[i + 1] - str[i - 1] - 2;
            switch(k) //不熟，都要加break？ 是的 
            {
                case 1:
                    str_replace(str, str + i, str + i, str2 + 1 + str[i - 1] - '0', str2 - 1 + str[i + 1] - '0'); @@
                    break;
                case 2:
                    str_replace(str, str + i, str + i, str3 + 1 + str[i - 1] - 'a', str3 - 1 + str[i + 1] - 'a'); @@
                    break;
                case 3:
                    str_replace(str, str + i, str + i, str4 + 1 + str[i - 1] - 'A', str4 - 1 + str[i + 1] - 'A'); @@
                    break;
                default:
                    printf("switch default\n");
                    break;
            }    
        }
    }
    /*不改变字符串，改变输出方式的做法
    for(i = 0; i < j; i++)//j不随随拓展而变化，指的是目前整串长度 
    {
        chk = i > 0 && i < (j - 1) && str[i] == '-' && (str[i + 1] - str[i - 1]) > 1; 
        k = char_type_same(        char_type(str[i - 1]), char_type(str[i + 1])    );//最多套两层
        
        
        if(chk)
        {
            switch(k) //不熟，都要加break？qsqs，不加-号也打出来了 
            {
                case 1:
                case 2:
                case 3:
                    for(int m = str[i - 1] + 1; m < str[i + 1]; m ++){
                        printf("%c", m); 
                    }//这个写法可以吗？可以的
                    break; 
                default:
                    printf("%c", str[i]);
                    break;
            }//无防错 
        }
        else printf("%c", str[i]);
    }
    */
    
}

void main()
{
    gets(str1); @@
    
    replace(str1, strlen(str1));
    
    /*改变字符串的做法 
    
    */
    puts(str1);
}