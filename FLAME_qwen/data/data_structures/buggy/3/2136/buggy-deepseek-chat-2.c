#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[105];
int main()
{

fgets(str, 110, stdin);
//gets(str);
int spot_count = 0, numb_start = 0;
int length = strlen(str);

for (int i = 0; i < length ; i++) //有多少字符进行多少次
{
if (str[i] == '0')continue; //遇到0 识别下一个

if (str[i] != '0' && str[i] != '.')//出现数字
{
if (numb_start != 0)continue; // 不是零 直接下一轮
numb_start = i + 1;// 上面是0 记录第一个非0数字的真实位置

if (str[0] == '0')numb_start = i - 1;//首位不是0 用不到 首位是0 让numb等于小数点后开始计算的位数
}

if (str[i] == '.')spot_count = i - 1;//小数点前的位置
}

if (str[0] == '0')
{
     
if (numb_start + 2 >= length)//原来是length-1
printf("%c", str[numb_start + 1]); // @@ 错误：当输入为"0.0"时，numb_start可能为-1，导致数组越界；且逻辑上应输出第一个非零数字，但索引计算错误
else
{printf("%c.", str[numb_start + 1]);//0.02与0.0236的区别 看是不是只有一个有效数字

 for (int i = numb_start + 2; i <= length - 1; i++)//i=4 i<=5 
 {
 printf("%c", str[i]);
 }
 }
  printf("e-%d", abs(numb_start - spot_count)); // @@ 错误：指数计算错误，应为 first - wei - 1 的类似逻辑，这里 abs 使用不当且公式不正确
}

//printf("%d %d", spot_count, numb_start);

if (str[0] != '0')
{
printf("%c.", str[numb_start - 1]); // @@ 错误：当输入为"1.23"时，numb_start 记录的是索引+1，减1后可能指向小数点，导致输出错误
  for (int i = numb_start; i < length ; i++)
 {
  if (str[i] == '.')continue;
  printf("%c", str[i]);
  }
printf("e%d", spot_count); // @@ 错误：指数应为小数点前位数减1，这里直接输出 spot_count 不正确
}
return 0;

}