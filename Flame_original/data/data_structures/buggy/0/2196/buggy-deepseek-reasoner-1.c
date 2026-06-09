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
    {if(a[i]=='-'&&i>0&&a[i-1]<a[i+1]&&((a[i+1]<=90&&a[i+1]>=65&&a[i-1]<=90&&a[i-1]>=65)||(a[i+1]<=122&&a[i+1]>=97&&a[i-1]<=122&&a[i-1]>=97))) // @@ Missing digit range check (48-57) and missing bound check for a[i+1] (could be out of range if hyphen at end)
        {for(n=0;n<a[i+1]-a[i-1];n++) // @@ Off-by-one: should be n < a[i+1]-a[i-1]-1 to exclude the end character
            {b[j+n]=a[i-1]+n+1;
            }
        j=j+n-1; // @@ Incorrect j update: leads to overwriting the last expanded character with a[i+1] in the else branch
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