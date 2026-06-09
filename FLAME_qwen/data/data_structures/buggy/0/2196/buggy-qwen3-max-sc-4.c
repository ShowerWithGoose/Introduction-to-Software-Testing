#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)// 读取指定位
#define CPL_BIT(value, bit)((value) ^= (1 << (bit)))// 取反指定位
#define SETO_BIT(value, bit) ((value) &= ~(1 << (bit))) // 把某位置0
#define SET1_BIT(value,bit) ((value)|= (1 << (bit))) //把某位置1
#include <stdio.h> // @@ [duplicate #include <stdio.h> is harmless but unnecessary; however, the real issue is missing bounds check for a[i+1] leading to out-of-bounds read when '-' is at end]
int main()
{char a[100],b[100];int i=0,j=0,n;
gets(a); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but not the direct cause of logic error here]
while(a[i]!='\0')
    {if(a[i]=='-'&&i>0&&a[i-1]<a[i+1]&&((a[i+1]<=90&&a[i+1]>=65&&a[i-1]<=90&&a[i-1]>=65)||(a[i+1]<=122&&a[i+1]>=97&&a[i-1]<=122&&a[i-1]>=97))) // @@ [missing check that i+1 is within bounds (i.e., a[i+1] != '\0'), causing undefined behavior when '-' is last character; also fails to handle digit ranges [0-9]]
        {for(n=0;n<a[i+1]-a[i-1];n++)
            {b[j+n]=a[i-1]+n+1;
            }
        j=j+n-1; // @@ [should be j += n, because after loop n = a[i+1]-a[i-1], so j becomes j + (a[i+1]-a[i-1]) - 1, which skips one character; correct would be j += n or j = j + n]
        i=i+1; // @@ [only increments i by 1, but should skip the next character (a[i+1]) since it's already expanded; should be i += 2 to avoid reprocessing the end character]
        }
    else
        {b[j]=a[i];
        j++;i++;
        }
    }
b[j]='\0';
puts(b);
}