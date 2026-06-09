#include<stdio.h>
#include<stdlib.h>//申请内存malloc(例如 ：int*a；a=（int*）malloc（number*sizeof（int））；接下来就拿a当数组来用就可以了,最后要还内存free（a）a指的是最开始的原地址)
#include<math.h> // 开方sqrt(x)  x的y次方pow(x,y)
#include<stdbool.h> //C99 bool : true or false 布尔量本质还是整数,故输出还是1或0
#include<string.h>
#include<time.h>

#define N 100000

int main(){
   char s[N];
   gets(s);
   int i;
   for (i=0;s[i]!='\0';i++)
   {
       if (s[i]=='-' && ((s[i-1]>='0' && s[i+1]<='9') || (s[i-1]>='a' && s[i+1]<='z') || (s[i-1]>='A' && s[i+1]<='Z')))
           {
                char j;
                for (j=s[i-1]+1;j<=s[i+1]-1;j++)
                {
                    printf ("%c",j);
                }
           }
        else
        {
            printf ("%c",s[i]);
        }
   }
    return 0;
}



