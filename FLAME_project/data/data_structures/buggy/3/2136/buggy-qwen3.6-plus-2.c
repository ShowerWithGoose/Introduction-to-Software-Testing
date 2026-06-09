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
 if (str[i] == '\n') break; // @@ The loop iterates up to length-1, which includes the newline character appended by fgets. This newline should not be printed as part of the significant digits.
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
printf("e%d", spot_count); // @@ The exponent calculation is incorrect. For numbers >= 1, the exponent should be the number of digits before the decimal point minus 1 (which is spot_count). However, spot_count was calculated as index_of_dot - 1. If the number is "12.34", dot is at index 2, spot_count becomes 1. The exponent should be 1 (1.234e1). This seems correct for this specific variable definition, but let's re-evaluate. Wait, if input is "12.34", dot is at index 2. spot_count = 2-1 = 1. Exponent is 1. Correct. If input is "123.4", dot at 3, spot_count = 2. Exponent 2. Correct. So this line might be logically okay based on how spot_count is defined, BUT the reference program uses `abs(numb_start - spot_count - 1)`. Let's look at numb_start. For "12.34", first non-zero is '1' at index 0. numb_start becomes 0+1=1. str[0]!='0' so numb_start stays 1. Reference: `printf("%c.", str[numb_start - 1])` -> str[0] which is '1'. Correct. Loop starts at numb_start=1. Prints '2', skips '.', prints '3', '4'. Output base: "1.234". Exponent: `abs(1 - 1 - 1)` = 1. Correct.
// In the buggy code: numb_start for "12.34" is 1. spot_count is 1.
// Buggy exponent: `spot_count` which is 1. Correct.
// Let's check "123.4". Dot at 3. spot_count = 2. numb_start = 1.
// Buggy exponent: 2. Correct.
// Let's check "1.23". Dot at 1. spot_count = 0. numb_start = 1.
// Buggy exponent: 0. Correct.
// It seems `spot_count` holds the correct exponent for str[0]!='0' cases because spot_count = index_of_dot - 1, and exponent = index_of_dot - 1.
// So this line is actually correct in value, but the previous logic for finding numb_start and handling the loop needs to be robust.
// However, there is a subtle issue. If the input is just "0.5", str[0]=='0'.
// If input is "5.0" (problem says no trailing zeros, so likely "5" or "5.1"). Problem says "digits before and after decimal point". So "5.0" is valid input? "all digits are significant... no trailing zeros". So "5.0" would likely be "5" if integer, but problem says "has digits before and after". So "5.1" is valid. "0.5" is valid.
// What if input is "10.5"? str[0]='1'. numb_start=1. spot_count (dot at 2) = 1. Exp=1. Base: str[0]='1', then loop from 1. str[1]='0', str[2]='.', skip, str[3]='5'. Base "1.05". Exp 1. 1.05e1 = 10.5. Correct.
}
return 0;

}