#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

char str1[1000];//可能会不够
char str3[] = "abcdefghijklmnopqrstuvwxyz";
char str4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char str2[] = "0123456789";

char temp[2000];
void str_replace(char *str1_start, char *str1_replace_start, char *str1_replace_end, char *str2_replace_start, char *str2_replace_end)//被替换串的开始，被替换串的替换部分开始，被替换串的替换部分结束，替换串的替换部分开始，替换串的替换部分结束 
{
    strcpy(temp, str1_replace_end + 1);
    memset(str1_replace_start, '\0', strlen(str1_replace_start));
    strncat(str1_start, str2_replace_start, str2_replace_end + 1 - str2_replace_start);//并且把改+1去掉 
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
                    str_replace(str, str + i, str + i, str2 + 1 + str[i - 1] - '0', str2 - 1 + str[i + 1] - '0'); // @@ [Undefined behavior: pointer arithmetic with str2 - 1 may result in an invalid address before the array.]
                    break;
                case 2:
                    str_replace(str, str + i, str + i, str3 + 1 + str[i - 1] - 'a', str3 - 1 + str[i + 1] - 'a'); // @@ [Undefined behavior: pointer arithmetic with str3 - 1 may result in an invalid address before the array.]
                    break;
                case 3:
                    str_replace(str, str + i, str + i, str4 + 1 + str[i - 1] - 'A', str4 - 1 + str[i + 1] - 'A'); // @@ [Undefined behavior: pointer arithmetic with str4 - 1 may result in an invalid address before the array.]
                    break;
                default:
                    printf("switch default\n");
                    break;
            }    
        }
    }
}

void main() // @@ [Non-standard signature: should be int main() to match typical environments, but may not cause runtime error directly.]
{
    gets(str1); // @@ [Deprecated and dangerous function; may lead to buffer overflow if input is longer than 1000. For this test case it's safe.]
    
    replace(str1, strlen(str1));
    
    /*改变字符串的做法 
    
    */
    puts(str1);
}