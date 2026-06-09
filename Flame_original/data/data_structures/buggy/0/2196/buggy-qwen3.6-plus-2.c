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
gets(a); // @@ [Compilation Error] 'gets' is removed in the C11 standard and causes compilation failure in modern compilers. Use 'fgets(a, sizeof(a), stdin);' instead.
while(a[i]!='\0')
    {if(a[i]=='-'&&i>0&&a[i-1]<a[i+1]&&((a[i+1]<=90&&a[i+1]>=65&&a[i-1]<=90&&a[i-1]>=65)||(a[i+1]<=122&&a[i+1]>=97&&a[i-1]<=122&&a[i-1]>=97))) // @@ [Logical Error] The condition misses the required digit range [0-9] (ASCII 48-57). Additionally, accessing a[i+1] without checking bounds may cause out-of-bounds read if '-' is at the end of the string.
        {for(n=0;n<a[i+1]-a[i-1];n++)
            {b[j+n]=a[i-1]+n+1;
            }
        j=j+n-1;
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