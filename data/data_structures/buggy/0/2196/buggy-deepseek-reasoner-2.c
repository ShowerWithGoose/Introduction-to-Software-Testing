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
    {if(a[i]=='-'&&i>0&&a[i-1]<a[i+1]&&((a[i+1]<=90&&a[i+1]>=65&&a[i-1]<=90&&a[i-1]>=65)||(a[i+1]<=122&&a[i+1]>=97&&a[i-1]<=122&&a[i-1]>=97))) // @@ Missing digit range [0-9] and missing check for a[i+1] != '\0'
        {for(n=0;n<a[i+1]-a[i-1];n++) // @@ Loop bound includes the last character, causing double output. Should be n < a[i+1]-a[i-1]-1
            {b[j+n]=a[i-1]+n+1;
            }
        j=j+n-1; // @@ Incorrect update of j. Should be j = j + n; (n is count of characters written)
        i=i+1; // @@ Should increment i by 2 to skip both '-' and the following character, or handle differently.
        }
    else
        {b[j]=a[i];
        j++;i++;
        }
    }
b[j]='\0';
puts(b);
}