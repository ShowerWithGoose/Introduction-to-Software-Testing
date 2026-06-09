#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[105];
int main()
{

fgets(str, 110, stdin); // @@ fgets reads the trailing newline character into the string, which increases length and causes the newline to be printed in the output.
//gets(str);
int spot_count = 0, numb_start = 0;
int length = strlen(str); // @@ length includes the newline character from fgets, leading to incorrect loop bounds and condition checks.

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
     
if (numb_start + 2 >= length)//原来是length-1 // @@ The condition incorrectly relies on length which includes '\n', failing to correctly identify cases with only one significant digit.
printf("%c", str[numb_start + 1]);//
else
{printf("%c.", str[numb_start + 1]);//0.02与0.0236的区别 看是不是只有一个有效数字

 for (int i = numb_start + 2; i <= length - 1; i++)//i=4 i<=5  // @@ The loop iterates up to length-1, which includes the newline character, causing it to be printed in the output.
 {
 printf("%c", str[i]);
 }
 }
  printf("e-%d", abs(numb_start - spot_count));
}

//printf("%d %d", spot_count, numb_start);

if (str[0] != '0')
{
printf("%c.", str[numb_start - 1]);
  for (int i = numb_start; i < length ; i++) // @@ Iterates including '\n', printing it in the output. Also lacks a check for single significant digit case where decimal point should be omitted.
 {
  if (str[i] == '.')continue;
  printf("%c", str[i]);
  }
printf("e%d", spot_count);
}
return 0;

}