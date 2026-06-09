#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)// 读取指定位
#define CPL_BIT(value, bit)((value) ^= (1 << (bit)))// 取反指定位
#define SETO_BIT(value, bit) ((value) &= ~(1 << (bit))) // 把某位置0
#define SET1_BIT(value,bit) ((value)|= (1 << (bit))) //把某位置1
#include <stdio.h>
int main()
{char a[100],b[100];int i=0,j=0,n;
gets(a);
while(a[i]!='\0')
    {if(a[i]=='-'&&i>0&&a[i-1]<a[i+1]&&((a[i+1]<=90&&a[i+1]>=65&&a[i-1]<=90&&a[i-1]>=65)||(a[i+1]<=122&&a[i+1]>=97&&a[i-1]<=122&&a[i-1]>=97))) @@ [The condition does not include digits (0-9), so expansions like '0-8' are ignored even though they should be expanded. Also, it checks a[i] == '-' but then uses a[i-1] and a[i+1], which means the current character is '-', but the logic assumes the '-' is between two valid characters; however, the loop index advancement skips the next character incorrectly.]
        {for(n=0;n<a[i+1]-a[i-1];n++)
            {b[j+n]=a[i-1]+n+1;
            }
        j=j+n-1; @@ [After writing n characters starting from b[j], j should be advanced by n, not n-1, because the next character to write should be at b[j + n]. This causes one character to be overwritten or skipped in the next iteration.]
        i=i+1; @@ [This only skips the '-' character, but after processing a range like '0-8', we must also skip the next character (the '8'), otherwise it will be processed again in the next loop iteration, leading to duplication or incorrect output. Should be i += 2.]
        }
    else
        {b[j]=a[i];
        j++;i++;
        }
    }
b[j]='\0';
puts(b);
}