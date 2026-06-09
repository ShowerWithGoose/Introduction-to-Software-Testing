/*
* @Author:
* @Date: 2022-04-15 00:05:26
 * @LastEditors:
 * @LastEditTime: 2022-06-25 11:00:22
* @Description: 可计算浮点数的加减乘除和括号的计算器，计算方式为转中缀为后缀，同时不断判断栈顶符号和入栈符号的优先级，进行计算
   最后输出栈顶元素即为最终结果. 不能计算有负数的表达式
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXN 2020
const int PLUS = -1, MINUS = -2, MULTI = -3, DIVI = -4;     //加减乘除
const int LEFT = -5, RIGHT = -6;        //左右括号
const int STOP = -7;                    //等于号
int PriorityInStack[7] =  {-10, 1, 1, 3, 3, 0, 4};     //在栈中的优先级 左括号 < 加 = 减 < 乘 = 除 < 右括号 
int PriorityOutStack[8] = {-10, 1, 1, 2, 2, 4, 0};    //在栈外的优先级 第一个凑数的没有用
//用的是负数，对应下标的时候要加负号

double NumsStack[MAXN];             //存放要进行运算的数
int OpsStack[MAXN];                 //暂时保存运算符号
int numstop = -1, opstop = -1;      //两个栈顶指针
/*
   优先级规则：

   1. 都在栈外时，优先级从高到低：'(' > '*' = '/' > '+' = '-' > ')'
   2. 都在栈内时，优先级从高到低：')' > '*' = '/' > '+' = '-' > '('
   3. 栈内外的 '+' '-' 优先级全都相同
   4. 栈外的'*' '/' 优先级低于栈内的 '*' '/'，因为乘除自左往右算
   5. 栈外'=' 优先级最低，遇到'='时直接计算到栈空为止，输出栈顶元素
   
   出入栈规则：

   1. 只要栈空，运算符就进栈('='除外)
   2. 当栈顶元素和将要判断的元素恰好是一对括号时，栈顶元素组左括号退栈，跳过当前右括号
   3. 当栈顶元素和将要判断的元素不是一对括号，判断栈顶和将要入栈的元素：
      i. 栈外元素优先级高，则栈外元素入栈
      ii. 栈外元素优先级低或相等，则栈顶元素出栈，NumsStack中出来顶上两个元素进行这个栈顶符号对应的运算，运算结果再入栈

*/
char str[10000];
double a[10000];        //全部用数表示的
int flag[10000];        //0：a[i]是运算符；1：a[i]是数字
double Calculate(int i);
int main()
{
   int i, j = 0;
   gets(str);
   int len = strlen(str);
   for(i = 0; i < len; i ++)
   {
      if(str[i] == '+') a[j++] = PLUS;
      else if(str[i] == '-') a[j++] = MINUS; 
      else if(str[i] == '*') a[j++] = MULTI;
      else if(str[i] == '/') a[j++] = DIVI;
      else if(str[i] == '(') a[j++] = LEFT;
      else if(str[i] == ')') a[j++] = RIGHT;
      else if(str[i] == '=') a[j++] = STOP;
      else if(str[i] != ' '){      //将字符串转成浮点数
         double temp = (str[i] - '0') * 1.0;  //结果初始化为第一个遇到的数
         i++;
         while(str[i] >= '0' && str[i] <= '9')
         {
               temp = ( temp * 10.0 + (str[i] - '0') * 1.0);
               i++; 
         }
         flag[j] = 1; 
         a[j++] = temp;       //计算整数部分。可能没有小数，但一定有整数，所以j++在这里
         temp = 0;         //清空
         if(str[i] == '.')
         {
            i++;
            int cnt = 0;
            while(str[i] >= '0' && str[i] <= '9')
            {
               temp += (str[i] - '0') / (10.0 * pow(10,cnt));     //计算小数部分，第一次是除以10
               i++;
            }
            a[j] += temp;
         } 
         i--;  //多往下了一位，往后退回去     
      }
   }
   len = j;
   //计算：
   for(i = 0; i < len; )
   {
      if(flag[i])
         NumsStack[++numstop] = a[i++];
      else{    //a[i]是运算符
         if(opstop == -1 || PriorityOutStack[(int)(-a[i])] > PriorityInStack[-OpsStack[opstop]])    //空栈或栈外优先级高，则入栈
            OpsStack[++opstop] = (int)a[i++];
         else if(((int)a[i] == RIGHT) && (OpsStack[opstop] == LEFT) )   //如果是一对括号
         {
            opstop--;
            i++;
            continue;
         }
         else if(PriorityOutStack[(int)(-a[i])] <= PriorityInStack[-OpsStack[opstop]])  //栈外优先级低或等，出栈并计算
         {
            NumsStack[numstop - 1] = Calculate(opstop);
            numstop--;
            opstop--;
         }
         if(a[i] == STOP && opstop == -1 && numstop == 0)
         {
            // printf("%.2lf",NumsStack[0]);
            break;
         }
      }
   }
            printf("%d",(int)(NumsStack[0]));
   return 0;
}

double Calculate(int i)
{
   int op = OpsStack[i];
   if(op == PLUS)  return NumsStack[numstop-1] + NumsStack[numstop];
   if(op == MINUS) return NumsStack[numstop-1] - NumsStack[numstop];
   if(op == MULTI) return NumsStack[numstop-1] * NumsStack[numstop];
   if(op == DIVI)  return NumsStack[numstop-1] / NumsStack[numstop];
}
