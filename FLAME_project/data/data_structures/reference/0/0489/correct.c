#include <stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define arraynum(x)  (sizeof(x)/sizeof(x[o])
#define eps (1*10^-9)
char ch(char,char);
char m[105],n[250],l[105];
int main()
{int i,i1,mid,h,i2=0;
gets(m);
for(i=0;m[i]!='\0';i++)
{
        if((m[i]=='-')&&(ch(m[i-1],m[i+1])==1))
        {
            mid=m[i+1]-m[i-1];
            for(h=0;h<=mid-1;h++)
                n[i2+h]=m[i-1]+h+1;
            i2+=h-1;
        }
        else
        {
            n[i2]=m[i];
            i2++;
        }
}
puts(n);
return 0;
}

char ch(char a,char b)
{
        if(((('a'<=a)&&(a<='z'))&&((('a'<=b)&&(b<='z'))))||((('A'<=a)&&(a<='Z'))&&((('A'<=b)&&(b<='Z'))))||((('0'<=a)&&(a<='9'))&&((('9'>=b)&&(b>='0')))))
           {
               if(a<b)
               {
                   return 1;
               }
               else
                   return 2;
           }

               else
                   return 3;
}

