#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[105];
int main()
{

fgets(str, 110, stdin); // @@ The newline character captured by fgets will be processed as part of the string, causing unexpected output characters (e.g., newline printed inside the mantissa). Should remove newline or adjust loop bounds.
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

if (str[0] == '0')numb_start = i - 1;// @@ This line incorrectly overrides numb_start for cases where the integer part is zero. For example, input "0.02" sets numb_start to 1 (pointing to '.'), which later causes wrong indexing and exponent calculation. The intended logic should store the index of the first significant digit, not a decremented value.
}

if (str[i] == '.')spot_count = i - 1;//小数点前的位置
}

if (str[0] == '0')
{
     
if (numb_start + 2 >= length)//原来是length-1 // @@ The condition is incorrect. For input "0.02" (with newline, length=4), numb_start+2=3 <4, so it goes to else branch and prints a decimal point even though there are no digits after the first significant digit besides the newline. Should check if there is at least one actual digit (excluding newline) after the first non-zero digit.
printf("%c", str[numb_start + 1]);//
else
{printf("%c.", str[numb_start + 1]);// @@ This line forces a decimal point after the first digit even when no digits follow (e.g., "0.02" prints "2." then the newline). Should only add decimal point if there are more significant digits to print.

 for (int i = numb_start + 2; i <= length - 1; i++)// @@ The loop includes the newline character (since length includes it). For "0.02", it prints the newline as part of the mantissa. Also, the starting index should be numb_start+1 (the digit after the first significant digit) not +2.
 {
 printf("%c", str[i]);
 }
 }
  printf("e-%d", abs(numb_start - spot_count)); // @@ Exponent calculation is wrong. For "0.02", numb_start=1, spot_count=0 gives exponent 1, but expected exponent is -2. The formula should account for the position of the decimal point and the first significant digit correctly.
}

//printf("%d %d", spot_count, numb_start);

if (str[0] != '0')
{
printf("%c.", str[numb_start - 1]);
  for (int i = numb_start; i < length ; i++) // @@ The loop includes the newline character, which will be printed in the mantissa. Should stop before newline (e.g., i < length-1 after removing newline).
 {
  if (str[i] == '.')continue;
  printf("%c", str[i]);
  }
printf("e%d", spot_count);
}
return 0;

}