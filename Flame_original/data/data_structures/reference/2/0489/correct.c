#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
 char read, line[5000] = { 0 }, temp[20] = { 0 }, operate[500] = { 0 };
 int i = 0, k = 0, m = 0, num[500] = { 0 };
 while ((read = getchar()) != '=')//读取输入的式子
 {
  if (read != ' ') line[i++] = read;//如果读到的不是空格，存入line数组
  if (read == '+' || read == '-' || read == '*' || read == '/')//如果读到符号存入operate数组
  {
   operate[m++] = read;
  }
  else continue;
 }
 operate[m] = line[i] = read;//把最后的等于号存入operate数组


 for (i = 0; line[i] != '='; i++)//遍历数组，把字符串转换成数字，存入num数组
 {

  if (line[i] >= '0' && line[i] <= '9')
  {
   int j;
   memset(temp, 0, sizeof(temp));
   for (j = 0; line[i + j] >= '0' && line[i + j] <= '9'; j++)
   {
    temp[j] = line[i + j];
   }
   num[k++] = atoi(temp);
   i += j;
  }
 }
 num[k] = -1;//-1标志num数组的结尾
 m = k = 0;
 int result = 0, result_temp;//result_temp暂时存储乘除运算的结果
 int num_new[500] = { 0 };//存储算完乘除法后得到的的操作数
 char op_new[500] = { 0 };//去除乘除号，余下的运算符
 for (i = 0; operate[i] != 0; i++)
 {
  if (operate[i] == '+' || operate[i] == '-'||operate[i] == '=')//若当前符号不是*/就转存操作数和对应符号
  {
   num_new[k++] = num[i];
   op_new[m++] = operate[i];
  }
  if (operate[i] == '*' || operate[i] == '/')//当前符号是 */ ，先算乘除法
  {
   int j = 0;
   result_temp = num[i];
   for (j = 0; operate[i + j] == '*' || operate[i + j] == '/'; j++)
   {
    switch (operate[i + j])
    {
    case '*':result_temp *= num[i + j + 1]; break;
    case '/':result_temp /= num[i + j + 1]; break;
    }
   }
   i += j;
   num_new[k++] = result_temp;//把乘除法的结果存到num_new
   op_new[m++] = operate[i];//存乘除运算后面的运算符
  }

 }
 result = num_new[0];
 for (i = 0; op_new[i] != '='; i++)//把剩下的数做加减运算
 {
  switch (op_new[i])
  {
  case'+':result += num_new[i + 1]; break;
  case'-':result -= num_new[i + 1]; break;
  }
 }

 printf("%d", result);

 return 0;
}

