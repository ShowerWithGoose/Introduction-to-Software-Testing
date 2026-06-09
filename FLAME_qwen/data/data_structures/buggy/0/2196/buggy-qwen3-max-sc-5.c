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
gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; however, the immediate error is that when expansion occurs, the code skips the character after '-', leading to missing characters or incorrect output. Also, after expanding, it does not copy the ending character of the range (e.g., for a-d, 'd' is never appended).]
while(a[i]!='\0')
    {if(a[i]=='-'&&i>0&&a[i-1]<a[i+1]&&((a[i+1]<=90&&a[i+1]>=65&&a[i-1]<=90&&a[i-1]>=65)||(a[i+1]<=122&&a[i+1]>=97&&a[i-1]<=122&&a[i-1]>=97)))
        {for(n=0;n<a[i+1]-a[i-1];n++)
            {b[j+n]=a[i-1]+n+1;
            }
        j=j+n-1; // @@ [This should be 'j = j + n;' because the loop runs 'n = a[i+1]-a[i-1]' times, producing characters from a[i-1]+1 up to a[i+1]. But then we skip incrementing 'i' correctly and also fail to include the final character a[i+1] in some interpretations. However, more critically, after expansion, the next character (a[i+1]) must not be processed again, but the current logic increments i by only 1, so the next iteration will process a[i+1] as a normal char, causing duplication. Also, digits are not handled at all per problem requirements.]
        i=i+1;
        }
    else
        {b[j]=a[i];
        j++;i++;
        }
    }
b[j]='\0';
puts(b);
}