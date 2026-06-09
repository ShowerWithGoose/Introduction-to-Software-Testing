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
gets(a); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
while(a[i]!='\0')
    {if(a[i]=='-'&&i>0&&a[i-1]<a[i+1]&&((a[i+1]<=90&&a[i+1]>=65&&a[i-1]<=90&&a[i-1]>=65)||(a[i+1]<=122&&a[i+1]>=97&&a[i-1]<=122&&a[i-1]>=97)))
        {for(n=0;n<a[i+1]-a[i-1];n++)
            {b[j+n]=a[i-1]+n+1;
            }
        j=j+n-1; // @@ [After the loop, 'n' equals 'a[i+1]-a[i-1]', so 'j+n-1' skips one character too few; should be 'j += n' or 'j = j + n']
        i=i+1; // @@ [Skips the next character after '-', but doesn't skip the character after that, leading to duplication or misprocessing]
        }
    else
        {b[j]=a[i];
        j++;i++;
        }
    }
b[j]='\0';
puts(b);
}