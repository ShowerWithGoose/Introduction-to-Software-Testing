#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[105];
int main()
{

fgets(str, 110, stdin); // @@ The buffer size in fgets (110) exceeds the declared array size (105), which can cause a buffer overflow. It should be sizeof(str) or 105.
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
printf("%c", str[numb_start + 1]);//
else
{printf("%c.", str[numb_start + 1]);//0.02与0.0236的区别 看是不是只有一个有效数字

 for (int i = numb_start + 2; i <= length - 1; i++)//i=4 i<=5 
 {
 if (str[i] == '\n') break; // @@ The loop iterates up to length-1, which includes the newline character added by fgets. This newline should not be printed as part of the significant digits.
 printf("%c", str[i]);
 }
 }
  printf("e-%d", abs(numb_start - spot_count));
}

//printf("%d %d", spot_count, numb_start);

if (str[0] != '0')
{
printf("%c.", str[numb_start - 1]);
  for (int i = numb_start; i < length ; i++)
 {
  if (str[i] == '.')continue;
  if (str[i] == '\n') break; // @@ Similar to the previous case, the newline character at the end of the string should not be processed or printed.
  printf("%c", str[i]);
  }
printf("e%d", spot_count); // @@ The exponent calculation is incorrect. For numbers >= 1, the exponent should be the number of digits before the decimal point minus 1 (which is spot_count). However, spot_count was calculated as index_of_dot - 1. If the number is "12.34", dot is at index 2, spot_count is 1. The exponent should be 1. This seems correct for this specific variable definition, but let's re-evaluate. In "12.34", numb_start becomes 1 (index 0 is '1', non-zero, so numb_start = 0+1=1). The loop prints str[0] ('1') then '.'. Then it loops from i=1. str[1] is '2'. str[2] is '.' (skip). str[3] is '3'. str[4] is '4'. Output: "1.234e1". Correct. Wait, if input is "100.5", dot at 3, spot_count=2. numb_start=1. Output "1.005e2". Correct. The issue might be elsewhere or this line is actually correct relative to the logic used. However, looking at the reference code, it uses `abs(numb_start - spot_count - 1)`. Let's trace reference. Ref: spot_count = i-1 where i is dot index. So spot_count is dot_index - 1. numb_start for non-zero start is index+1 of first digit (which is 0+1=1). Exponent = abs(1 - (dot_index-1) - 1) = abs(1 - dot_index + 1 - 1) = abs(1 - dot_index). If dot is at 2 ("12.34"), exp = abs(1-2)=1. Correct. In buggy code: printf("e%d", spot_count). spot_count = dot_index - 1. If dot is at 2, spot_count=1. Correct. If input is "5.2", dot at 1, spot_count=0. Exp 0. Correct. If input is "52.3", dot at 2, spot_count=1. Exp 1. Correct. It seems this line is logically correct for the way spot_count is defined. However, there is a subtle bug: if the number is an integer like "100" (no decimal point mentioned in problem? "digits before and after the decimal point" implies there IS a decimal point). The problem states "digits before and after the decimal point". So there is always a dot.
}
return 0;

}