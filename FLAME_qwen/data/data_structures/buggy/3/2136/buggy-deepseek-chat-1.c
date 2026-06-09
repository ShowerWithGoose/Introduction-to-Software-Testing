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
printf("%c", str[numb_start + 1]); // @@ [Error: When the number is like "0.0...", numb_start may be -1 or incorrect, leading to out-of-bounds access. Also, the logic for indexing is flawed; it should use numb_start directly, not numb_start+1.]
else
{printf("%c.", str[numb_start + 1]);//0.02与0.0236的区别 看是不是只有一个有效数字

 for (int i = numb_start + 2; i <= length - 1; i++)//i=4 i<=5 
 {
 printf("%c", str[i]);
 }
 }
  printf("e-%d", abs(numb_start - spot_count)); // @@ [Error: The exponent calculation is incorrect. For numbers less than 1, the exponent should be -(number of zeros after decimal point before first non-zero digit), but the formula abs(numb_start - spot_count) does not correctly compute this. Also, spot_count is set to i-1 when '.' is found, which may be wrong if there are multiple dots or if the dot is at index 0.]
}

//printf("%d %d", spot_count, numb_start);

if (str[0] != '0')
{
printf("%c.", str[numb_start - 1]); // @@ [Error: When str[0] != '0', numb_start is set to i+1 in the loop, so numb_start-1 is the index of the first non-zero digit. However, this assumes the first digit is non-zero, but the problem allows numbers like "0.123" where str[0] is '0'. This branch incorrectly handles such cases. Also, the exponent should be the number of digits before the decimal point minus 1, but spot_count is set to i-1 when '.' is found, which may not be correct if the dot is not at the expected position.]
  for (int i = numb_start; i < length ; i++)
 {
  if (str[i] == '.')continue;
  printf("%c", str[i]);
  }
printf("e%d", spot_count); // @@ [Error: The exponent should be the number of digits before the decimal point minus 1, but spot_count is set to i-1 when '.' is found. This does not correctly compute the exponent for numbers like "123.456" where the exponent should be 2, but spot_count would be 2 (since '.' is at index 3, i-1=2), which is correct only if the first digit is non-zero and there is exactly one digit before the decimal. However, for numbers like "12.34", spot_count would be 1, but the exponent should be 1, so it works by coincidence. The logic is fragile and incorrect for general cases.]
}
return 0;

}